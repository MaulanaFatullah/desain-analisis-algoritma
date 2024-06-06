#include <iostream>
using namespace std;

class Node {
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

class Tree {
public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    void preOrder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (node == NULL)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    Tree tree;
    Node *root = new Node(18);
    root->left = new Node(30);
    root->left->left = new Node(29);
    root->left->right = new Node(32);
    root->right = new Node(33);

    cout << "Pre-order traversal: ";
    tree.preOrder(root);
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder(root);
    cout << endl;

    return 0;
}
