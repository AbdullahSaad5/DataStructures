#include <iostream>
using namespace std;

struct stu
{
    char letter;
    stu *next = nullptr;
    stu *prev = nullptr;
};
stu *head = nullptr;

void push(char value)
{
    stu *curr = new stu;
    curr->letter = value;
    if (head == nullptr)
    {
        head = curr;
    }
    else
    {
        head->next = curr;
        curr->prev = head;
        head = curr;
    }
}

char pop()
{
    if (head == nullptr)
    {
        cout << "Stack Overflow" << endl;
        return 0;
    }
    stu *del = head;
    char letter = del->letter;
    head = head->prev;
    delete del;
    cout << "Value Popped: " << letter << endl;
    return letter;
}

int main()
{
    cout << "Enter Word: ";
    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        push(word[i]);
    }

    bool palindrome = true;
    for (int i = 0; i < word.size(); i++)
    {
        if (pop() != word[i])
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