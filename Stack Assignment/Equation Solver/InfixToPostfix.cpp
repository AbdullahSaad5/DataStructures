#include <iostream>
#include <string>
using namespace std;

int Index = -1;
int length = -1;
void push(char value, char array[])
{
    if (Index == length - 1)
    {
        cout << "\nStack Overflow!" << endl;
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
        cout << "\nStack Underflow!" << endl;
        return 0;
    }
    else
    {
        char value = array[Index];
        Index--;
        return value;
    }
}

void convertEquation(string equation)
{
    int size = equation.length();
    char stack[size];
    bool empty = true;
    int count = -1;
    for (int i = 0; i < size; i++)
    {
        char top = stack[count];
        if (equation[i] == '+' || equation[i] == '-')
        {
            if (empty)
            {
                push(equation[i], stack);
                count++;
                empty = false;
            }
            else if (top == '-' || top == '+')
            {
                cout << pop(stack);
                push(equation[i], stack);
            }
            else if (top == '*' || top == '/')
            {
                do
                {
                    cout << pop(stack);
                    count--;
                } while (count != -1 || top == '(');
            }
        }
        else if (equation[i] == '*' || equation[i] == '/')
        {
            if (empty)
            {
                push(equation[i], stack);
                count++;
                empty = false;
            }
            else if (top == '*' || top == '/')
            {
                cout << pop(stack);
                push(equation[i], stack);
            }
            else if (top == '+' || top == '-')
            {
                push(equation[i], stack);
                count++;
            }
        }
        else if (equation[i] == '(')
        {
            push(equation[i], stack);
            count++;
        }
        else if (equation[i] == ')')
        {
            do
            {
                cout << pop(stack);
                count--;
            } while (equation[i] != '(');
            pop(stack);
            count--;
        }
        else
        {
            cout << equation[i];
        }
    }

    while (count > -1)
    {
        cout << pop(stack);
        count--;
    }
}

int main()
{
    string equation;
    cout << "Enter Equation: ";
    cin >> equation;
    length = equation.length();

    convertEquation(equation);
}