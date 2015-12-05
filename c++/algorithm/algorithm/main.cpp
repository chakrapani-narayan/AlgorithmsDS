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
#include "main.h"

#define SIZE 20

// Data
int items[] = {45, 34, 59, 3, 32, 10, 3, 9 , 84, 32, 84, 2, 4, 3, 55, 13, 6, 33, 81, 45};
//int items[] = {45, 34, 59, 3};
// more Data
string A =  ("Apple");
string B =  ("Banana");
string C =  ("Caterpillar");
string D =  ("Dog");
string E =  ("Elephant");
string F =  ("Fedora");
string G =  ("Goosebumps");
string H =  ("House");
string I =  ("Insects");
string J =  ("Jam");
string K =  ("Kite");
string L =  ("Limestone");
string M =  ("Mountaineering");
string N =  ("Night");
string O =  ("Open Sesame");
string P =  ("Potatoes");
string Q =  ("Quantum Mechanics");
string R =  ("Rrrrrrrrrrawr");
string S =  ("Snakes");
string T =  ("Tizzy Tube");
string U =  ("Underworld");
string V =  ("Volcanic Ash");
string W =  ("Who When What Why");
string X =  ("XXX");
string Y =  ("Yellow");
string Z =  ("Zest of Lemon");


//// llist

llist::llist()
{
    mpHead = new item();
    mCount = 0;
}
void llist::insertItem(int i) {
    item* p = mpHead;
    item* q = mpHead;
    while(p) {
        q = p;
        p = p->mpNext;
    }
    q->mpNext = new item(i);
    
    if(mCount == 0)
        mpHead = mpHead->mpNext;
    
    mCount++;
}

void llist::printItems() {
    item* p = mpHead;
    while(p) {
        cout << ", " << p->mData;
        p = p->mpNext;
    }
    cout << endl;
}

void llist::deleteItem(int i) {
    item* p = mpHead;
    item* q = mpHead;
    while(p) {
        if(p->mData == i) {
            q->mpNext = p->mpNext;
            mCount--;
            break;
        }
        q = p;
        p = p->mpNext;
    }
}

int  llist::getItemAt(int idx) {
    item* p = mpHead;
    int i = 0;
    while(p) {
        if(i++ == idx)
            return p->mData;
        
        p = p->mpNext;
    }
    return -1;
}

void llist::reverseList() {
    item* p = mpHead;
    item* q = mpHead;
    item* r = mpHead;

    while(p) {
        r = p->mpNext;
        p->mpNext = q;
        q = p;
        if( p == mpHead)
            p->mpNext = nullptr;
        p = r;
    }
    mpHead = q;
}

//// hashtable
hashtable::hashtable(){
    mCount = 0;
}

int hashtable::hash(int i) {
    return i;
}

void hashtable::insertItem(int i) {
    
    int j = hash(i);

    item* mpHead = mList[j];
    item* p = mpHead;
    item* q = mpHead;
    while(p) {
        q = p;
        p = p->mpNext;
    }
    if( p != q)
        q->mpNext = new item(i);
    else
        mList[j] = new item(i);

    mCount++;
}

void hashtable::printItems() {
    for(int i = 0; i < 100 ; i++) {
        item* p = mList[i];
        while(p) {
            cout << ", " << p->mData;
            p = p->mpNext;
        }
        cout << endl;
    }
}

void hashtable::deleteItem(int i) {
    for(int i = 0; i < 100 ; i++) {
        item* p = mList[i];
        item* q = mList[i];;
        while(p) {
            if(p->mData == i) {
                q->mpNext = p->mpNext;
                mCount--;
                break;
            }
            q = p;
            p = p->mpNext;
        }
        cout << endl;
    }
}

int hashtable::getItem(int i) {
    for(int i = 0; i < 100 ; i++) {
        item* p = mList[i];
        while(p) {
            if(p->mData == i) {
                return p->mData;
            }
            p = p->mpNext;
        }
        cout << endl;
    }
    return -1;
}
// hashtable

//// merge sort

void merge(int left, int mid, int right) {
    int temp[SIZE];
    
    int i = left;
    int j = mid + 1;
    for( int k = left; k <= right ; k++ ) {
        if( i <= mid && j <= right) {
            if(items[i] < items[j])
                temp[k] = items[i++];
            else
                temp[k] = items[j++];
        }
        else if(i > mid)
                temp[k] = items[j++];
        else
            temp[k] = items[i++];
    }
    
    for( int k = left; k <= right ; k++ ) {
        items[k] = temp[k];
    }
    
    
}

void mergeSort(int left, int right){
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

// merge sort

//// quick sort

int placePivot(int left, int right) {
    int temp;
    int pivot = items[right];
    int pivotIndex = left;
    for(int i = left; i < right; i++) {
        if(items[i] <= pivot) {
            temp = items[i];
            items[i] = items[pivotIndex];
            items[pivotIndex] = temp;
            ++pivotIndex;
        }
    }
    
    temp = items[right];
    items[right] = items[pivotIndex];
    items[pivotIndex] = temp;
    return pivotIndex;
}

void quickSort(int left, int right) {
    if(left < right) {
        int pivotIndex = placePivot(left, right);
        quickSort(left, pivotIndex - 1);
        quickSort(pivotIndex + 1, right);
    }
}

// quick sort


// list

int main(int argc, const char * argv[]) {

//    //// mergesort
//    cout << endl << "Before merge sort: " << endl;
//    
//    for( int k = 0; k < SIZE ; k++ ) {
//        cout << ", " << items[k];
//    }
//    
//    mergeSort(0, SIZE - 1);
//    
//    cout << endl << "After merge sort: " << endl;
//    
//    for( int k = 0; k < SIZE ; k++ ) {
//        cout << ", " << items[k];
//    }
//    
//    // mergesort
    
    //// quicksort
    
        cout << endl << "Before quick sort: " << endl;
    
        for( int k = 0; k < SIZE ; k++ ) {
            cout << ", " << items[k];
        }
    
        quickSort(0, SIZE - 1);
    
        cout << endl << "After quick sort: " << endl;
    
        for( int k = 0; k < SIZE ; k++ ) {
            cout << ", " << items[k];
        }
    
    // quicksort
    
    //// llist
//    llist _list;
//    
//    int count = sizeof(items) / sizeof(int);
//    for( int i = 0; i < count ; i ++) {
//        _list.insertItem(items[i]);
//    }
//    
//    _list.printItems();
//    
//    _list.deleteItem(3);
//    
//    _list.printItems();
//    
//    int i = _list.getItemAt(7);
//    cout << endl << "Item at 7th position is: " << i;
//    
//    _list.reverseList();
//    cout << "Reversed list is: " << endl;
//    _list.printItems();
    
    // llist
    
    //// ht
//    hashtable _ht;
//    
//    int count = sizeof(items) / sizeof(int);
//    for( int i = 0; i < count ; i ++) {
//        _ht.insertItem(items[i]);
//    }
//    
//    _ht.printItems();
//    
//    _ht.deleteItem(3);
//    
//    _ht.printItems();

    
    // ht

    
    //// BST
    
//    binaryTree bt;
//    bt.insertItem(I);
//    bt.insertItem(U);
//    bt.insertItem(K);
//    bt.insertItem(G);
//    bt.insertItem(T);
//    bt.insertItem(Z);
//    bt.insertItem(H);
//    bt.insertItem(C);
//    bt.insertItem(J);
//    bt.insertItem(X);
//    bt.insertItem(L);
//    bt.insertItem(B);
//    bt.insertItem(E);
//    bt.insertItem(F);
//    bt.insertItem(P);
//    bt.insertItem(M);
//    bt.insertItem(Y);
//    bt.insertItem(N);
//    bt.insertItem(R);
//    bt.insertItem(D);
//    bt.insertItem(Q);
//    bt.insertItem(S);
//    bt.insertItem(W);
//    bt.insertItem(V);
//    bt.insertItem(O);
//    bt.insertItem(A);
//    
//    cout << "InOrderPrint" << endl << endl;
//    bt.inOrderPrint();
//    
//    //    cout << "PreOrderPrint" << endl << endl;
//    //    bt.preOrderPrint();
//    //
//    //    cout << "PostOrderPrint" << endl << endl;
//    //    bt.postOrderPrint();
//    
//    cout << " count is " << bt.getCount() << endl << endl;
//    
//    
//    cout << "Deleting an item" << endl << endl;
//    bt.deleteItem("Goosebumps");
//    
//    cout << " count is " << bt.getCount() << endl << endl;
//    
//    bt.inOrderPrint();
    
    // BST
    
    return 0;
 
}
