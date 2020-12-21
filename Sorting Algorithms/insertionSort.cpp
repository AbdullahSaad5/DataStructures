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
    int array[] = {2, 4, 6, 8, 3, 7, 5};
    int size = 7;
    int last = 0;
    for (int i = last + 1; i < size; i++)
    {
        if (array[last] > array[i])
        {
            int x = last;
            while (array[x] > array[x + 1] && x >= 0)
            {
                swap(array[x], array[x + 1]);
                x--;
            }
        }
        last++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}