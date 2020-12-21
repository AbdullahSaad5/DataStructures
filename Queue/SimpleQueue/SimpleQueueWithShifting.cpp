#include <iostream>
using namespace std;

const int length = 10;
int array[length];
int front = -1, rear = -1;

bool isEmpty()
{
    return (rear == -1 && front == -1);
}

bool isFull()
{
    return (rear == (length - 1));
}
void shift()
{
    for (int i = 0; i < length - 1; i++)
    {
        array[i] = array[i + 1];
    }
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
    }
    else if (isEmpty())
    {
        rear++;
        front++;
        array[rear] = value;
    }
    else
    {
        rear++;
        array[rear] = value;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return -1;
    }
    else if (front == 0 && rear == 0)
    {
        int returningValue = array[front];
        front--;
        rear--;
        return returningValue;
    }
    else
    {
        int returningValue = array[front];
        shift();
        rear--;
        return returningValue;
    }
}

void display()
{
    if (isEmpty())
        cout << "Queue is Empty" << endl;

    for (int i = front; i <= rear; i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;
}
int main()
{
    bool infinite_loop = true;
    while (infinite_loop)
    {
        cout << "\nQueue Methods\n"
                "1. Enqueue Value\n"
                "2. Dequeue Value\n"
                "3. Display\n"
                "4. Exit\n"
                "Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "\nEnter value: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            cout << "Value Removed: " << dequeue() << endl;
            break;
        case 3:
            display();
            break;
        case 4:
            infinite_loop = false;
            break;
        }
    }
}