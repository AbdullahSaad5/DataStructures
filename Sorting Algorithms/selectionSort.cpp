#include <iostream>
using namespace std;

void swap(int a, int b, int *array)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int smallest(int array[], int start)
{
    int smallest = array[start];
    int index = start;
    for (int i = start; i < 10; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
            index = i;
        }
    }
    return index;
}
int main()
{
    int array[] = {7, 4, 8, 2, 0, 9, 6, 1, 5, 3};
    for (int i = 0; i < 10; i++)
    {
        int index = smallest(array, i);
        if (index != i)
            swap(index, i, array);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ", ";
    }
}