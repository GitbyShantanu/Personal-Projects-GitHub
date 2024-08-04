//Generic Stack using CSTL.

//include absolute path of related header file.
#include "...\CSTL\headers\Stack\Stack.h"

#include<iostream>
using namespace std;

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
    dobj.Push(51.5648);    
    dobj.Push(21.5646);    
    dobj.Push(11.5725);
    fobj.Display();

    cout<<"\ncharacter Stack : \n";
    cobj.Push('D');
    cobj.Push('C');    
    cobj.Push('B');    
    cobj.Push('A');    
    cobj.Display();

    return 0;
}