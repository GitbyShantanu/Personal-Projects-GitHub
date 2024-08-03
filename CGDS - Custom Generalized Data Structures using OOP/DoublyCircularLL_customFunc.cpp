//Generic Doubly Circular Linked List for all primitive datatypes.

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
class DoublyCL
{
    private:
        struct node<T> *First;
        struct node<T> *Last;
        int count;

    public:
        DoublyCL();
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
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    count = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    count++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;    
    count++;
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL)
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
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
    count--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL)
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
        Last = Last->prev;
        delete First->prev;
        Last->next = First;
        First->prev = Last;
    }
    count--;
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements in LL are : \n<=> ";
    if((First != NULL) && (Last != NULL))
    {
        do 
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }
        while(temp != Last->next);
        cout<<"First Node \n";
    }
}

template <class T>
int DoublyCL<T> :: CountNode()
{
    return count;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no,int pos)
{
    struct node<T> * temp = First;
    int Size = CountNode();

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
        struct node<T> *newn = new struct node<T>;
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
void DoublyCL<T> :: DeleteAtPos(int pos)
{
    struct node<T> * temp = First;
    struct node<T> * TargetedNode = NULL;
    int Size = CountNode();

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
        TargetedNode->next->prev = temp;
        delete TargetedNode;
    }
    count--;
}

template <class T>
int DoublyCL<T> :: SearchFirstOccurence(T no)
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
int DoublyCL<T> :: SearchLastOccurence(T no)
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
T DoublyCL<T> :: MaximumElement()
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
T DoublyCL<T> :: MinimumElement()
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
T DoublyCL<T> :: SecondMaximumElement()
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
T DoublyCL<T> :: SecondMinimumElement()
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

int main()
{
    DoublyCL<int> iobj;
    DoublyCL<float> fobj;
    DoublyCL<double> dobj;
    DoublyCL<char> cobj;

    cout<<"\nDoublyCL of Integers : "<<endl;    
    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();

    cout<<"\nDoublyCL of Float : "<<endl;
    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);
    fobj.Display();

    cout<<"\nDoublyCL of Doubles : "<<"\n";
    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9932);
    dobj.Display();

    cout<<"\nDoublyCL of Characters : "<<"\n";
    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.Display();

    return 0;
}