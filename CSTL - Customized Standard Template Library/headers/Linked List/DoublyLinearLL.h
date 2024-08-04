//Generic Doubly Linear Linked List for all primitive datatypes.

#ifndef DoublyLL_H
#define DoublyLL_H

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * prev;
    struct node * next;
};

template <class T>
class DoublyLL
{
    public:
        struct node<T> * First;
        int count;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode(); 
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int pos);
        void DeleteAtPos(int pos);

        // customized functions below...
        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        T MaximumElement();
        T MinimumElement();
        T SecondMaximumElement();
        T SecondMinimumElement();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    this->First = NULL;
    this->count = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;
    
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    count++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;
    
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    count++;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    count--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    count--;
}

template <class T>
void DoublyLL<T> :: Display()
{   
    struct node<T> * temp = First;
    cout<<"Elements in LL are : \nNULL <=> ";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T> 
int DoublyLL<T> :: CountNode()
{
    return count;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos)
{
    int iSize = CountNode();
    struct node<T> * newn = NULL;
    struct node<T> * temp = First;

    if((pos < 1) || (pos > iSize+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;

        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
    count++;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    int iSize = CountNode();
    struct node<T> * temp = First;
    struct node<T> * TargetedNode = NULL;

    if((pos < 1) || (pos > iSize))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        TargetedNode = temp->next;
        temp->next = TargetedNode->next;
        TargetedNode->next->prev = temp;
        delete TargetedNode;
    }
    count--;
}

template <class T>
int DoublyLL<T> :: SearchFirstOccurence(T no)
{
    struct node<T>* temp = First;
    int iCnt = -1;
    if(First != NULL)
    {
        for(iCnt = 1; iCnt <= CountNode(); iCnt++)
        {
            if((temp->data) == no)
            {
                return iCnt;
                break;
            }   
            temp = temp->next;
        }
        return -1;
    }
    else
    {
        return iCnt;
    }
}

template <class T>
int DoublyLL<T> :: SearchLastOccurence(T no)
{
    struct node<T>* temp = First;
    int iCnt = 0, LastOcc = -1;

    if(First != NULL)
    {
        for(iCnt = 1; iCnt <= CountNode(); iCnt++)
        {
            if((temp->data) == no)
            {
                LastOcc = iCnt;
            }   
            temp = temp->next;
        }
        return LastOcc;
    }
    else
    {
        return -1;
    }
}

template <class T>
T DoublyLL<T> :: MaximumElement()
{
    struct node<T>* temp = First;
    T Max = 0;
     
    if(First != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data > Max)
            {
                Max = temp->data;
            }  
            temp = temp->next;
        }   
        return Max;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T DoublyLL<T> :: MinimumElement()
{
    struct node<T>* temp = First;
    T Min = temp->data;
     
    if(First != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data < Min)
            {
                Min = temp->data;
            }  
            temp = temp->next;
        }   
        return Min;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T DoublyLL<T> :: SecondMaximumElement()
{
    struct node<T>* temp = First;
    T Max1 = temp->data, Max2 = 0;
     
    if(First != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data > Max1)
            {
                Max2 = Max1;
                Max1 = temp->data;
            }  
            else if((temp->data < Max1) && (temp->data > Max2))
            {
                Max2 = temp->data;
            }  
            temp = temp->next;
        }   
        return Max2;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T DoublyLL<T> :: SecondMinimumElement()
{
    struct node<T>* temp = First;
    T Min1 = 9999, Min2 = 0;
     
    if(First != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data < Min1)
            {
                Min2 = Min1;
                Min1 = temp->data;
            }  
            else if((temp->data > Min1) && (temp->data < Min2))
            {
                Min2 = temp->data;
            }  
            temp = temp->next;
        }   
        return Min2;    
    }
    else
    {
        return -1;
    }
}

#endif