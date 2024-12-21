#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

struct BST // Node for BST
{
    int data;
    BST *right;
    BST *left;

    BST *createNode(int data)
    {
        BST *newNode = new BST;
        newNode->data = data;

        // Sets the children nodes to NULL
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    /// @brief This function is used to implement InOrder Traversal (Left Subtree -> Root -> Subtree)
    /// @param rootNode The starting node of the BST
    void Traversal(BST *rootNode)
    {
        if (rootNode != NULL)
        {
            Traversal(rootNode->left);
            cout << rootNode->data << " ";
            Traversal(rootNode->right);
        }
    }

    /// @brief This function is used to search elements with recursive approach
    /// @param rootNode The starting node of the BST
    /// @param CNIC The CNIC which we're searching
    /// @return Returns NULL if the root node is empty or if the element is not found. Else, returns the node at which the element exists
    BST *searchRecord(BST *rootNode, int CNIC)
    {
        if (rootNode == NULL)
        {
            return NULL;
        }

        if (CNIC == rootNode->data)
        {
            return rootNode;
        }

        else if (CNIC < rootNode->data)
        {
            return searchRecord(rootNode->left, CNIC); // Searches element in the left subtree if the element is smaller than the current node's element
        }

        else
        {
            return searchRecord(rootNode->right, CNIC); // Searches element in the right subtree if the element is greater than the current node's element
        }
        return NULL;
    }

    /// @brief This function inserts record in the BST
    /// @param rootNode The starting node of the BST
    /// @param CNIC The record which we're trying to insert
    void insertRecord(BST *rootNode, int CNIC)
    {
        BST *prev = NULL; // Created for keeping the track of the Parent/Root Node

        while (rootNode != NULL)
        {
            prev = rootNode;

            if (rootNode->data == CNIC)
            {
                cout << "Duplicate values cannot be inserted." << endl;
                break; // Breaks the loop a duplicate value is found.
            }

            if (rootNode->data > CNIC)
            {
                rootNode = rootNode->left;
            }

            else
            {
                rootNode = rootNode->right;
            }
        }

        BST *newNode = createNode(CNIC); // Creates a new nodw with the value that we want to insert

        if (prev == NULL)
        {
            rootNode = newNode; // The element becomes the parent node if the BST was previously empty
        }

        else if (prev->data > CNIC)
        {
            prev->left = newNode;
        }

        else
        {
            prev->right = newNode;
        }
    }

    BST *inOrder_Predecessor(BST *rootNode) // Used to return left subtree's right most child node
    {
        rootNode = rootNode->left;

        while (rootNode->right != NULL)
        {
            rootNode = rootNode->right;
        }

        return rootNode;
    }
    /// @brief This function is used to delete record from the BST
    /// @param rootNode The starting node of the BST
    /// @param CNIC The CNIC we're trying to delete
    /// @return Returns the updated head if the deletion is successful. Else, false
    BST *deleteRecord(BST *rootNode, int CNIC)
    {
        if (rootNode == NULL)
        {
            cout << "The tree is already empty. Cannot perform deletion." << endl;
            return NULL;
        }

        // Searching for the node to be deleted
        if (CNIC < rootNode->data)
        {
            rootNode->left = deleteRecord(rootNode->left, CNIC);
        }

        else if (CNIC > rootNode->data)
        {
            rootNode->right = deleteRecord(rootNode->right, CNIC);
        }

        else // This block implements the functionality to delete nodes
        {
            // Case 1: Node has no children i.e. it is a Leaf Node
            if (rootNode->left == NULL && rootNode->right == NULL)
            {
                delete rootNode;
                return NULL;
            }

            // Case 2: Node has only one child
            else if (rootNode->left == NULL) // Only right child exists
            {
                BST *temp = rootNode->right;
                delete rootNode;
                return temp;
            }

            // Case 3: Only left child exists
            else if (rootNode->right == NULL)
            {
                BST *temp = rootNode->left;
                delete rootNode;
                return temp;
            }

            // Case 3: Node has two children
            else
            {
                BST *iPre = inOrder_Predecessor(rootNode);                 // Finding in-order predecessor
                rootNode->data = iPre->data;                               // Replacing data with predecessor's data
                rootNode->left = deleteRecord(rootNode->left, iPre->data); // Delete predecessor
            }
        }
        return rootNode;
    }
};

// int main()
// {
// Testing

// Node *root = new Node;
// Node *second = new Node;
// Node *third = new Node;

// root = createNode(100);
// second = createNode(102);
// third = createNode(10);

// root->right = second;
// root->left = third;

// // cout << "Pre-Order Traversal:" << endl;
// // preOrder_Traversal(root);

// // cout << "\nPost-Order Traversal" << endl;
// // postOrder_Traversal(root);

// cout << "In-Order Traversal" << endl;
// inOrder_Traversal(root);

// cout << "\nDeletion Function Called " << endl;
// root = deletion_in_BST(root, 10);

// cout << "\nIn-Order Traversal" << endl;
// inOrder_Traversal(root);

//      return 0;
// }
#endif