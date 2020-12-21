#include <iostream>
using namespace std;

int length = 10;
int array[10];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

bool isFull()
{
    int check = (rear + 1) % length;
    return (check == front);
}

void simpleEnqueue(int value)
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
        int pos = 0;
        if (rear >= front && rear != length - 1)
        {
            // Finding position
            for (int i = 0; i < rear; i++)
            {
                if (value < array[i])
                {
                    pos = i;
                    break;
                }
            }

            // Shifting values
            for (int i = length - 1; i > pos; i++)
            {
                array[i] = array[i - 1];
            }

            array[pos] = value;
            rear = (rear + 1) % length;
        }
        else
        {
            for (int i = front; i < length; i++)
            {
                if (value < array[i])
                {
                    pos = i;
                }
            }
            for (int i = 0; i <= rear; i++)
            {
                if (value < array[i])
                {
                    pos = i;
                }
            }
        }
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

void reverseDisplay()
{
    if (rear >= front)
    {
        for (int i = rear; i >= 0; i--)
        {
            cout << array[i] << ",";
        }
        cout << endl;
    }
    else
    {
        for (int i = front - 1; i >= 0; i--)
        {
            cout << array[i] << ",";
        }
        for (int i = length - 1; i > rear - 1; i--)
        {
            cout << array[i] << ",";
        }
    }
}

void Reverse()
{
    if (rear >= front)
    {
        for (int i = rear; i >= 0; i--)
        {
            cout << array[i] << ",";
        }
        cout << endl;
    }
    else
    {
        for (int i = rear; i >= 0; i--)
        {
            cout << array[i] << ",";
        }
        for (int i = front; i >= rear; i--)
        {
            cout << array[i] << ",";
        }
    }
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
            reverseDisplay();
            break;
        case 4:
            infinite_loop = false;
            break;
        }
    }
}