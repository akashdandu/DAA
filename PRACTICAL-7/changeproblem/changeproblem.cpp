#include <iostream>
#include <vector>
using namespace std;

int coin(int N, vector<int> coins)
{
    int m = coins.size();

    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));


    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < coins[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j]
                         + dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[m][N];
}

int main()
{
    int N, m;

    cout << "Enter target amount: ";
    cin >> N;

    cout << "Enter number of coins: ";
    cin >> m;

    vector<int> coins(m);

    cout << "Enter coin values: ";
    for (int i = 0; i < m; i++)
    {
        cin >> coins[i];
    }

    int result = coin(N, coins);

    cout << "Number of ways = " << result << endl;

    return 0;
}