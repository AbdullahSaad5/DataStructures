#include <iostream>
using namespace std;

class stack
{
public:
    int index = -1;
    int array[10];

    void push(int value)
    {
        if (index >= 10)
        {
            cout << "\nStack Overflow" << endl;
        }
        else
        {
            index++;
            array[index] = value;
        }
    }

    int pop()
    {
        if (index == -1)
        {
            cout << "\nStack is empty" << endl;
            return -1;
        }
        else
        {
            int temp = array[index];
            index--;
            return temp;
        }
    }
};

class queue
{
public:
    stack s1, s2;

public:
    void enqueue(int value, stack s1, stack s2)
    {
        for (int i = 0; i < s1.index; i++)
        {
            int number = s1.pop();
            s2.push(number);
        }

        s1.push(value);

        for (int i = 0; i < s2.index; i++)
        {
            int number = s2.pop();
            s1.push(number);
        }
    }

public:
    int dequeue(stack s1)
    {
        return s1.pop();
    }

public:
    void viewAll(stack s1)
    {
        for (int i = 0; i < s1.index; i++)
        {
            cout << s1.array[i] << endl;
        }
    }
};

int main()
{
    queue q1;
    stack s1, s2;
    q1.enqueue(1, s1, s2);
    q1.enqueue(5, s1, s2);
    q1.enqueue(4, s1, s2);
    q1.enqueue(2, s1, s2);
    q1.enqueue(1, s1, s2);
    q1.enqueue(6, s1, s2);
    q1.enqueue(7, s1, s2);
    q1.enqueue(4, s1, s2);
    q1.dequeue(s1);
}