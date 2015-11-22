//
//  main.h
//  
//
//  Created by Carnival on 20/6/15.
//
//

#ifndef ____bst__
#define ____bst__

#include <stdio.h>

//// BinaryTree

struct nodeBT {
    string mpData;
    nodeBT* mpLeft;
    nodeBT* mpRight;
    
    nodeBT(string data) {
        mpData = data;
        mpLeft = nullptr;
        mpRight = nullptr;
    }
};


class binaryTree {
    
private:
    nodeBT *mpRoot; // root node
    int nCount;
    void preOrderPrint(const nodeBT* p) const;
    void postOrderPrint(const nodeBT* p) const;
    void inOrderPrint(const nodeBT* p) const;
    void destroy_tree(nodeBT* p);
    void insertItem(string str , nodeBT* p);
    nodeBT* searchItem(string str, nodeBT* p);
    int getCount(const nodeBT *p) const;
    void deleteItem(string str, nodeBT* p);
    
public:
    binaryTree();
    ~binaryTree();
    void preOrderPrint() const;
    void postOrderPrint() const;
    void inOrderPrint() const;
    void insertItem(string str);
    void deleteItem(string str);
    string  searchItem(string str);
    int  getCount() const;
};

// BinaryTree


#endif /* defined(____bst__) */
