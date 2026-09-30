#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> profit, vector<int> w) {

    int n = w.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= W; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {

                int pick = 0;

                if (w[i - 1] <= j) {
                    pick = profit[i - 1] + dp[i - 1][j - w[i - 1]];
                }

                int notPick = dp[i - 1][j];

                dp[i][j] = max(pick, notPick);
            }
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> profit(n);
    vector<int> w(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Maximum value = "
         << knapsack(W, profit, w);

    return 0;
}