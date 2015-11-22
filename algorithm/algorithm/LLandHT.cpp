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
#include "llandht.h"

template <class T>
vector<T>::vector() {
    mCapacity = 100;
    mSize = 0;
    mHead = new T[mCapacity];
}

template <class T>
T vector<T>::getValueAt(int index) const {
    return mHead[index];
}

template <class T>
void vector<T>::push(T value) {
    if (mSize < mCapacity) {
        mHead[mSize++] = value;
    }
    else {
        cout << "reallcoatate" << endl;
        mCapacity *= 2;
        T* temp = new T(mCapacity);
        for (int i = 0; i < mSize; i++) {
            temp[i] = mHead[i];
        }
        delete [] mHead;
        mHead = temp;
    }
}

template <class T>
void vector<T>::deleteAt(int index) {
    
    --mSize;
    for (int i = index; i < mSize; i++) {
        mHead[i] = mHead[i+1];
    }
    delete mHead + mSize;
}

template <class T>
int vector<T>::size() const {
    return mSize;
}


//// linked list


template <class T, class K>
list<T,K>::list() {
    mHead = new node<T,K>();
    mCount = 0;
}

template <class T, class K>
void list<T, K>::insert(T* value, K key) {
    
    node<T,K> *pNode = new node<T,K>();
    pNode->mpData = value;
    pNode->mpKey = key;
    
    node<T, K> *p = mHead;
    node<T, K> *q = mHead;
    while (p != nullptr) {
        q = p;
        p = p->mpNext;
    }
    
    q->mpNext = pNode;
    mCount++;
    
    if(mCount == 1)
        mHead = pNode;
    
    return;
}


template <class T, class K>
bool list<T,K>::isPresent(K key) const {
    
    node<T, K> *p = mHead;
    node<T, K> *q = mHead;
    
    while (p != nullptr) {

        if(p->mpKey == key)
            return true;
        q = p;
        p = p->mpNext;
    }
    return false;
}

template <class T, class K>
void list<T,K>::deleteAt(unsigned int index) {
    
    unsigned int i = 0;

    node<T,K> *p = mHead;
    node<T,T> *q = mHead;
    
    while(p != nullptr) {
        if( i == index) {
            q->mpNext = p->mpNext;
            mCount--;
            return;
        }
        q = p;
        p = p->mpNext;
        
        i++;
    }
    return;
}

template <class T, class K>
void list<T,K>::deleteNode(K key) {
    
    node<T,K> *p = mHead;
    node<T,T> *q = mHead;
    
    while(p != nullptr) {
        if(p->mpKey == key) {
            q->mpNext = p->mpNext;
            mCount--;
            return;
        }
        q = p;
        p = p->mpNext;
    }
    return;
}

template <class T, class K>
unsigned int list<T,K>::length() const {
    return mCount;
}

template <class T, class K>
T* list<T,K>::getAt(unsigned int index) const {
    if(index >= mCount)
        return nullptr;
    
    int i = 0;
    node<T,K> *p = mHead;
    node<T,K> *q = mHead;
    while(p != nullptr) {
        if ( i++ == index)
            return p->mpData;
        q = p;
        p = p->mpNext;
    }
    return nullptr;
}

template <class T, class K>
T* list<T,K>::getData(K key) const {

    node<T,K> *p = mHead;
    node<T,K> *q = mHead;
      
    while(p != nullptr) {
        if(p->mpKey == key)
            return p->mpData;
        q = p;
        p = p->mpNext;
    }
    return nullptr;
}


template <class T, class K>
void list<T,K>::revertList() {
    if(mCount < 2)
        return;
    
    node<T,K> *p = mHead;
    node<T,K> *q = mHead;
    node<T,K> *r = mHead;
    
    while (p != nullptr) {
        r = p->mpNext;
        if( p != mHead)
            p->mpNext = q;
        else
            p->mpNext = nullptr;
        q = p;
        p = r;
    }
    mHead = q;
}

// linked list


///// hashtable
template<class K, class T>
unsigned int hashtable<K, T>::getHashIndex(K key) {
    string str = static_cast<string> (key);
    int value = 0;
    for ( int i = 0; i < str.length(); i++ )
        value += str[i];
    return (value * str.length() ) % 13;
}

template <class K, class T>
void hashtable<K, T>::insert(K key, T* element) {
    unsigned int hashIndex = this->getHashIndex(key);
    _list[hashIndex].insert(element, key);
}

template <class K, class T>
T* hashtable<K, T>::getElement(K key) const {
    unsigned int hashIndex = this->getHashIndex(key);
    return _list[hashIndex].getData(key);
}

template <class K, class T>
bool hashtable<K, T>::isPresent(K key) const{
    unsigned int hashIndex = this->getHashIndex(key);
    return _list[hashIndex].isPresent(key);
}

template <class K, class T>
void hashtable<K, T>::deleteElement(K key) {
    unsigned int hashIndex = this->getHashIndex(key);
    return _list[hashIndex].getData(key);
}

template <class K, class T>
void hashtable<K,T>::printHT() {
    
    for( int i = 0; i < 100; i++) {
        cout << endl;
        int length = _list[i].length();
        for (int j = 0; j < length; j++)
            cout << ", " << *(_list[i].getAt(j));
    }
    
}

// hastable

int main1(int argc, const char * argv[]) {

    //// linked list
    
    // Create 26 new node<string, string>s to store in the Hash Table.
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
    
    //// hashtable implementation
    hashtable<string, string> ht;
    ht.insert(A, &A);
    ht.insert(B, &B);
    ht.insert(C, &C);
    ht.insert(D, &D);
    ht.insert(E, &E);
    ht.insert(F, &F);
    ht.insert(G, &G);
    ht.insert(H, &H);
    
    cout << endl << "Printing hashtable: ";
//    ht.printHT();
    
    
    //// linked list implementation
    
    list<string, string> _list;
    
    _list.insert(&A, A);
    _list.insert(&B, B);
    _list.insert(&C, C);
    _list.insert(&D, D);
    _list.insert(&E, E);
    _list.insert(&F, F);
    _list.insert(&G, G);
    _list.insert(&H, H);
//    _list.insert(&I, I);
//    _list.insert(&J, J);
//    _list.insert(&K, K);
//    _list.insert(&L, L);
//    _list.insert(&M, M);
//    _list.insert(&N, N);
//    _list.insert(&O, O);
//    _list.insert(&P, P);
//    _list.insert(&Q, Q);
//    _list.insert(&R, R);
//    _list.insert(&S, S);
//    _list.insert(&T, T);
//    _list.insert(&U, U);
//    _list.insert(&V, V);
//    _list.insert(&W, W);
//    _list.insert(&X, X);
//    _list.insert(&Y, Y);
//    _list.insert(&Z, Z);
//    
    cout << "length of the linked list is: " << _list.length() << endl;
    
    cout << "current list is " << endl;
    for( int i = 0; i < _list.length(); i++){
        cout << ", " + *(_list.getAt(i));
    }
    
    cout << endl << endl;
    
    
    _list.deleteAt(5);
    cout << "Deleted 6th element and then the list is" << endl;
    
    for( int i = 0; i < _list.length(); i++){
        cout << ", " + *(_list.getAt(i));
    }
    
    cout << endl << "length of the linked list is: " << _list.length() << endl;
    cout << "Data at key House is: " << *(_list.getData("House")) << endl;
    cout << "Data at first index is: " << *(_list.getAt(0)) << endl;
    cout << "Data at last index is: " << *(_list.getAt(_list.length() - 1)) << endl;
    
    cout << endl << endl << "Reversing the linked list" << endl;
    _list.revertList();
    cout << endl << "length of the linked list is: " << _list.length() << endl;
    for( int i = 0; i < _list.length(); i++){
        cout << ", " + *(_list.getAt(i));
    }
    cout << endl;
    
    return 0;
    
    
    //// vector implementation
    
//    int m, n;
//    vector<int> v;
//    cout << "Please enter size of array your are entering" << endl;
//    cin >> n;
//    cout << "Please enter an array of numbers" << endl;
//    for (int i = 0; i < n; i++) {
//        cin >> m;
//        v.push(m);
//    }
//    
//    cout << "Here are the numbers you entered as an array" << endl;
//    for (int i = 0; i < v.size(); i++) {
//        cout << v.getValueAt(i) << " ";
//    }
//    
//    cout << endl;
//    return 0;
    
    
    //// remove duplicate charracters from a given string
    
//    string str;
//    int nDup = 0;
//    
//    cout << "Please enter a string " << endl;
//    getline(cin, str);
//    size_t length = str.length();
//    
//    for(int i=0; i < length; i++) {
//        int j;
//        for (j = 0; j < i-nDup; j++) {
//            if(str[j] == str[i]) {
//                nDup++;
//                break;
//            }
//        }
//        if(j == i - nDup)
//            str[j]=str[i];
//    }
//    str[length-nDup] = 0;
//    
//    cout << "Here is the string without any duplicate character" << endl;
//    cout << str;
//    return 0;
    
}
