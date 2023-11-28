//
// Created by Rizwan Syed on 11/27/23.
//
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


void BinarySearchTree::insert(BinarySearchTree::Node *&aNodePtr, BinarySearchTree::Node *&aNewNodePtr) {
    if(!aNodePtr)
        aNodePtr = aNewNodePtr;
    else if(aNewNodePtr->val < aNodePtr->val)
        insert(aNodePtr->left, aNewNodePtr);
    else
        insert(aNodePtr->right, aNewNodePtr);
}

void BinarySearchTree::deleteNode(int aVal, BinarySearchTree::Node *&aNodePtr) {
    if(aVal < aNodePtr->val)
        deleteNode(aVal, aNodePtr->left);
    else if(aVal > aNodePtr->val)
        deleteNode(aVal, aNodePtr->right);
    else
        makeDeletion(aNodePtr);
}

void BinarySearchTree::makeDeletion(BinarySearchTree::Node *&aNodePtr) {
    Node* temp = nullptr;

    if(!aNodePtr)
        cout << "Cannot remove empty node." << endl;
    else if(!aNodePtr->right){
        temp = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete temp;
    }
    else if(!aNodePtr->left){
        temp = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete temp;
    }
    else{
        temp = aNodePtr->right;
        while(temp->left){
            temp = temp->left;
        }
        temp->left = aNodePtr->left;
        temp = aNodePtr;
        aNodePtr = temp->right;

        delete temp;
    }
}

BinarySearchTree::BinarySearchTree() {

}

void BinarySearchTree::insertNode(int aVal) {
    Node* newnode = new Node(aVal);

    insert(root, newnode);
}

bool BinarySearchTree::searchNode(int aVal) {
    Node * current = root;

    while(current){
        if(current->val == aVal)
            return true;
        else if(aVal < current->val){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return false;
}

void BinarySearchTree::remove(int aVal) {

}

void BinarySearchTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        std::cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinarySearchTree::printTree(){
    displayInOrder(root);
    std::cout << std::endl;
};