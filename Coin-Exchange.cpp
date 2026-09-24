#include <iostream>
#include <vector>
using namespace std;

int countCombinations(vector<int>& coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= amount; j++){
            if (coins[i - 1] <= j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "\nDP Table:\n\n";

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= amount; j++){
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    return dp[n][amount];
}

int main()
{
    int n;

    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int amount;

    cout << "Enter target amount: ";
    cin >> amount;

    int result = countCombinations(coins, amount);

    cout << "\nTotal Number of Combinations = "
         << result << endl;

    return 0;
}