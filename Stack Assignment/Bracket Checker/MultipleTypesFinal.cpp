#include <iostream>
using namespace std;

int arrayCount = -1;
bool noUnderflow = true;

void push(char value, char array[])
{
    string temp = array;
    int length = temp.length();
    if (arrayCount == length - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        arrayCount++;
        array[arrayCount] = value;
    }
}

char pop(char array[])
{
    if (arrayCount == -1)
    {
        noUnderflow = false;
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        char temp = array[arrayCount];
        arrayCount--;
        return temp;
    }
}

bool isEmpty()
{
    return (arrayCount == -1);
}

int main()
{
    string equation;
    cout << "Enter equation: ";
    cin >> equation;

    int size = equation.length();
    char array[size];
    bool isEmpty = true;
    bool valid = true;
    for (int i = 0; i < size; i++)
    {
        if (equation[i] == '(')
        {
            push(equation[i], array);
        }
        else if (equation[i] == '{')
        {
            if (isEmpty)
            {
                push(equation[i], array);
                isEmpty = false;
            }
            else
            {
                char top = array[arrayCount];
                if (top == '{' || top == '[')
                {
                    push(equation[i], array);
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }
        else if (equation[i] == '[')
        {
            if (isEmpty)
            {
                push(equation[i], array);
                isEmpty = false;
            }
            else
            {
                char top = array[arrayCount];
                if (top == '[')
                {
                    push(equation[i], array);
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }
        else if (equation[i] == ')')
        {
            char top = array[arrayCount];
            if (top == '(')
            {
                pop(array);
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (equation[i] == '}')
        {
            char top = array[arrayCount];
            if (top == '{')
            {
                pop(array);
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (equation[i] == ']')
        {
            char top = array[arrayCount];
            if (top == '[')
            {
                pop(array);
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (arrayCount == -1)
        {
            isEmpty = true;
        }
        else
        {
            continue;
        }
    }

    if (arrayCount == -1 && noUnderflow && valid)
    {
        cout << "Equation is balanced" << endl;
    }
    else
    {
        cout << "Equation is not balanced" << endl;
    }
}