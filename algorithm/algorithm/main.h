//
//  main.h
//  
//
//  Created by Carnival on 20/6/15.
//
//

#ifndef ____main__
#define ____main__

#include <stdio.h>

//// llist

struct item {
    int mData;
    item *mpNext;
    
    item() {}
    item(int i) {
        mData = i;
        mpNext = nullptr;
    }
};

class llist {
private:
    item* mpHead;
    int mCount;
    
public:
    llist();
    void insertItem(int i);
    void printItems();
    void deleteItem(int i);
    int  getItemAt(int idx);
    void reverseList();
};


// llist

//// hashtable

class hashtable {
private:
    item* mList[100];
    int mCount;
    int hash(int i);
    
public:
    hashtable();
    void insertItem(int i);
    void printItems();
    void deleteItem(int i);
    int  getItem(int i);
};

// hashtable


#endif /* defined(____main__) */
