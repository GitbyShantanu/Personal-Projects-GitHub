// Generic Queue using CSTL. 

//include absolute path of related header file.
#include "...\CSTL\headers\Queue\Queue.h"

#include<iostream>
using namespace std;

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