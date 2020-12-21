#include <iostream>
using namespace std;

int search(int array[], int first, int last, int value)
{
    int index = (first + last) / 2;
    if (value == array[index])
    {
        return index;
    }
    else if (last < first || first > last)
    {
        return -1;
    }
    else if (value > array[index])
    {
        first = index;
        search(array, first, last, value);
    }
    else if (value < array[index])
    {
        last = index;
        search(array, first, last, value);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    cout << "Enter number: ";
    int number;
    cin >> number;
    cout << search(array, 0, size, number) << endl;
}
