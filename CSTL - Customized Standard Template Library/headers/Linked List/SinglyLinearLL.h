//Generic Singly Linear Linked List for all primitive datatypes with customised functions.

#ifndef SinglyLL_H
#define SinglyLL_H

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;             
    struct node * next;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> * First;     
        int count;

    public:
        SinglyLL();
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
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
    count = 0;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;       
    
    newn = new struct node<T>;          
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    count++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct node<T> * temp = First;
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    count++;
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct node<T> * temp = First;
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
        delete temp;
    }
    count--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct node<T> * temp = First;
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
void SinglyLL <T>:: Display()
{
    cout<<"Elements in LL are : "<<endl;
    struct node<T> * temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: CountNode()
{
    return count;
}

template <class T>
void SinglyLL <T>:: InsertAtPos(T no,int pos)
{
    int size = CountNode();
    struct node<T> * temp = First;
    struct node<T> * newn = NULL;

    if((pos < 1) || (pos > size+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
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
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    int size = CountNode();
    struct node<T>* temp = First;
    struct node<T>* TargetedNode = NULL;

    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == size)
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
int SinglyLL<T> :: SearchFirstOccurence(T no)
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
int SinglyLL<T> :: SearchLastOccurence(T no)
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
T SinglyLL<T> :: MaximumElement()
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
        }   
        return Max;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T SinglyLL<T> :: MinimumElement()
{
    struct node<T>* temp = First;
    T Min = 0;
     
    if(First != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data < Min)
            {
                Min = temp->data;
            }  
        }   
        return Min;    
    }
    else
    {
        return -1;
    }
}

template <class T>
T SinglyLL<T> :: SecondMaximumElement()
{
    struct node<T>* temp = First;
    T Max1 = 0, Max2 = 0;
     
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
T SinglyLL<T> :: SecondMinimumElement()
{
    struct node<T>* temp = First;
    T Min1 = 9999.99, Min2 = 0;
     
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