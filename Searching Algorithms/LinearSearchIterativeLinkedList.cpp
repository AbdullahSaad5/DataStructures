#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};
node *head = nullptr;
node *tail = nullptr;

void add(int value)
{
    node *curr = new node;
    curr->value = value;
    if(head == nullptr)
    {
        head = tail = curr;
    }
    else
    {
        tail->next = curr;
        tail = curr;
    }
}
int main()
{
    for(int i = 1; i <= 10; i++){
        add(i);
    }
    
    cout << "Enter value: ";
    int value;
    cin >> value;
    int index = -1, count = 0;
    for(node *i = head; i != nullptr; i = i->next){
        if(i->value == value){
            index = count;
            break;
        }
        count++;
    }
    
    cout << "Value found on index: " << index << endl;
}