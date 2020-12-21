#include <iostream>
#include <queue>
using namespace std;

int array[6][6] = {{0, 1, 1, 1, 0, 0},
                   {1, 0, 0, 1, 0, 0},
                   {1, 0, 0, 1, 1, 0},
                   {1, 1, 1, 0, 1, 0},
                   {0, 0, 1, 1, 0, 1},
                   {0, 0, 0, 0, 1, 0}};
bool visited[6];
queue<int> numbers;

void BFS(int starting)
{
    cout << starting << " ";
    numbers.push(starting);
    visited[starting] = true;

    while (!numbers.empty())
    {
        int curr = numbers.front();
        numbers.pop();

        for (int i = 0; i < 6; i++)
        {
            if (array[curr][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                cout << i << " ";
                numbers.push(i);
            }
        }
    }
}

int main()
{
    BFS(4);
}
