// Generic Singly Linear Linked List using CSTL.

//include absolute path of related header file.
#include "...\CSTL\headers\Linked List\SinglyLinearLL.h"

#include <iostream>
using namespace std;

int main()
{   
    SinglyLL <int>iobj;
    SinglyLL <float>fobj;
    SinglyLL <double>dobj;
    SinglyLL <char>cobj;

    cout<<"\nLinkedList of Integers : "<<"\n";
    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();

    int iRet = iobj.SecondMinimumElement();
    cout<<"Second Minimum element is : "<<iRet<<endl;

    cout<<"\nLinkedList of Floats : "<<"\n";
    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);
    fobj.Display();

    cout<<"\nLinkedList of Doubles : "<<"\n";
    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);
    dobj.Display();

    cout<<"\nLinkedList of Characters : "<<"\n";
    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');
    cobj.Display();

    return 0;
}