#include <iostream>
#include <vector>
using namespace std;

void knapsack(int n, int mw, vector<int> &weight, vector<int> &profit)
{
    int m = mw + 2;
    int no = n + 1;
    int b[no][m];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= mw; j++)
        {
            if (i == 0 || j == 0)
            {
                b[i][j] = 0;
            }
            else
                b[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= mw; j++)
        {
            if (weight[i - 1] <= j)
            {
                b[i][j] = max(profit[i - 1] + b[i - 1][j - weight[i - 1]], b[i - 1][j]);
            }
            else
                b[i][j] = b[i - 1][j];
        }
    }
    cout << "\n========== Table ==========\n\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= mw; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nMaximum Profit : " << b[n][mw] << endl;
}

int main()
{
    vector<int> weight;
    vector<int> profit;
    int n, capacity;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the Capacity of the bag : ";
    cin >> capacity;
    cout << "Enter the weights of the " << n << " items : " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        weight.push_back(temp);
    }
    cout << "Enter the profits of the " << n << " items : " << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        profit.push_back(temp);
    }
    knapsack(n, capacity, weight, profit);
    return 0;
}