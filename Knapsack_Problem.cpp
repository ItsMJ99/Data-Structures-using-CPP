#include <iostream>
using namespace std;

int n = 5;
float capacity;

struct item
{
    float ratio;
    float weight;
    float profit;
};

void display(struct item s[])
{
    for (int i = 0; i < n; i++)
        cout << "\nRatio : " << s[i].ratio << " Profit :" << s[i].profit << " Weight : " << s[i].weight << endl;
}

void sort(struct item s[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i].ratio >= s[j].ratio)
                swap(s[i], s[j]);
        }
    }
}

void fill(struct item s[])
{
    float bag = 0;
    float ans;
    for (int i = 0; i < n; i++)
    {
        if (bag < capacity)
        {
            if (bag + s[i].weight > capacity)
            {
                float rem = capacity - bag;
                ans += (rem / s[i].weight) * s[i].profit;
                bag += rem;
                cout << "\nCurrent profit : " << ans << " Current bag weight : " << bag << endl;
                break;
            }
            else
            {
                ans += s[i].profit;
                bag += s[i].weight;
            }
        }
        cout << "\nCurrent profit : " << ans << " Current bag weight : " << bag << endl;
    }
    cout << "\nFinal Answer\n"
         << "\nprofit : " << ans << " bag weight : " << bag << endl;
}

int main()
{
    item it[5];
    cout << "Enter Capacity : ";
    cin >> capacity;

    for (int i = 0; i < n; i++)
    {
        cin >> it[i].profit;
        cin >> it[i].weight;
        it[i].ratio = it[i].profit / it[i].weight;
        cout << it[i].ratio;
    }

// sort(it);
// display(it);
// fill(it);
MENU:
    int ch;
    cout << "==========[ MENU ]==========" << endl;
    cout << "\n0. Exit\n1. Greedy Approach\n2. 0/1 Approach" << endl;
    cout << "Enter Choice : ";
    cin >> ch;
    switch (ch)
    {
    case 0:
        exit;
    case 1:
        sort(it);
        display(it);
        fill(it);
        goto MENU;
    case 2:
        goto MENU;
    }
    return 0;
}
