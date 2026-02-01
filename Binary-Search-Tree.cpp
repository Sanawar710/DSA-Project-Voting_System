// BST implementation
#include "Binary-Search-Tree.h"

#include <iostream>

BST *BST::createNode(int data)
{
    BST *newNode = new BST;
    newNode->data = data;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BST::Traversal(BST *rootNode)
{
    if (rootNode != NULL)
    {
        Traversal(rootNode->left);
        std::cout << rootNode->data << " ";
        Traversal(rootNode->right);
    }
}

BST *BST::searchRecord(BST *rootNode, int CNIC)
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
        return searchRecord(rootNode->left, CNIC);
    }

    else
    {
        return searchRecord(rootNode->right, CNIC);
    }
    return NULL;
}

void BST::insertRecord(BST *rootNode, int CNIC)
{
    BST *prev = NULL;

    while (rootNode != NULL)
    {
        prev = rootNode;

        if (rootNode->data == CNIC)
        {
            std::cout << "Duplicate values cannot be inserted." << std::endl;
            break;
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

    BST *newNode = createNode(CNIC);

    if (prev == NULL)
    {
        rootNode = newNode;
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

BST *BST::inOrder_Predecessor(BST *rootNode)
{
    rootNode = rootNode->left;

    while (rootNode->right != NULL)
    {
        rootNode = rootNode->right;
    }

    return rootNode;
}

BST *BST::deleteRecord(BST *rootNode, int CNIC)
{
    if (rootNode == NULL)
    {
        std::cout << "The tree is already empty. Cannot perform deletion." << std::endl;
        return NULL;
    }

    if (CNIC < rootNode->data)
    {
        rootNode->left = deleteRecord(rootNode->left, CNIC);
    }

    else if (CNIC > rootNode->data)
    {
        rootNode->right = deleteRecord(rootNode->right, CNIC);
    }

    else
    {
        if (rootNode->left == NULL && rootNode->right == NULL)
        {
            delete rootNode;
            return NULL;
        }

        else if (rootNode->left == NULL)
        {
            BST *temp = rootNode->right;
            delete rootNode;
            return temp;
        }

        else if (rootNode->right == NULL)
        {
            BST *temp = rootNode->left;
            delete rootNode;
            return temp;
        }

        else
        {
            BST *iPre = inOrder_Predecessor(rootNode);
            rootNode->data = iPre->data;
            rootNode->left = deleteRecord(rootNode->left, iPre->data);
        }
    }
    return rootNode;
}