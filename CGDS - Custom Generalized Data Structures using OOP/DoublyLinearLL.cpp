//Generic Doubly Linear Linked List for all primitive datatypes.

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

int main()
{
    DoublyLL<int> iobj;
    DoublyLL<float> fobj;
    DoublyLL<double> dobj;
    DoublyLL<char> cobj;

    cout<<"\nDoublyLL of Integers : "<<endl;    
    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();

    cout<<"\nDoublyLL of Float : "<<endl;
    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);
    fobj.Display();

    cout<<"\nDoublyLL of Doubles : "<<"\n";
    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.99);
    dobj.Display();

    cout<<"\nDoublyLL of Characters : "<<"\n";
    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.Display();

    return 0;
}