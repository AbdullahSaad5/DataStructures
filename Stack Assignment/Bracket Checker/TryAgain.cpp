#include <iostream>
using namespace std;

int Index = -1;
bool noUnderflow = true;

void push(char value, char array[])
{
    string temp = array;
    int length = temp.length();
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

char pop(char array[])
{
    if (Index == -1)
    {
        noUnderflow = false;
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        char temp = array[Index];
        Index--;
        return temp;
    }
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
            if (isEmpty)
            {
                push(equation[i], array);
                isEmpty = false;
            }
            else
            {
                char top = array[Index];
                if (top == '(' || top == '{' || top == '[')
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
        else if (equation[i] == '{')
        {
            if (isEmpty)
            {
                push(equation[i], array);
                isEmpty = false;
            }
            else
            {
                char top = array[Index];
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
                char top = array[Index];
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
            char top = array[Index];
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
            char top = array[Index];
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
            char top = array[Index];
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
        else
        {
            if (Index == -1)
            {
                isEmpty = true;
            }
        }
    }

    if (Index == -1 && noUnderflow)
    {
        cout << "Equation is balanced" << endl;
    }
    else
    {
        cout << "Equation is not balanced" << endl;
    }
}