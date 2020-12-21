#include <iostream>
using namespace std;

int array[6][6] = {{0, 1, 1, 1, 0, 0},
                   {1, 0, 0, 1, 0, 0},
                   {1, 0, 0, 1, 1, 0},
                   {1, 1, 1, 0, 1, 0},
                   {0, 0, 1, 1, 0, 1},
                   {0, 0, 0, 0, 1, 0}};
bool visited[6];
void DFS(int start)
{
    if (visited[start] == true)
    {
        return;
    }
    else
    {
        cout << start << " ";
        visited[start] = true;
    }
    for (int i = 0; i < 6; i++)
    {
        if (array[start][i] == 1)
        {
            DFS(i);
        }
    }
}

int main()
{
    DFS(0);
}