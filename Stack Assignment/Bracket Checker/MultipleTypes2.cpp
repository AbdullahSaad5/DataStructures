#include <iostream>
#include <string>
using namespace std;

int Index = -1;
void push(char value, char array[])
{
    if (Index >= 10)
    {
        cout << "\nStack is full" << endl;
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
        cout << "\nStack is empty" << endl;
        return NULL;
    }
    else
    {
        cout << "\nValue Popped: " << array[Index] << endl;
        char value = array[Index];
        Index--;
        return value;
    }
}

bool checkStack(char array[])
{
    bool valid = true;
    int length = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < length; i++)
    {
        if (array[i] == ']')
        {
            if (array[i - 1] == '(' || array[i - 1] == '{')
            {
                valid = false;
            }
            else
            {
                pop(array);
            }
        }
        else if (array[i] == '}')
        {
            if (array[i - 1] == '(' || array[i - 1] == '[')
            {
                valid = false;
            }
            else
            {
                pop(array);
            }
        }
        else if (array[i] == ')')
        {
            if (array[i - 1] == '{' || array[i - 1] == '[')
            {
                valid = false;
            }
            else
            {
                pop(array);
            }
        }
    }
    return valid;
}

int main()
{
    string equation;
    cout << "Enter Equation: ";
    cin >> equation;
    char brackets[equation.length()];

    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '[' || equation[i] == '{' || equation[i] == '(')
        {
            push(equation[i], brackets);
        }
    }

    if (checkStack(brackets))
    {
        cout << "Equation is balanced" << endl;
    }
    else
    {
        cout << "Equation is not balanced" << endl;
    }
}