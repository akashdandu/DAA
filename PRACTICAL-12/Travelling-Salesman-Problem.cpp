
#include <iostream>
using namespace std;

#define MAX 10

int n, cost[MAX][MAX];
int visited[MAX];
int minCost = 999999;

void tsp(int city, int count, int totalCost)
{
    int i;

    if (count == n && cost[city][0] > 0)
    {
        int finalCost = totalCost + cost[city][0];

        if (finalCost < minCost)
            minCost = finalCost;

        return;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] > 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    cout << "Enter number of cities (maximum 10): ";
    cin >> n;

    if (n < 2 || n > MAX)
    {
        cout << "Invalid number of cities." << endl;
        return 0;
    }

    cout << "Enter the cost matrix:\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    tsp(0, 1, 0);

    if (minCost == 999999)
        cout << "No complete tour exists." << endl;
    else
        cout << "Minimum travelling cost = "
             << minCost << endl;

    return 0;
}