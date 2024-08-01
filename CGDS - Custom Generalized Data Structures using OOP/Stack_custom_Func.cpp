//Generic Stack for all primitive datatypes with customised functions.

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class Stack
{
    private:
        struct node <T> * First;
        int count;

    public:
        Stack();
        void Push(T no);
        T Pop();
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
Stack<T> :: Stack()
{
    First = NULL;
    count = 0;
}

template <class T>
void Stack<T> :: Push(T no)
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
        newn->next = First;
        First = newn;
    }
    count++;
}


template <class T>
void Stack<T> :: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements in Stack are : \n";
    if(First != NULL)
    {
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|\n";
            temp = temp->next;
        }
    }
    else 
    {
        cout<<"|NULL|\n";
    }
}

template <class T>
T Stack<T> :: Pop()
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
int Stack<T> :: CountNode()
{
    return count;
}

template <class T>
int Stack<T> :: SearchFirstOccurence(T no)
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
int Stack<T> :: SearchLastOccurence(T no)
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
T Stack<T> :: MaximumElement()
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
T Stack<T> :: MinimumElement()
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
T Stack<T> :: SecondMaximumElement()
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
T Stack<T> :: SecondMinimumElement()
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
    Stack<int> iobj;
    Stack<float> fobj;
    Stack<double> dobj;
    Stack<char> cobj;

    cout<<"\ninteger Stack : \n";
    iobj.Push(51);    
    iobj.Push(21);    
    iobj.Push(11);
    iobj.Display();

    cout<<"\nfloat Stack : \n";   
    fobj.Push(51.5);    
    fobj.Push(21.5);    
    fobj.Push(11.5);
    fobj.Display();

    cout<<"\ndouble Stack : \n";   
    dobj.Push(51.564);    
    dobj.Push(21.564);    
    dobj.Push(11.572);
    fobj.Display();

    cout<<"\ncharacter Stack : \n";
    cobj.Push('D');
    cobj.Push('C');    
    cobj.Push('B');    
    cobj.Push('A');    
    cobj.Display();

    return 0;
}