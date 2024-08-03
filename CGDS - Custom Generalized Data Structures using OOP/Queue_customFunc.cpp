//Generic Queue for all primitive datatypes with customised functions.

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class Queue
{
    private:
        struct node <T> * First;
        int count;

    public:
        Queue();
        void Enqueue(T no);
        T Dequeue();
        void Display();
        int CountNode();

        // customized functions below...
        int SearchFirstOccurence(T no);
        int SearchLastOccurence(T no);
        T MaximumElement();
        T MinimumElement();
        T SecondMaximumElement();
        T SecondMinimumElement();
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    count = 0;
}

template <class T>
void Queue<T> :: Enqueue(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> *temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    count++;
}

template <class T>
T Queue<T> :: Dequeue()
{
    struct node<T> * temp = First;
    T value = 0;
    if(First == NULL)
    {
        return value;
    }
    else if(First->next == NULL)
    {
        value = temp->data;
        delete First;
        First = NULL;
    }
    else
    {
        value = temp->data;
        First = First->next;
        delete temp;
    }
    return value;
}

template <class T>
void Queue<T> :: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements in Stack are : \n";
    if(First != NULL)
    {
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"| ";
            temp = temp->next;
        }
        cout<<endl;
    }
    else 
    {
        cout<<"|NULL|\n";
    }
}

template <class T>
int Queue<T> :: CountNode()
{
    return count;
}

template <class T>
int Queue<T> :: SearchFirstOccurence(T no)
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
int Queue<T> :: SearchLastOccurence(T no)
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
T Queue<T> :: MaximumElement()
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
T Queue<T> :: MinimumElement()
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
T Queue<T> :: SecondMaximumElement()
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
T Queue<T> :: SecondMinimumElement()
{
    struct node<T>* temp = First;
    T Min1 = 99.9999, Min2 = 0;
     
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

int main()
{
    Queue<int> iobj;
    Queue<float> fobj;
    Queue<double> dobj;
    Queue<char> cobj;

    cout<<"\ninteger Queue : \n";
    iobj.Enqueue(11);
    iobj.Enqueue(21);    
    iobj.Enqueue(51);    
    iobj.Display();

    cout<<"\nfloat Queue : \n";   
    fobj.Enqueue(11.5);
    fobj.Enqueue(21.5);    
    fobj.Enqueue(51.5);    
    fobj.Display();

    cout<<"\ndouble Queue : \n";   
    dobj.Enqueue(11.572);
    dobj.Enqueue(21.564);    
    dobj.Enqueue(51.564);    
    fobj.Display();

    cout<<"\ncharacter Queue : \n";
    cobj.Enqueue('A');    
    cobj.Enqueue('B');    
    cobj.Enqueue('C');    
    cobj.Enqueue('D');
    cobj.Display();

    return 0;
}