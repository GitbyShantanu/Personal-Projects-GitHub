//Generic Singly Circular Linked List using CSTL.

#ifndef SinglyCL_H
#define SinglyCL_H

#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T data;
    struct node * next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * First;
        struct node<T> * Last;
        int count;

    public:
        SinglyCL();
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
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    count = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    count++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
       Last->next = newn;
       Last = newn;
    }
    Last->next = First;
    count++;
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    count--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        Last = temp;
        delete temp->next;
        Last->next = First;
    }
    count--;
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements in SinglyCL are : \n-> ";

    if((First != NULL) && (Last != NULL))
    {
        do 
        {
            cout<<"|"<<temp->data<<"| -> ";
            temp = temp->next;
        }
        while(temp != Last->next);
        cout<<"First Node\n";
    }
}

template <class T>
int SinglyCL<T> :: CountNode()
{
    return count;
}

template <class T>
void SinglyCL<T>:: InsertAtPos(T no,int pos)
{
    int Size = CountNode();
    struct node<T> * temp = First;

    if((pos < 1) && (pos > Size+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == Size+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    count++;
}

template <class T>
void SinglyCL<T>:: DeleteAtPos(int pos)
{
    int Size = CountNode();
    struct node<T> * temp = First;
    struct node<T> * TargetedNode = NULL;

    if((pos < 1) && (pos > Size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == Size)
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
        delete TargetedNode;
    }
    count--;
}

template <class T>
int SinglyCL<T> :: SearchFirstOccurence(T no)
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
int SinglyCL<T> :: SearchLastOccurence(T no)
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
T SinglyCL<T> :: MaximumElement()
{
    struct node<T>* temp = First;
    T Max = 0;
     
    if(First != NULL)
    {
        do 
        {
            if(temp->data > Max)
            {
                Max = temp->data;
            }  
            temp = temp->next;
        } while(temp != Last->next);
        return Max;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T SinglyCL<T> :: MinimumElement()
{
    struct node<T>* temp = First;
    T Min = temp->data;
     
    if(First != NULL)
    {
        do 
        {
            if(temp->data < Min)
            {
                Min = temp->data;
            }  
            temp = temp->next;
        } while(temp != First);  
        return Min;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T SinglyCL<T> :: SecondMaximumElement()
{
    struct node<T>* temp = First;
    T Max1 = 0, Max2 = 0;
     
    if(First != NULL)
    {
        do 
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
        }while(temp != Last->next); 
        return Max2;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T SinglyCL<T> :: SecondMinimumElement()
{
    struct node<T>* temp = First;
    T Min1 = 9999.99, Min2 = 0;
     
    if(First != NULL)
    {
        do 
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
        }while(temp != Last->next); 
        return Min2;    
    }
    else
    {
        return -1;
    }
}


#endif