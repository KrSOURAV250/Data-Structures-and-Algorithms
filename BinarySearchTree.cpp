#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int a)
    {
        data = a;
    }
};
void displayPreOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}
void displayPostOrder(node *root)
{
    if (root != NULL)
    {
        displayPostOrder(root->left);
        displayPostOrder(root->right);
        cout << root->data << " ";
    }
}
void display(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void displayInOrder(node *root)
{

    if (root != NULL)
    {
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }
}
// int isBST(node *root)
// {
//     static node *prevNode = NULL;
//     if (root != NULL)
//     {
//         if (!isBST(root->left))
//         {
//             return 0;
//         }
//         if (prevNode != NULL && root->data <= prevNode->data)
//         {
//             return 0;
//         }
//         prevNode = root;
//         return isBST(root->right);
//     }
//     else
//     {
//         return 1;
//     }
// }

bool isBST(node *root, int minn = INT_MIN, int maxx = INT_MAX)
{
    if (root != NULL)
    {
        if (root->data <= minn || root->data >= maxx)
        {
            return false;
        }
        return isBST(root->left, minn, root->data) & isBST(root->right, root->data, maxx);
    }
    else
        return 1;
}
// node *searching(node *root, int key = 0)
// {
//     if (root != NULL)
//     {
//         if (root->data == key)
//         {
//             return root;
//         }
//         else if (key < root->data)
//         {
//             searching(root->left, key);
//         }
//         else if (key > root->data)
//         {
//             searching(root->right, key);
//         }
//     }
//     else

//         return NULL;
// }

// for deletion
node *iterativeSearch(node *root, int key)
{

    while (root != NULL)
    {

        if (key == root->data)
        {

            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
            root = root->right;
    }

    return NULL;
}

void insert(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Can't Insert\n";
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    node *ptr = new node(key);
    if (key < prev->data)
    {
        prev->left = ptr;
    }
    else
        prev->right = ptr;
}
// node *inOrderPre(node *root)
// {
//     root = root->left;
//     while (root->right != NULL)
//     {
//         root = root->right;
//     }
//     return root;
// }

node *deleteRoot(node *root)
{
    if (!root || root->data == 0)
        return NULL;
    if (!root->right)
        return root->left;
    node *x = root->right;
    while (x->left)
        x = x->left;
    x->left = root->left;
    return root->right;
}
void deleteNode(node *root, int key)
{
    if (!root || root->data == key)
        deleteRoot(root);
    node *curr = root;
    while (1)
    {
        int x = curr->data;
        if (key < x)
        {
            if (!curr->left || curr->left->data == key)
            {
                node *ptr = curr->left;
                curr->left = deleteRoot(curr->left);
                delete ptr;
                break;
            }
            curr = curr->left;
        }
        else
        {
            if (!curr->right || curr->right->data == key)
            {
                node *ptr = curr->right;
                curr->right = deleteRoot(curr->right);
                delete ptr;
                break;
            }
            curr = curr->right;
        }
    }
}

int main(int argc, char const *argv[])
{
    node n1(9);
    node *head1 = &n1;
    insert(head1, 4);
    insert(head1, 6);
    insert(head1, 3);
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 5);
    insert(head1, 7);
    insert(head1, 8);
    insert(head1, 9);
    insert(head1, 10);
    insert(head1, 11);
    insert(head1, 12);
    insert(head1, 13);

    cout << "The Pre Order Presentation is  : ";
    displayPreOrder(head1);
    cout << endl;
    cout << "The Post Order Presentation is : ";
    displayPostOrder(head1);
    cout << endl;
    cout << "The In Order Presentation is   : ";
    displayInOrder(head1);
    cout << endl
         << isBST(head1);
    cout << endl;
    // if (searching(head1, 25) == NULL)
    // {
    //     cout << "The Key is  NOT Found" << endl;
    // }
    // else
    //     cout << "The Key is Found" << endl;
    // if (iterativeSearch(head1, 25) == NULL)
    // {
    //     cout << "The Key is  NOT Found" << endl;
    // }
    // else
    //     cout << "The Key is Found" << endl;

    displayInOrder(head1);
    cout << endl;

    deleteNode(head1, 9);
    // deleteRoot(head1);

    // iterativeSearch(head1, 5);
    cout
        << endl;
    displayInOrder(head1);

    // preInOrder(head1);

    return 0;
}
