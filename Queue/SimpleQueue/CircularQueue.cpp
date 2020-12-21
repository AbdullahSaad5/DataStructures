#include <iostream>
using namespace std;

const int length = 10;
int array[length];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

bool isFull()
{
    int check = (rear + 1) % length;
    return (check == front);
}

void enqueue(int value)
{
    if (isFull())
    {
        cout << "Overflow" << endl;
    }
    else if (isEmpty())
    {
        front++;
        rear++;
        array[rear] = value;
    }
    else
    {
        rear = (rear + 1) % length;
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
    else if (rear == front)
    {
        int returningValue = array[front];
        rear = -1;
        front = -1;
        return returningValue;
    }
    else
    {
        int returningValue = array[front];
        front = (front + 1) % length;
        return returningValue;
    }
}

void display()
{
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