#include <iostream>
using namespace std;

int Index = -1;
int length = -1;

void push(char value, char array[])
{
    if (Index == length - 1)
    {
        cout << "\nStack Overflow" << endl;
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
        cout << "\nStack Underflow" << endl;
        return 0;
    }
    else
    {
        char value = array[Index];
        Index--;
        return value;
    }
}

int main()
{
    cout << "Enter Word: ";
    string word;
    cin >> word;
    length = word.size();
    char array[length];

    for (int i = 0; i < length; i++)
    {
        push(word[i], array);
    }

    bool palindrome = true;

    for (int i = 0; i < length; i++)
    {
        if (pop(array) != word[i])
        {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}