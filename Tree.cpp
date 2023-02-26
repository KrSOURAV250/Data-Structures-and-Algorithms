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
void displayInOrder(node *root)
{
    if (root != NULL)
    {
        displayInOrder(root->left);
        cout << root->data << " ";
        displayInOrder(root->right);
    }
}
int main(int argc, char const *argv[])
{
    node n1(55);
    node n2(25);
    node n3(59);
    node n4(24);
    node n5(27);
    node n6(58);
    node n7(61);
    node *head1 = &n1;
    node *head2 = &n2;
    node *head3 = &n3;
    node *head4 = &n4;
    node *head5 = &n5;
    node *head6 = &n6;
    node *head7 = &n7;
    head1->left = head2;
    head1->right = head3;
    head2->left = head4;
    head2->right = head5;
    head3->left = head6;
    head3->right = head7;
    cout << "The Pre Order Presentation is  : ";
    displayPreOrder(head1);
    cout << endl;
    cout << "The Post Order Presentation is : ";
    displayPostOrder(head1);
    cout << endl;
    cout << "The In Order Presentation is   : ";
    displayInOrder(head1);

    return 0;
}
