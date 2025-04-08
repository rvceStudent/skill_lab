
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to find the largest recurring subsequence
int largest_recurring_subsequence(char *s, char *result) {
    int n = strlen(s);
    int dp[n + 1][n + 1];

    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: first row and column initialized to 0
            } else if (s[i - 1] == s[j - 1] && i != j) {
                // If characters match and indices are different
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Otherwise, take the max of the previous row and column
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // The length of the longest recurring subsequence is in dp[n][n]
    int length = dp[n][n];

    // Reconstruct the longest recurring subsequence
    int index = length - 1;
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == s[j - 1] && i != j) {
            result[index--] = s[i - 1];  // Add character to result
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    result[length] = '\0';  // Null-terminate the result string
    return length;  // Return the length of the subsequence
}

int main() {
    char s[] = "aabebcdd";
    char result[MAX_LEN];  // Array to hold the result subsequence
    int length = largest_recurring_subsequence(s, result);

    printf("Length of the largest recurring subsequence: %d\n", length);
    printf("The largest recurring subsequence: %s\n", result);

    return 0;
}

