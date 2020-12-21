#include <iostream>
using namespace std;
struct node
{
    int value;
    node *right = nullptr;
    node *left = nullptr;
};
int count = 0;
double sum = 0;

node *root = nullptr;

void preOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        cout << root->value << ", ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->value << ", ";
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << ", ";
    }
}

void add(node *curr)
{
    if (root == nullptr)
    {
        root = curr;
    }
    else
    {
        node *p = root, *q = nullptr;
        while (p != nullptr)
        {
            q = p;
            if (curr->value > p->value)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }

        if (curr->value > q->value)
        {
            q->right = curr;
        }
        else
        {
            q->left = curr;
        }
    }
}

void deleteNode(int value)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        node *p = root, *q = nullptr;

        while (p != nullptr)
        {
            if (p->value == value)
            {
                break;
            }
            else
            {
                q = p;

                if (value > p->value)
                {
                    p = p->right;
                }
                else
                {
                    p = p->left;
                }
            }
        }

        if (p == nullptr)
        {
            cout << "Value not found" << endl;
        }

        else if (p->left == nullptr && p->right == nullptr)
        {
            if (q->left == p)
            {
                delete p;
                q->left = nullptr;
            }
            else
            {
                delete p;
                q->right = nullptr;
            }
        }

        else if (p->left != nullptr && p->right != nullptr)
        {
            node *del = p;
            q = p;
            node *curr = p->right;
            if (curr->left == nullptr)
            {
                del->value = curr->value;
                q->right = curr->right;
                delete curr;
            }
            else
            {
                while (curr->left != nullptr)
                {
                    q = curr;
                    curr = curr->left;
                }
                del->value = curr->value;
                q->left = curr->right;
                delete curr;
            }
        }

        else if (q->left == p)
        {
            if (p->right == nullptr)
            {
                q->left = p->left;
                delete p;
            }
            else if (p->left == nullptr)
            {
                q->left = p->right;
                delete p;
            }
        }

        else if (q->right == p)
        {
            if (p->left == nullptr)
            {
                q->right = p->right;
                delete p;
            }
            else if (p->right == nullptr)
            {
                q->right = p->left;
                delete p;
            }
        }
    }
}
void getAverage(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        sum += root->value;
        count++;
        getAverage(root->left);
        getAverage(root->right);
    }
}

double calculateAverage()
{
    getAverage(root);
    double average = sum / count;
    return average;
}

int min()
{
    node *p = root;
    do
    {
        p = p->left;
    } while (p->left != nullptr);
    return p->value;
}

int max()
{
    node *p = root;
    do
    {
        p = p->right;
    } while (p->right != nullptr);
    return p->value;
}

int main()
{
    int array[] = {12, 5, 15, 3, 7, 9, 1, 13, 17, 14, 20, 18, 16, 8, 11};
    for (int i = 0; i < 15; i++)
    {
        node *curr = new node;
        curr->value = array[i];
        add(curr);
    }

    cout << "\nPre Order: ";
    preOrder(root);
    cout << "\nIn Order: ";
    inOrder(root);
    cout << "\nPost Order: ";
    postOrder(root);

    cout << "\nArray is: ";
    for (int i = 0; i < 15; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;

    cout << "Average is " << calculateAverage() << endl;

    deleteNode(9);

    cout << "\nPre Order: ";
    preOrder(root);
    cout << endl;

    cout << "Min: " << min() << "\t"
         << "Max: " << max() << endl;
}
