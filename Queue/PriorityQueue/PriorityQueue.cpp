#include <iostream>
using namespace std;

class Queue
{
private:
    int Index = -1;

public:
    void push(int value, int array[])
    {
        int size = sizeof(array) / sizeof(array[0]);

        if (Index == -1)
        {
            Index++;
            array[Index] = value;
        }
        else if (Index == size - 1)
        {
            cout << "Queue is overloaded!" << endl;
        }
        else
        {
            Index++;
            array[Index] = value;
        }
    }

    int pop(int array[])
    {
        if (Index == -1)
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        else
        {
            int temp = array[Index];
            Index--;
            return temp;
        }
    }
};

int main()
{
    Queue Q1;
    int array1[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Number: ";
        int value;
        cin >> value;

        for (int j = 0; j < 10; j++)
        {
            if (value < array1[j])
                ;
        }
    }
}