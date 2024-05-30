#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char value)
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

    void insert(char value)
    {
        root = insert(root, value);
    }

    Node *insert(Node *node, char value)
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

    void preorderTraversal() { preorderTraversal(root); }

    void preorderTraversal(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal() { inorderTraversal(root); }

    void inorderTraversal(Node *node)
    {
        if (node == NULL)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal() { postorderTraversal(root); }

    void postorderTraversal(Node *node)
    {
        if (node == NULL)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
};

int main()
{
    Tree tree;
    tree.insert('R');
    tree.insert('A');
    tree.insert('E');
    tree.insert('I');
    tree.insert('S');
    tree.insert('T');

    cout << "Posisi Awal Tree: \n";
    cout << "\t\t\t R" << endl;
    cout << "\t\t\t/ \\" << endl;
    cout << "\t\t       A   E" << endl;
    cout << "\t\t      /" << endl;
    cout << "\t\t     S" << endl;
    cout << "\t\t    / \\" << endl;
    cout << "\t\t   I  T" << endl;

    cout << "\nPreorder: ";
    tree.preorderTraversal();
    cout << endl;

    cout << "Inorder: ";
    tree.inorderTraversal();
    cout << endl;

    cout << "Postorder: ";
    tree.postorderTraversal();
    cout << endl;
    return 0;
}
