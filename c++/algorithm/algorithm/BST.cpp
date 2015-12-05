//
//  main.cpp
//  algorithm
//
//  Created by Carnival on 20/6/15.
//  Copyright (c) 2015 Carnival. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include "bst.h"


binaryTree::binaryTree() {
    mpRoot = NULL;
    nCount = 0;
}

void binaryTree::preOrderPrint() const {
    preOrderPrint(mpRoot);
    cout << endl << endl;
}

void binaryTree::postOrderPrint() const {
    postOrderPrint(mpRoot);
    cout << endl << endl;
}


void binaryTree::inOrderPrint() const {
    inOrderPrint(mpRoot);
    cout << endl << endl;
}

void binaryTree::preOrderPrint(const nodeBT* p) const {
    
    if(p == nullptr)
        return;
    
    cout << ", " << p->mpData;
    preOrderPrint(p->mpLeft);
    preOrderPrint(p->mpRight);
}

void binaryTree::postOrderPrint(const nodeBT* p) const {
    
    if(p == nullptr)
        return;
    
    postOrderPrint(p->mpLeft);
    postOrderPrint(p->mpRight);
    cout << ", " << p->mpData;
}


void binaryTree::inOrderPrint(const nodeBT* p) const {
    
    if(p == nullptr)
        return;
    
    inOrderPrint(p->mpLeft);
    cout << ", " << p->mpData;
    inOrderPrint(p->mpRight);
    
}

void binaryTree::insertItem(string str , nodeBT* p)
{
    if(p == nullptr)
    {
        mpRoot = new nodeBT(str);
        return;
    }
    
    if( str < p->mpData) {
        if(p->mpLeft == nullptr) {
            p->mpLeft = new nodeBT(str);
            return;
        }
        insertItem(str, p->mpLeft);
    }
    else {
        if(p->mpRight == nullptr) {
            p->mpRight = new nodeBT(str);
            return;
        }
        insertItem(str, p->mpRight);
    }
}

void binaryTree::insertItem(string str) {
    insertItem(str, mpRoot);
}

void binaryTree::deleteItem(string str, nodeBT* p)
{
    if(p == nullptr)
        return;
    
    nodeBT* pCurrent = p;
    nodeBT* pParent = p;
    //find i
    while(pCurrent != nullptr) {
        if(pCurrent->mpData == str)
            break;
        else if (pCurrent->mpData > str) { // search left node
            pParent = pCurrent;
            pCurrent = pCurrent->mpLeft;
        }
        else { // search right node
            pParent = pCurrent;
            pCurrent = pCurrent->mpRight;
        }
    }
    
    
    // delete pCurrent;
    if(pCurrent != nullptr) // we foud you, get ready to be deleted
    {
        if(pCurrent->mpLeft == nullptr && pCurrent->mpRight == nullptr) { // left and right both empty
            if(pParent->mpLeft == pCurrent) {
                pParent->mpLeft = nullptr;
            }
            else if (pParent->mpRight == pCurrent) {
                pParent->mpRight = nullptr;
            }
            delete pCurrent;
            pCurrent = nullptr;
            return;
        }
        else if (pCurrent->mpLeft == nullptr) { // only left empty
            if(pParent->mpRight == pCurrent) {
                pParent->mpRight = pCurrent->mpRight;
                delete pCurrent;
            }
            else {
                pParent->mpLeft = pCurrent->mpRight;
                delete pCurrent;
            }
        }
        else if (pCurrent->mpRight == nullptr) { // only right empty
            if(pParent->mpRight == pCurrent) {
                pParent->mpRight = pCurrent->mpLeft;
                delete pCurrent;
            }
            else {
                pParent->mpLeft = pCurrent->mpLeft;
                delete pCurrent;
            }
        }
        else { // left and right both exist
            // find largest element from left hand side and copy it over.
            if(pCurrent->mpLeft->mpRight != nullptr) {
                // traverse in while loop to find laregest number
                nodeBT* p = pCurrent->mpLeft->mpRight;
                nodeBT* q = p;
                nodeBT* r = p;
                
                while( p != nullptr) {
                    r = q;
                    q = p;
                    p = p->mpRight;
                }
                pCurrent->mpData = q->mpData;
                delete q;
                r->mpRight = nullptr;
            }
            else {
                 // no child of pCurrent's child, bring the grandchild up in place of child.
                nodeBT* temp = pCurrent;
                if(pParent->mpLeft == pCurrent) {
                    pParent->mpLeft = pCurrent->mpLeft;
                }
                else {
                    pParent->mpRight = pCurrent->mpLeft;

                }
                delete temp;
            }
        }
    }
}

void binaryTree::deleteItem(string str) {
    deleteItem(str, mpRoot);
}

string binaryTree::searchItem(string str) {
    nodeBT* p = searchItem(str, mpRoot);
    return p == nullptr ? nullptr : p->mpData;
}

int binaryTree::getCount(const nodeBT *p) const {
    int nCount = 0;
    if(p != nullptr) {
        nCount++;
        nCount += getCount(p->mpLeft);
        nCount += getCount(p->mpRight);
    }
    return nCount;
}

int binaryTree::getCount() const {
    return getCount(mpRoot);
}

nodeBT* binaryTree::searchItem(string str, nodeBT* p){
    if( p == nullptr)
        return nullptr;
    else if ( p->mpData == str)
        return p;
    else if (p->mpData > str)
        return searchItem(str, p->mpLeft);
    else
        return searchItem(str, p->mpRight);
}

binaryTree::~binaryTree() {
    destroy_tree(mpRoot);
}

void binaryTree::destroy_tree(nodeBT *p)
{
    if(p!=NULL)
    {
        destroy_tree(p->mpLeft);
        destroy_tree(p->mpRight);
        delete p;
        p = nullptr;
    }
}
