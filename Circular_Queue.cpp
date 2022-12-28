#include <iostream>
using namespace std;

class Queue
{
    int front = -1, rear = -1, val;

public:
    Queue()
    {
        int front = -1, rear = -1;
    }

    void enqueue(int q[], int n)
    {
        cout << "\nEnter Value to Enqueue = ";
        cin >> val;
        if (rear == -1 && front == -1)
        {
            rear++;
            front++;
            q[rear] = val;
        }
        else if ((rear + 1) % n == front)
        {
            cout << "\nQueue is Full !!!" << endl;
        }
        else
        {
            rear = (rear + 1) % n;
            q[rear] = val;
        }
    }

    void dequeue(int q[], int n)
    {
        if (rear == -1 && front == -1)
        {
            cout << "\nQueue is already Empty !!!" << endl;
        }
        else if (rear == front)
        {
            rear = -1;
            front = -1;
        }
        else
        {
            cout << "\nDequeued element is " << q[front] << endl;
            front = (front + 1) % n;
        }
    }

    void display(int q[], int n)
    {
        int i = front;
        if (rear == -1 && front == -1)
        {
            cout << "\nQueue is Empty !!!" << endl;
        }
        else
        {
            cout << "-------------[ Queue Elements ]-------------" << endl;
            while (i != rear)
            {
                cout << q[i] << "\t";
                i = (i + 1) % n;
            }
            cout << q[rear] << endl;
        }
    }
};

int main()
{
    int ch, n;
    Queue q;
    cout << "Enter Size of Queue = ";
    cin >> n;
    int que[n];
    system("cls");
MENU:
    cout << "---------------[ Queue MENU ]---------------" << endl;
    cout << "\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n\nEnter Your Choice = ";
    cin >> ch;
    switch (ch)
    {
    case 0:
        break;
    case 1:
        q.enqueue(que, n);
        goto MENU;
    case 2:
        q.dequeue(que, n);
        goto MENU;
    case 3:
        q.display(que, n);
        goto MENU;

    default:
        cout << "Invalid Input !!!" << endl;
        goto MENU;
    }
}