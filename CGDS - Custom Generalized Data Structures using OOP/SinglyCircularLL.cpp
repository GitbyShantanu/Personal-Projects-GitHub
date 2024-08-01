//Generic Singly Circular Linked List for all primitive datatypes.

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

int main()
{
    SinglyCL<int> iobj;
    SinglyCL<float> fobj;
    SinglyCL<double> dobj;
    SinglyCL<char> cobj;

    cout<<"\nSinglyCL of Integers : "<<endl;    
    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();

    cout<<"\nSinglyCL of Float : "<<endl;
    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);
    fobj.Display();

    cout<<"\nSinglyCL of Doubles : "<<"\n";
    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9932);
    dobj.Display();

    cout<<"\nSinglyCL of Characters : "<<"\n";
    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.Display();   

    return 0;
}