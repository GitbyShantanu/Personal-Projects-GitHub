# 🌟 Generic Data Structure Library in C++ 🌟

Welcome to the **Generic Data Structure Library**! This repository contains *generic* implementations of various linear data structures in C++ with custom functionalities to support all primitive data types.

## Overview
The following data structures are included in this library:

- **Array**
- **Singly Linear Linked List**
- **Singly Circular Linked List**
- **Doubly Linear Linked List**
- **Doubly Circular Linked List**
- **Stack**
- **Queue**

## Features
- **Array**
- `Accept`: Accepts the user defined elements.
- `Display`: Display the elements.
- `Addition`: Computes the sum of all elements.
- `Multiplication`: Computes the product of all elements.
- `Maximum`: Finds the maximum element.
- `Minimum`: Finds the minimum element.
- `Average`: Computes the average of all elements.
- `DisplayEven`: Displays all even elements.
- `DisplayOdd`: Displays all odd elements.
- `Reverse`: Reverses the order of elements.

Each data structure (except Array) supports the following common functionalities:
- `InsertFirst`: Inserts an element at the beginning of the structure.
- `InsertLast`: Inserts an element at the end of the structure.
- `DeleteFirst`: Removes the first element.
- `DeleteLast`: Removes the last element.
- `InsertAtPos`: Inserts an element at a specified position.
- `DeleteAtPos`: Removes an element from a specified position.
- `Display`: Displays all elements in the structure.
- `CountNode`: Returns the number of elements in the structure.

Additional customized functions include:
  - `SearchFirstOccurrence`: Searches for the first occurrence of a value.
  - `SearchLastOccurrence`: Searches for the last occurrence of a value.
  - `MaximumElement`: Finds the maximum element.
  - `MinimumElement`: Finds the minimum element.
  - `SecondMaximumElement`: Finds the second maximum element.
  - `SecondMinimumElement`: Finds the second minimum element.
  
## 🛠️ Installation

1. **Clone the repository:**
   git clone https://github.com/your-username/generic-data-structure-library.git

2. **Navigate to the project directory:**
cd generic-data-structure-library

3. **Compile the code using a C++ compiler :**
g++ -o main main.cpp

4. **Run the Program :**
Execute the compiled program:
./main

## 🚀 Example Usage for Array: 
Here's a quick example of how to use the Array :

#include <iostream>
using namespace std;

int main() {
    int Size = 0;
    cout << "Enter number of elements: ";
    cin >> Size;

    Array<float> fobj(Size);
    fobj.Accept();
    fobj.Display();

    float fRet = fobj.Addition();
    cout << "Sum of elements: " << fRet << endl;

    fobj.Reverse();
    cout << "After Reverse: " << endl;
    fobj.Display();

    return 0;
}

### 🚀 Example Usage for Singly Linked List (Same usage For remaining Linked lists, Stack and Queue)
Here's a quick example of how to use the Linked List:

#include <iostream>
using namespace std;

int main() {
    SinglyLL<int> iobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();

    int iRet = iobj.SecondMinimumElement();
    cout << iRet << endl;

    return 0;
}
