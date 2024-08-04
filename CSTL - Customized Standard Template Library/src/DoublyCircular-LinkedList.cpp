// Generic Doubly Circular Linked List using CSTL.

//include absolute path of related header file.
#include "...\CSTL\headers\Linked List\DoublyCircularLL.h"

#include<iostream>
using namespace std;

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