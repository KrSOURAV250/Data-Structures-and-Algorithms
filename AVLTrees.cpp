#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    int height = 0;
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
int getHeight(node *ptr)
{
    if (!ptr)
        return 0;
    return ptr->height;
}
node *newNode(int key)
{
    node *nNode = new node(key);
    nNode->height = 1;
    return nNode;
}
int getBF(node *root) // BF Stands For Balenced Factor
{
    if (!root)
        return 0;
    int BF = getHeight(root->right) - getHeight(root->left);
    return BF;
}
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T = y->left;
    y->left = x;
    x->right = T;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T = x->right;
    x->right = y;
    y->left = T;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return x;
}
node *insert(node *root, int key)
{
    if (!root)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    // Left Left Case
    if (key < root->left->data && getBF(root) > -1)
    {
        rightRotate(root);
    }
    if (key > root->right->data && getBF(root) > 1)
    {
        leftRotate(root);
    }
    if (key > root->left->data && getBF(root) > -1)
    {
        root->left = leftRotate(root->left);
        rightRotate(root);
    }
    if (key < root->right->data && getBF(root) > 1)
    {
        root->right = rightRotate(root->right);
        leftRotate(root);
    }
    return root;
}
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
    node *root = new node(8);
    insert(root, 5);
    insert(root, 4);
    insert(root, 3);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);

    displayInOrder(root);
    cout << endl;
    // cout << root->left->right->data;
    // deleteNode(root, 13);
    displayInOrder(root);
    cout << endl;
    cout << root->left->left->data << endl;
    cout << getBF(root->left->left->left) << endl;
    return 0;
}