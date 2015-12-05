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

////vector
template <class T>
class vector {
    int mSize;
    int mCapacity;
    T* mHead;
    
public:
    vector();
    T getValueAt(int index) const;
    void push(T value);
    void deleteAt(int index);
    int size() const;
};
//vector

////list

template <class T, class K>
class node {
public:
    K mpKey;
    T* mpData;
    node *mpNext;
};

template <class T, class K>
class list {
private:
    node<T, K> *mHead;
    unsigned int mCount;
    
public:
    list();
    void insert(T* value, K key);
    bool isPresent(K key) const;
    void deleteAt(unsigned int i);
    void deleteNode(K key);
    T*   getAt(unsigned int i) const;
    T*   getData(K key) const;
    unsigned int length() const;
    void revertList();
};

//list

//// hashtable

template <class K = std::string, class T = std::string>
class hashtable {
    
    list<T,K> _list[100];
    
public:
    unsigned int getHashIndex(K key);
    void insert(K key, T* element);
    T* getElement(K key) const;
    bool isPresent(K key) const;
    void deleteElement(K key);
    void printHT();
};
 

// hashtable

#endif /* defined(____main__) */
