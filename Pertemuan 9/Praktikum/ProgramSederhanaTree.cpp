#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }

    void insert(int value)
    {
        root = insert(root, value);
    }

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            node = new Node(value);
        }
        else if (value <= node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorder() { inorder(root); }

    void inorder(Node *node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main()
{
    Tree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.inorder();
    return 0;
}