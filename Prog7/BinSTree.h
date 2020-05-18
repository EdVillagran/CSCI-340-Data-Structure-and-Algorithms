//binSTree.h

#ifndef BINSTREE_H
#define BINSTREE_H

#include <vector>
#include <algorithm>
using std::generate; using std::sort;

#include "binTree.h"

template <class T>
class binSTree;

template < class T >
class binSTree : public binTree <T> {
public:
    void insert ( const T& );
    void remove ( const T& );

private:
    void insert ( Node < T >*&, const T& );
    void remove ( Node < T >*&, const T& );
    Node<T>* pred ( Node<T>* );
};


template <class T>
void binSTree<T>::insert( const T& element ) {
    insert(this->root, element);
}


template <class T>
void binSTree<T>::remove( const T& element ) {
    remove(this->root, element);
}

template <class T>
void binSTree<T>::insert( Node<T>*& ptr, const T& element ) {
    if(ptr == NULL)
        ptr = new Node<T>(element);
    else {
        if(element < ptr->data)
            insert(ptr->left, element);
        else
            insert(ptr->right, element);
    }
}

template <class T>
void binSTree<T>::remove( Node<T>*& ptr, const T& element ) {
    Node<T>* temp = ptr;

    if(ptr == NULL)
        return ; //node doesnt exist
    else if(element < ptr->data)
        remove(ptr->left, element);
    else if(element > ptr->data)
        remove(ptr->right, element);
    else {
        //no Child
        if(ptr->left == NULL && ptr->right == NULL){
            delete ptr;
            ptr = NULL;
        }
            //one child
        else if( ptr->right == NULL) {
            ptr = ptr->left;
            delete temp;
        }
        else if( ptr->left == NULL) {
            ptr = ptr->right;
            delete temp;
        }
            //two childs
        else {
            temp = pred(ptr->left);
            ptr->data = temp->data;
            remove(ptr->left, temp->data);
        }
    }
}

template <class T>
Node<T>* binSTree<T>::pred( Node<T>* ptr) {
    while(ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr;
}

#endif