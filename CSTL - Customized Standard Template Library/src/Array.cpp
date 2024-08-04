// Generic Array using CSTL.

//include absolute path of related header file.
#include "...\CSTL\headers\arrays\Array.h" 

#include <iostream>
using namespace std;

int main()
{
    int Size = 0;

    cout<<"Enter number of elements : ";
    cin>>Size;

    Array<int> iobj(Size);
    int iRet = 0;

    iobj.Accept();
    iobj.Display();

    iRet = iobj.Addition();
    cout<<"Sum of elements : "<<iRet<<endl;

    iRet = iobj.Minimum();
    cout<<"Min : "<<iRet<<endl;

    return 0;
}