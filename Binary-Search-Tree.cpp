#include <iostream>
using namespace std;

struct Node // Node for BST
{
    int data;
    Node *right;
    Node *left;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;

    // Sets the children nodes to NULL
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void preOrder_Traversal(Node *rootNode) // Root -> Left Subtree -> Right Subtree
{
    if (rootNode != NULL) // Traverses the BST if the root node is not NULL
    {
        cout << rootNode->data << " ";
        preOrder_Traversal(rootNode->left);  // Traverses left subtrees
        preOrder_Traversal(rootNode->right); // Traverses right subtrees
    }
}

void postOrder_Traversal(Node *rootNode) // Left Subtree -> Right Subtree -> Root
{
    if (rootNode != NULL)
    {
        postOrder_Traversal(rootNode->left);
        postOrder_Traversal(rootNode->right);
        cout << rootNode->data << " ";
    }
}

void inOrder_Traversal(Node *rootNode) // Left Subtree -> Root -> Subtree
{
    if (rootNode != NULL)
    {
        inOrder_Traversal(rootNode->left);
        cout << rootNode->data << " ";
        inOrder_Traversal(rootNode->right);
    }
}

Node *recursive_Binary_Search(Node *rootNode, int Element)
{
    if (rootNode == NULL)
    {
        return NULL;
    }

    if (Element == rootNode->data)
    {
        return rootNode;
    }

    else if (Element < rootNode->data)
    {
        return recursive_Binary_Search(rootNode->left, Element); // Searches element in the left subtree if the element is smaller than the current node's element
    }

    else
    {
        return recursive_Binary_Search(rootNode->right, Element); // Searches element in the right subtree if the element is greater than the current node's element
    }
}

Node *iterative_Search(Node *rootNode, int Element)
{
    while (rootNode != NULL) // Iterates through the BST until it reaches NULL
    {
        if (rootNode->data == Element)
        {
            return rootNode;
        }

        else if (rootNode->data > Element)
        {
            rootNode = rootNode->left; // Searches elements in left subtree if the element is smaller than the current node's element
        }

        else
        {
            rootNode = rootNode->right; // Searches elements in right subtree if the element is greater than the current node's element
        }
    }
    return NULL; // Returns NULL if the root node is NULL or if the desired element is not found
}

void insertion_in_BST(Node *rootNode, int Element)
{
    Node *prev = NULL; // Created for keeping the track of the Parent/Root Node

    while (rootNode != NULL)
    {
        prev = rootNode;

        if (rootNode->data == Element)
        {
            cout << "Duplicate values cannot be inserted." << endl;
            break; // Breaks the loop a duplicate value is found.
        }

        if (rootNode->data > Element)
        {
            rootNode = rootNode->left;
        }

        else
        {
            rootNode = rootNode->right;
        }
    }

    Node *newNode = createNode(Element); // Creates a new nodw with the value that we want to insert

    if (prev == NULL)
    {
        rootNode = newNode; // The element becomes the parent node if the BST was previously empty
    }

    else if (prev->data > Element)
    {
        prev->left = newNode;
    }

    else
    {
        prev->right = newNode;
    }
}

int main()
{
    // Testing

    // Node *root = new Node;
    // Node *second = new Node;
    // Node *third = new Node;

    // root = createNode(100);
    // second = createNode(102);
    // third = createNode(10);

    // root->right = second;
    // root->left = third;

    // cout << "Pre-Order Traversal:" << endl;
    // preOrder_Traversal(root);

    // cout << "\nPost-Order Traversal" << endl;
    // postOrder_Traversal(root);

    // cout << "\nIn-Order Traversal" << endl;
    // inOrder_Traversal(root);

    // cout << "\n"
    //      << endl;

    // cout << "Insertion Function Called." << endl;
    // insertion_in_BST(root, 101);

    // cout << "\nIn-Order Traversal Function Called after Insertion: " << endl;
    // inOrder_Traversal(root);

    return 0;
}