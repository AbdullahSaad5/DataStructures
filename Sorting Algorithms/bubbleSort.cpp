#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}
int main()
{
    int array[] = {7, 4, 8, 2, 0, 9, 6, 1, 5, 3};
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << ", ";
    }
}