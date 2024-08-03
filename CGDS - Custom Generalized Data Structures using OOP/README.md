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
Array:
- `Accept`: Accepts the user defined elements.
- `Display`: Display the elements.

Custom functions support added for Array: 
- `Addition`: Computes the sum of all elements.
- `Multiplication`: Computes the product of all elements.
- `Maximum`: Finds the maximum element.
- `Minimum`: Finds the minimum element.
- `Average`: Computes the average of all elements.
- `DisplayEven`: Displays all even elements.
- `DisplayOdd`: Displays all odd elements.
- `Reverse`: Reverses the order of elements.

Linked Lists supports the following common functionalities:
- `InsertFirst`: Inserts an element at the beginning of the structure.
- `InsertLast`: Inserts an element at the end of the structure.
- `DeleteFirst`: Removes the first element.
- `DeleteLast`: Removes the last element.
- `InsertAtPos`: Inserts an element at a specified position.
- `DeleteAtPos`: Removes an element from a specified position.
- `Display`: Displays all elements in the structure.
- `CountNode`: Returns the number of elements in the structure.

Stack supports the following regular functionalities:
- `Push`: Inserts an element in stack.
- `Pop`: Removes the recently added element (LIFO).
- `Display`: Displays all elements in the Stack.
- `CountNode`: Returns the number of elements in the Stack.

Queue supports the following regular functionalities:
- `Enqueue`: Inserts an element in Queue.
- `Dequeue`: Removes the element which came first (FCFS).
- `Display`: Displays all elements in the Queue.
- `CountNode`: Returns the number of elements in the Queue.

Additional customized functions includes (for all linear data structures except Array):
  - `SearchFirstOccurrence`: Searches for the first occurrence of a value.
  - `SearchLastOccurrence`: Searches for the last occurrence of a value.
  - `MaximumElement`: Finds the maximum element.
  - `MinimumElement`: Finds the minimum element.
  - `SecondMaximumElement`: Finds the second maximum element.
  - `SecondMinimumElement`: Finds the second minimum element.
  
## 🛠️ Installation

1. **Clone the repository:**
git clone  https://github.com/GitbyShantanu/Personal-Projects-GitHub/tree/main/CGDS%20-%20Custom%20Generalized%20Data%20Structures%20using%20OOP

2. **Navigate to the project directory:**
cd  generic-data-structure-library

4. **Compile the code using a C++ compiler :**
g++  main.cpp  -o  main 

5. **Run the Program :**
Execute the compiled program:  ./ main



## 🚀 Example Usage for Array:

```cpp
#include<iostream>
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
    cout << "After Reverse:" << endl;
    fobj.Display();

    return 0;
}
```


### 🚀 Example Usage for Singly Linked List (Same usage For remaining Linked lists, Stack and Queue)

```cpp
#include<iostream>
using namespace std;

int main()
{
    SinglyLL<int> iobj;
    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);
    iobj.Display();
    
    int iRet = iobj.SecondMinimumElement();
    cout << "Second Minimum Element: " << iRet << endl;

    return 0;
}
```

### 📲 Contact: 
For any questions or feedback, please contact **deshshantanu05@gmail.com**.
