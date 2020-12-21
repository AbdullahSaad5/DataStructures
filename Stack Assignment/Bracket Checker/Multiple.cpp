#include <iostream>
using namespace std;

class Stack
{
public:
    int Index = -1;
    char array[10];

    Stack(int size)
    {
        char array[size];
    };
    void push(char value)
    {
        int length = sizeof(array) / sizeof(array[0]);
        if (Index == length - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            Index++;
            array[Index] = value;
        }
    }

    char pop()
    {
        if (Index == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            char temp = array[Index];
            Index--;
            return temp;
        }
    }
};

int main()
{
    string equation;
    cout << "Enter equation: ";
    cin >> equation;

    int size = equation.size();
    Stack S1(size);
    bool isEmpty = true;
    for (int i = 0; i < size; i++)
    {
        if (equation[i] == '(')
        {
            if (isEmpty)
            {
                S1.push(equation[i]);
                isEmpty = false;
            }
            else
            {
                char top = S1.array[S1.Index];
            }
        }
        else if (equation[i] == '{')
        {
            if (isEmpty)
            {
                S1.push(equation[i]);
                isEmpty = false;
            }
        }
        else if (equation[i] == '[')
        {
            if (isEmpty)
            {
                S1.push(equation[i]);
                isEmpty = false;
            }
        }
    }
}