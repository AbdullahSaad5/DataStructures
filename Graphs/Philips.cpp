#include <iostream>
using namespace std;

int array[6][6] = {{0, 2, 4, 100, 100, 100},
                   {2, 0, 1, 7, 100, 100},
                   {4, 1, 0, 100, 3, 100},
                   {100, 7, 100, 0, 2, 1},
                   {100, 100, 3, 2, 0, 5},
                   {100, 100, 100, 1, 5, 0}};
bool visited[6];
int answers[6];

bool checkBool(bool array[])
{
    for (int i = 0; i < 6; i++)
    {
        if (array[i] == false)
        {
            return false;
        }
    }
    return true;
}
void dijkstra(int start)
{
    for (int i = 0; i < 6; i++)
    {
        answers[i] = array[start][i];
    }

    visited[start] = true;
    while (!checkBool(visited))
    {
        int smallest = 100, index = -1;

        for (int i = 0; i < 6; i++)
        {
            if (smallest > answers[i] && visited[i] == false)
            {
                index = i;
            }
        }
        visited[index] = true;
        for (int i = 0; i < 6; i++)
        {
            int dist = array[index][i];
            if (dist < answers[i])
            {
                answers[i] = dist;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            cout << answers[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    dijkstra(2);
}