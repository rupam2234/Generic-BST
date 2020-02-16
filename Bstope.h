// Implementation of generics in BST

#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Node
{
public:
    T key;
    Node* parent;
    Node* lchild;
    Node* rchild;

    Node()
    {
        parent = lchild = rchild = NULL;
    }
};

template <class T>
class Tree
{

public:
    Node<T>* root;

    Tree()
    {
        root = NULL;
    }
};

template <class T>
class Bstope : Tree <T>
{
    // for making the primary methods unaccessible out side the class


private:

    Node<T>* root;
    int value;

    int getheight(Node<T>* current, T value, int count);
    int leftSibling(Node<T>* current, int height, int value);
    int RightSibling(Node<T>* current, int height, int value);
    int MaximumSum(Node<T>* current);
    int MinimumSum(Node<T>* current);
    /*Node* LLrotation(Node* current);
    Node* LRrotation(Node* parent);
    Node* RRrotation(Node* parent);
    Node* RLrotation(Node* current);

    Node node;
*/

public:

    void insert(int value);

    int getheight(int value)  // function overloading
    {
        return getheight(root, value, -1);
    }

    int leftSibling(int value) //function overloading
    {
        return leftSibling(root, getheight(value), value);
    }
    int RightSibling(int value) //function overloading
    {
        return RightSibling(root, getheight(value), value);
    }
    int MaximumSum() //function overloading
    {
        return MaximumSum(root);
    }
	int MinimumSum() //function overloading
	{
		return MinimumSum(root);
	}
};

template <class T>
inline void Bstope<T>::insert(int value)
{
    // a new node pointed by temp is created to hold the value to be inserted
    Node<T>* temp = new Node<T>();
    temp->key = value;

    // now we take a pointer current which will initially point to the root
    // and parent pointer will point to the parent of the current node

    Node<T>* current = root;
    Node<T>* parent = NULL;

    // when current is NULL, it means no BST is there and new node will form the root of the tree
    // if it is not NULL then the current has child so it will point to class 

    while (current != NULL)
    {
        parent = current;

        if (value < current->key)
        {
            current = current->lchild;
        }

        else
        {
            current = current->rchild;
        }
    }

    // now if we check the parent of current is NULL, if yes current is a root node 

    if (parent == NULL)
    {
        //temp holds the value to be inserted, so now root will point to it.
        root = temp;
    }
    else if (value < parent->key)
    {
        parent->lchild = temp;
    }
    else
    {
        parent->rchild = temp;
    }

    //now the parent of temp will be the parent 
}

template<class T>
inline int Bstope<T>::getheight(Node<T>* current, T value, int count)
{

    if (current == NULL) {
        return count;
    }

    while (current != NULL) {

        count++;
        if (current->key == value) {
            return count;
        }

        else if (current->key > value) {
            current = current->lchild;
        }

        else current = current->rchild;
    }

    return count;
}

//for finding the leftmost cousin of a node	

template<class T>
inline int Bstope<T>::leftSibling(Node<T>* current, int height, int value)

{
    if (current == NULL)
    {
        return -1;
    }

    while (height != 0 && current != NULL)
    {
        if (current->lchild != NULL)
        {
            current = current->lchild;
            height = height - 1;
        }

        else if (current->rchild != NULL)
        {
            current = current->rchild;
            height = height - 1;
        }

        else if (height != 0)
            return -1;
    }

    if (current->key == value)
    {
        return -1;
    }

    return current->key;
}

// for finding the rightmost cousin of a node

template<class T>
inline int Bstope<T>::RightSibling(Node<T>* current, int height, int value)
{


    if (current == NULL)
    {
        return -1;
    }

    while (height != 0 && current != NULL)
    {
        if (current->rchild != NULL)
        {
            current = current->rchild;
            height = height - 1;
        }

        else if (current->lchild != NULL)
        {
            current = current->lchild;
            height = height - 1;
        }

        else if (height != 0)
            return -1;
    }

    if (current->key == value)
    {
        return -1;
    }

    return current->key;
}

//to find the maximum sum of the brunch
template<class T>
inline int Bstope<T>::MaximumSum(Node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }

    else if ((current->lchild = NULL) && (current->rchild = NULL))
    {
        return current->key;
    }

    return current->key + max(MaximumSum(current->lchild), MaximumSum(current->rchild));
}

//to find the minimum sum of the brunch

template<class T>
inline int Bstope<T>::MinimumSum(Node<T>* current)
{
	if (current == NULL)
	{
		return 0;
	}

	else if ((current->lchild = NULL) && (current->rchild = NULL))
	{
		return current->key;
	}

	return current->key + min(MaximumSum(current->lchild), MaximumSum(current->rchild));
}
