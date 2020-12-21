#include <iostream>
using namespace std;

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "Enter value:";
    int value;
    cin >> value;
    
    int index = -1;
    for(int i = 0; i < 10; i++)
    {
        if(value == array[i]){
            index = i;
        }
    }
    
    cout << "Value found on index: " << index << endl;
}