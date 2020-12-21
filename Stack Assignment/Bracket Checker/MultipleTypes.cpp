#include <iostream>
using namespace std;

int Index = -1;
bool error = false;

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
        error = true;
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

bool checkPushValidity(char value, char array[])
{
    bool valid = false;
    char top = array[Index];

    if (value == '[')
    {
        if (top == '[')
        {
            valid = true;
        }
    }
    else if (value == '{')
    {
        if (top == '{' || top == '[')
        {
            valid = true;
        }
    }
    else if (value == '(')
    {
        if (top == '(' || top == '{' || top == '[')
        {
            valid = true;
        }
    }
    return valid;
}

bool checkPopValidity(char value, char array[])
{
    bool valid = false;
    char top = array[Index];
    if (value == ']' && top == '[')
    {
        valid = true;
    }
    else if (value == '}' && top == '{')
    {
        valid = true;
    }
    else if (value == ')' && top == '(')
    {
        valid = true;
    }
    return valid;
}

int main()
{
    cout << "Enter Equation: ";
    string equation;
    cin >> equation;

    int length = equation.size();
    char brackets[length];
    char final[length];

    for (int i = 0; i < length; i++)
    {
        if (equation[i] == '(' || equation[i] == ')' || equation[i] == '{' || equation[i] == '}' || equation[i] == '[' || equation[i] == ']')
        {
            push(equation[i], brackets);
        }
    }
    bool valid = true;

    for (int i = 0; i < sizeof(brackets) / sizeof(brackets[0]); i++)
    {
        char check = pop(brackets);
        if (check == '[' || check == '{' || check == '(')
        {
            if (checkPushValidity(check, brackets))
            {
                push(check, final);
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (check == ']' || check == '}' || check == ')')
        {
            if (checkPopValidity(check, brackets))
            {
                pop(brackets);
            }
            else
            {
                valid = false;
                break;
            }
        }
    }
    if (sizeof(final) / sizeof(final[0]) == 0 && valid == true)
    {
        cout << "Equation is balanced" << endl;
    }
    else
    {
        cout << "Equation is not balanced" << endl;
    }
}