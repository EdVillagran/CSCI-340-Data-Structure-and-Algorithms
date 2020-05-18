//binTree.h

#ifndef BINTREE_H
#define BINTREE_H

using std::max;
using namespace std;
#include<iostream>
#include "Node.h"

template <class T>
class binTree;

template <class T>
class binTree {
public:
    binTree() { root = NULL; };
    unsigned height () const;
    virtual void insert( const T& );
    void inorder(void (*) (T&) );
    unsigned size() const;
    typedef enum { left_side, right_side } SIDE;
    SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }
protected:
    Node <T>* root;

private:
    unsigned height( Node<T>* ) const;
    void insert( Node<T>*&, const T& );
    void inorder( Node<T>*, void (*) (T&) );
    unsigned size( Node<T>* ) const;
};


template <class T>
unsigned binTree<T>::size() const {
    return size(root);
}


template <class T>
unsigned binTree<T>::height() const {
    return height(root);
}


template <class T>
void binTree<T>::insert( const T& element ) {
    insert(root, element);
}

template<class T>
inline void binTree<T>::inorder(void(*)(T &))
{
	inorder(root, func);
}


template <class T>
unsigned binTree<T>:: size( Node<T>* ptr ) const {
    if(ptr == NULL) //if null, size = 0
        return 0;
    else
        return (size(ptr->left) + 1 + size(ptr->right));
}


template <class T>
unsigned binTree<T>::height( Node<T>* ptr) const {
    if(!ptr) //if null, height = 0
        return 0;

    return 1+ max(height(ptr->left), height(ptr->right)); //finds tree height
}


template <class T>
void binTree<T>::insert( Node<T>*& ptr, const T& element) {
    if(ptr == NULL) {
        ptr = new Node<T>();
        ptr->right = NULL;
        ptr->left = NULL;
        ptr->data = element;
    }
    else if( rnd() == right_side ) //if rnd == right_side, make new node on right
        insert(ptr->right, element);
    else //else left
        insert(ptr->left, element);

}

template<class T>
inline void binTree<T>::inorder(Node<T>*, void(*)(T &))
{
	if (ptr != NULL) {
		inorder(ptr->left, func);
		func(ptr->data);
		inorder(ptr->right, func);
	}


}



#endif