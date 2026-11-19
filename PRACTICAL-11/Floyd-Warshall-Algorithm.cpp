
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k;
    int d[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    cout << "Shortest distance matrix:\n";

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}