//Generic Array for all numeric datatypes (int,float,double) with customised functions.

#include<iostream>
using namespace std;

template<class T>

class Array
{
    private: 
        T * Arr;
        int iSize;

    public:
        Array(int X);
        ~Array();
        void Accept();
        void Display();

        // customized functions below...
        T Addition();
        T Multiplication();
        T Maximum();
        T Minimum();
        float Average();
        void DisplayEven();
        void DisplayOdd();
        void Reverse();
};

template<class T>
Array<T>:: Array(int X)
{
    this->iSize = X;
    this->Arr = new T[iSize];
}

template<class T>
Array<T>:: ~Array()
{
    delete [] Arr;
}

template<class T>
void Array<T>:: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template<class T>
void Array<T>:: Display()
{
    cout<<"Elements of Array are  : \n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<endl;
}

template<class T>
T Array<T>:: Addition()
{
    T Sum = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        Sum = Sum + Arr[iCnt];
    }
    return Sum;
}

template<class T>
T Array<T>:: Multiplication()
{
    int Mult = 1;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        Mult = Mult * Arr[iCnt];
    }
    return (int)Mult;
}

template<class T>
void Array<T>:: DisplayEven()
{
    cout<<"Even Elements in array are : \n";
    int iCnt = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if((Arr[iCnt] % 2)== 0)
        {
            cout<<Arr[iCnt]<<"\t";
        }
    }
}

template<class T>
void Array<T>:: DisplayOdd()
{
    cout<<"Odd Elements in array are : \n";
    int iCnt = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if((Arr[iCnt] % 2) != 0)
        {
            cout<<Arr[iCnt]<<"\t";
        }
    }
}

template <class T>
T Array<T> :: Maximum()
{
    int iCnt = 0;
    T Max = Arr[0]; 

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > Max)
        {
            Max = Arr[iCnt];
        }
    }
    return Max;
}

template <class T>
T Array<T> :: Minimum()
{
    int iCnt = 0;
    T Min = Arr[0]; 

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > Min)
        {
            Min = Arr[iCnt];
        }
    }
    return Min;
}

template <class T>
float Array<T> :: Average()
{
    int iCnt = 0;
    T Sum = 0;
    float fAvg = 0.0f;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        Sum = Sum + Arr[iCnt];
    }

    fAvg = ((float)Sum /(float)iSize);
    return fAvg;
}

template <class T>
void Array<T> :: Reverse()
{   
    int i = 0,j = 0;
    for(i = 0,j = iSize-1; i < j; i++,j--)
    {
        T Temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = Temp;
    }
}

int main()
{
    int Size = 0;

    cout<<"Enter number of elements : ";
    cin>>Size;

    Array<float> fobj(Size);

    float fRet = 0.0f;
    fobj.Accept();
    fobj.Display();

    fRet = fobj.Addition();
    cout<<"Sum of elements : "<<fRet<<endl;

    fobj.Reverse();
    cout<<"After Reverse : "<<endl;
    fobj.Display();

    return 0;
}