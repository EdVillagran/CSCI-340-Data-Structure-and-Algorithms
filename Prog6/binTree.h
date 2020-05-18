//Edgar Villagran 
//Assignment 6
//10/30/2018

#ifndef BINTREE_H
#define BINTREE_H

#include "Node.h"
#include <iostream>
using namespace std;

template < class T > class binTree {

	//public function versions call the private functions 
public:

	// default constructor
	binTree(); 
	// returns height of BT
	unsigned height() const; 
	// inserts node in BT
	virtual void insert(const T&v);
	// inorder traversal of BT
	void inorder(void(*fn)(const T&)); 

protected:
	//Root for tree
	Node < T >* root; 
private:

	// private versions of functions that have access to nodes and root
	unsigned height(Node < T >*) const; 
	void insert(Node < T >*&p, const T&v); 
	void inorder(Node < T >*p, void(*fn) (const T&));
};

//type definition
typedef enum { left_side, right_side } SIDE;
SIDE rnd() { return rand() % 2 ? right_side : left_side; }


//default consturctor initializez root
template <class T>
binTree <T>::binTree()
{
	root = 0;
}

//public function calls private and returns the height of the BT
template <class T>
unsigned binTree <T>::height() const
{
	return height(root);
}
//calls private insert 
template <class T>
void binTree <T>::insert(const T& v)
{
	insert(root, v);
}
//calls  private inorder function
template <class T>
void binTree <T>::inorder(void(*fn)(const T&))
{
	inorder(root, fn);
}

//private function definitions
template <class T>
unsigned binTree <T>::height(Node < T >* p) const
{
	//If the node is empty it returns 0
	if (p == 0)
	{
		return 0;
	}
	else
	{
		//Using recursion to find height of BT

		//left side
		int leftHeight = height(p->left);
		//right side
		int rightHeight = height(p->right);

		//determines which is side has the greater height
		if (leftHeight > rightHeight)
		{
			return 1 + leftHeight;
		}
		else
		{
			return 1 + rightHeight;
		}
	}
}
//inserts a value into node
template <class T>
void binTree <T>::insert(Node < T >*&p, const T&val) {
	if (p == nullptr)
	{
		//sets p to a new node
		p = new Node <T>(val);
	}
	else
	{
		//randomizes the variable
		SIDE s = rnd();
		//condition to put value into either left or right
		if (s == left_side)
		{
			insert(p->left, val);
		}
		else
		{
			insert(p->right, val);
		}
	}
}
//prints the tree inorder
template <class T>
void binTree <T>::inorder(Node < T >*p, void(*fn) (const T&)) {
	if (p != NULL)
	{
		inorder(p->left, fn);
		fn(p->data);
		inorder(p->right, fn);
	}
}

#endif
