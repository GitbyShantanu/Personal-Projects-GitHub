#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node* lchild;
    struct node* rchild;
};

template <class T>
class BinarySearchTree
{
    private:
        struct node<T>* root;

    public:
        BinarySearchTree();
        void Insert(T value);
        void Inorder();
        void Preorder();
        void Postorder();
        bool Search(T value);
        int CountNode();
        int CountLeaf();
        int CountParent();
        int CountEven();
        int CountOdd();
        T Sum();
        
    private:
        void Insert(struct node<T>*& current, T value);
        void Inorder(struct node<T>* current);
        void Preorder(struct node<T>* current);
        void Postorder(struct node<T>* current);
        bool Search(struct node<T>* current, T value);
        int CountNode(struct node<T>* current);
        int CountLeaf(struct node<T>* current);
        int CountParent(struct node<T>* current);
        int CountEven(struct node<T>* current);
        int CountOdd(struct node<T>* current);
        T Sum(struct node<T>* current);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template <class T>
void BinarySearchTree<T>::Insert(T value)
{
    Insert(root, value);
}

template <class T>
void BinarySearchTree<T>::Insert(struct node<T>*& current, T value)
{
    if (current == NULL)
    {
        current = new node<T>;
        current->data = value;
        current->lchild = NULL;
        current->rchild = NULL;
    }
    else if (value < current->data)
    {
        Insert(current->lchild, value);
    }
    else if (value > current->data)
    {
        Insert(current->rchild, value);
    }
    else
    {
        cout << "Unable to insert " << value << " as it is already present in the BST.\n";
    }
}

template <class T>
void BinarySearchTree<T>::Inorder()
{
    Inorder(root);
    cout << "\n";
}

template <class T>
void BinarySearchTree<T>::Inorder(struct node<T>* current)
{
    if (current != NULL)
    {
        Inorder(current->lchild);
        cout << current->data << " ";
        Inorder(current->rchild);
    }
}

template <class T>
void BinarySearchTree<T>::Preorder()
{
    Preorder(root);
    cout << "\n";
}

template <class T>
void BinarySearchTree<T>::Preorder(struct node<T>* current)
{
    if (current != NULL)
    {
        cout << current->data << " ";
        Preorder(current->lchild);
        Preorder(current->rchild);
    }
}

template <class T>
void BinarySearchTree<T>::Postorder()
{
    Postorder(root);
    cout << "\n";
}

template <class T>
void BinarySearchTree<T>::Postorder(struct node<T>* current)
{
    if (current != NULL)
    {
        Postorder(current->lchild);
        Postorder(current->rchild);
        cout << current->data << " ";
    }
}

template <class T>
bool BinarySearchTree<T>::Search(T value)
{
    return Search(root, value);
}

template <class T>
bool BinarySearchTree<T>::Search(struct node<T>* current, T value)
{
    while (current != NULL)
    {
        if (value == current->data)
        {
            return true;
        }
        else if (value < current->data)
        {
            current = current->lchild;
        }
        else
        {
            current = current->rchild;
        }
    }
    return false;
}

template <class T>
int BinarySearchTree<T>::CountNode()
{
    return CountNode(root);
}

template <class T>
int BinarySearchTree<T>::CountNode(struct node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + CountNode(current->lchild) + CountNode(current->rchild);
    }
}

template <class T>
int BinarySearchTree<T>::CountLeaf()
{
    return CountLeaf(root);
}

template <class T>
int BinarySearchTree<T>::CountLeaf(struct node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }
    if ((current->lchild == NULL) && (current->rchild == NULL))
    {
        return 1;
    }
    else
    {
        return CountLeaf(current->lchild) + CountLeaf(current->rchild);
    }
}

template <class T>
int BinarySearchTree<T>::CountParent()
{
    return CountParent(root);
}

template <class T>
int BinarySearchTree<T>::CountParent(struct node<T>* current)
{
    if ((current == NULL) || ((current->lchild == NULL) && (current->rchild == NULL)))
    {
        return 0;
    }
    else
    {
        return 1 + CountParent(current->lchild) + CountParent(current->rchild);
    }
}

template <class T>
int BinarySearchTree<T>::CountEven()
{
    return CountEven(root);
}

template <class T>
int BinarySearchTree<T>::CountEven(struct node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }
    int count = ((current->data) % 2 == 0) ? 1 : 0;
    return count + CountEven(current->lchild) + CountEven(current->rchild);
}

template <class T>
int BinarySearchTree<T>::CountOdd()
{
    return CountOdd(root);
}

template <class T>
int BinarySearchTree<T>::CountOdd(struct node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }
    int count = ((current->data) % 2 != 0) ? 1 : 0;
    return count + CountOdd(current->lchild) + CountOdd(current->rchild);
}

template <class T>
T BinarySearchTree<T>::Sum()
{
    return Sum(root);
}

template <class T>
T BinarySearchTree<T>::Sum(struct node<T>* current)
{
    if (current == NULL)
    {
        return 0;
    }
    else
    {
        return (current->data) + Sum(current->lchild) + Sum(current->rchild);
    }
}

#endif // BINARY_SEARCH_TREE_H
