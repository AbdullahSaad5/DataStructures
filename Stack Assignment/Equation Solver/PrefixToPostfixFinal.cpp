#include <iostream>
using namespace std;

int Index = -1;
int length = -1;
void push(char value, char array[])
{
    if (Index == length - 1)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        Index++;
        array[Index] = value;
    }
}

char pop(char array[])
{
    if (Index == -1)
    {
        cout << "Stack Underflow!" << endl;
        return 0;
    }
    else
    {
        int temp = array[Index];
        Index--;
        return temp;
    }
}

bool isEmpty()
{
    return (Index == -1);
}

char top(char array[])
{
    return array[Index];
}

int main()
{
    string equation;
    cout << "Enter equation: ";
    cin >> equation;

    length = equation.length();
    char array[length];

    for (int i = 0; i < length; i++)
    {
        char curr = equation[i];
        if (curr == '+' || curr == '-')
        {
            if (isEmpty() || top(array) == '(')
            {
                push(curr, array);
            }
            else
            {
                if (top(array) == '+' || top(array) == '-')
                {
                    cout << pop(array);
                    push(curr, array);
                }
                else if (top(array) == '*' || top(array) == '/')
                {
                    do
                    {
                        cout << pop(array);
                    } while (!isEmpty() || !top(array) == '(');
                    push(curr, array);
                }
            }
        }
        else if (curr == '*' || curr == '/')
        {
            if (isEmpty() || top(array) == '(')
            {
                push(curr, array);
            }
            else
            {
                if (top(array) == '+' || top(array) == '-')
                {
                    push(curr, array);
                }
                else if (top(array) == '*' || top(array) == '/')
                {
                    cout << pop(array);
                    push(curr, array);
                }
            }
        }
        else if (curr == '(')
        {
            push(curr, array);
        }
        else if (curr == ')')
        {
            while (top(array) != '(')
            {
                cout << pop(array);
            }
            pop(array);
        }
        else
        {
            cout << curr;
        }
    }

    while (!isEmpty())
    {
        cout << pop(array);
    }
}
