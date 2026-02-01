#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

struct BST
{
    int data;
    BST *right;
    BST *left;

    BST *createNode(int data);

    void Traversal(BST *rootNode);

    BST *searchRecord(BST *rootNode, int CNIC);

    void insertRecord(BST *rootNode, int CNIC);

    BST *inOrder_Predecessor(BST *rootNode);

    BST *deleteRecord(BST *rootNode, int CNIC);
};

#endif // BINARYSEARCHTREE_H
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

struct BST
{
    int data;
    BST *right;
    BST *left;

    BST *createNode(int data);

    void Traversal(BST *rootNode);

    BST *searchRecord(BST *rootNode, int CNIC);

    void insertRecord(BST *rootNode, int CNIC);

    BST *inOrder_Predecessor(BST *rootNode);

    BST *deleteRecord(BST *rootNode, int CNIC);
};

#endif // BINARYSEARCHTREE_H
// Header wrapper for Binary-Search-Tree.cpp
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Binary-Search-Tree.cpp"

#endif // BINARY_SEARCH_TREE_H
