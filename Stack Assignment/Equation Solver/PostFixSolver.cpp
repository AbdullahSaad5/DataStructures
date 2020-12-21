#include <iostream>
using namespace std;

int Index = -1;
int length = -1;
void push(int value, int array[])
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

int pop(int array[])
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

int top(int array[])
{
    return array[Index];
}

int main()
{
    string equation;
    cout << "Enter equation: ";
    cin >> equation;

    length = equation.length();
    int array[length];
    for (size_t i = 0; i < length; i++)
    {
        char curr = equation[i];
        if (isdigit(curr))
        {
            string num = "";
            num += curr;
            push(stoi(num), array);
        }
        else if (curr == '+')
        {
            int x = pop(array);
            int y = pop(array);
            push(x + y, array);
        }
        else if (curr == '-')
        {
            int x = pop(array);
            int y = pop(array);
            push(x - y, array);
        }
        else if (curr == '*')
        {
            int x = pop(array);
            int y = pop(array);
            push(x * y, array);
        }
        else if (curr == '/')
        {
            int x = pop(array);
            int y = pop(array);
            push(y / x, array);
        }
        else if (curr == ' ')
        {
            continue;
        }
    }

    cout << "Answer: " << pop(array) << endl;
}