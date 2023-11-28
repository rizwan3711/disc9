//
// Created by Rizwan Syed on 11/27/23.
//
#include <iostream>
#ifndef DISC9_BINARYTREE_H
#define DISC9_BINARYTREE_H

class BinarySearchTree{
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* left = nullptr, Node* right = nullptr);
    };

    Node* root;

    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);

public:
    BinarySearchTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();
};
#endif //DISC9_BINARYTREE_H
