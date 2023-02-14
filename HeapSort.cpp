#include <iostream>
using namespace std;

void heapifyMaxHeap(int h[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && h[left] > h[large])
    {
        large = left;
    }
    if (right < n && h[right] > h[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(h[large], h[i]);
        heapifyMaxHeap(h, n, large);
    }
}

void buildHeapMaxHeap(int h[], int n, int s)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMaxHeap(h, n, i);
    }
    for (int k = s - 1; k >= 0; k--)
    {
        swap(h[0], h[k]);
        heapifyMaxHeap(h, k, 0);
    }
    for (int p = 0; p < s; p++)
    {
        cout << h[p] << "\t";
    }
}

int main()
{
    int n;
    cout << "Enter Size of heap = ";
    cin >> n;
    int heap[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element to insert = ";
        cin >> heap[i];
    }
    int s = sizeof(heap) / sizeof(int);
    buildHeapMaxHeap(heap, n, s);
}