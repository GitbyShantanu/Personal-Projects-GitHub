
# 🌟 Customized Standard Template Library in C++ 🌟

Welcome to the **Customized Standard Template Library**! This repository contains *generic* implementations of various linear data structures in C++ with custom functionalities to support all primitive data types.

## Overview
The following data structures are included in this library:

- **Array**
- **Singly Linear Linked List**
- **Singly Circular Linked List**
- **Doubly Linear Linked List**
- **Doubly Circular Linked List**
- **Stack**
- **Queue**
- **Binary Search Tree**

## Features
### Array:
- `Accept`: Accepts the user-defined elements.
- `Display`: Displays the elements.

Custom functions support added for Array: 
- `Addition`: Computes the sum of all elements.
- `Multiplication`: Computes the product of all elements.
- `Maximum`: Finds the maximum element.
- `Minimum`: Finds the minimum element.
- `Average`: Computes the average of all elements.
- `DisplayEven`: Displays all even elements.
- `DisplayOdd`: Displays all odd elements.
- `Reverse`: Reverses the order of elements.

### Linked Lists
Supports the following common functionalities:
- `InsertFirst`: Inserts an element at the beginning of the structure.
- `InsertLast`: Inserts an element at the end of the structure.
- `DeleteFirst`: Removes the first element.
- `DeleteLast`: Removes the last element.
- `InsertAtPos`: Inserts an element at a specified position.
- `DeleteAtPos`: Removes an element from a specified position.
- `Display`: Displays all elements in the structure.
- `CountNode`: Returns the number of elements in the structure.

### Stack
Supports the following regular functionalities:
- `Push`: Inserts an element in the stack.
- `Pop`: Removes the recently added element (LIFO).
- `Display`: Displays all elements in the stack.
- `CountNode`: Returns the number of elements in the stack.

### Queue
Supports the following regular functionalities:
- `Enqueue`: Inserts an element in the queue.
- `Dequeue`: Removes the element which came first (FCFS).
- `Display`: Displays all elements in the queue.
- `CountNode`: Returns the number of elements in the queue.

### Binary Search Tree
Supports the following functionalities:
- `Insert`: Inserts an element in the BST.
- `Search`: Searches for an element in the BST.
- `Inorder`: Displays elements in ascending order.
- `Preorder`: Displays elements in pre-order traversal.
- `Postorder`: Displays elements in post-order traversal.
- `CountNode`: Returns the number of nodes in the BST.
- `CountLeaf`: Returns the number of leaf nodes.
- `CountParent`: Returns the number of parent nodes.
- `Sum`: Computes the sum of all elements.
- `CountEven`: Counts the number of even elements.
- `CountOdd`: Counts the number of odd elements.

Additional customized functions include (for all linear data structures except Array):
- `SearchFirstOccurrence`: Searches for the first occurrence of a value.
- `SearchLastOccurrence`: Searches for the last occurrence of a value.
- `MaximumElement`: Finds the maximum element.
- `MinimumElement`: Finds the minimum element.
- `SecondMaximumElement`: Finds the second maximum element.
- `SecondMinimumElement`: Finds the second minimum element.

 ## Use Cases & Real-World Applications  

This **Customized Standard Template Library (CSTL)** isn't just an academic exercise — its applications extend to **real-world scenarios**, making it a powerful tool in **system-level programming**.

### 💡 Applications  

👉 **Database Indexing**  
The **BST implementation** can be used for **efficient indexing** in databases, allowing quick searches, inserts, and deletions.  
It supports optimized search performance similar to **B-Trees** widely used in database management systems.  

👉 **Memory Management System**  
**Linked Lists** can manage dynamic memory allocation using **Free List Management**.  
Custom **Stack and Queue** structures can simulate memory paging and scheduling algorithms in **Operating Systems**.  

👉 **Compiler Design Modules**  
**Stacks** are essential in **expression evaluation** and **syntax parsing** during the compilation process.  
**Queues** help in **lexical analysis** for token processing.  
**BST** structures manage **symbol tables** for variable and function storage.  

👉 **IoT Data Logging System**  
**Queues and Linked Lists** can handle **real-time sensor data streams** efficiently.  
**Stacks** provide **rollback mechanisms** to recover recent operations.  
Optimized **search and sorting algorithms** can process IoT data before storage or transmission.  

These use cases highlight the library's versatility, making it a **practical addition to system-level projects and real-time applications**.

## 🚀 Example Usage for Array

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

## 🚀 Example Usage for Singly Linked List (Same usage for remaining Linked Lists)

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

## 🚀 Example Usage for Stack

```cpp
#include<iostream>
using namespace std;

int main()
{
    Stack<int> iobj;
    iobj.Push(51);    
    iobj.Push(21);    
    iobj.Push(11);
    iobj.Display();

    return 0;
}
```

## 🚀 Example Usage for Queue

```cpp
#include<iostream>
using namespace std;

int main()
{
    Queue<int> iobj;
    iobj.Enqueue(11);
    iobj.Enqueue(21);    
    iobj.Enqueue(51);
    iobj.Display();

    return 0;
}
```

## 🚀 Example Usage for Binary Search Tree

```cpp
#include <iostream>
using namespace std;

int main()
{
    BinarySearchTree<int> iobj;
    iobj.Insert(50);
    iobj.Insert(30);
    iobj.Insert(20);
    iobj.Insert(70);
    iobj.Inorder();

    cout << "Element 30 " << (iobj.Search(30) ? "found" : "not found") << " in the BST.\n";
    cout << "Total Nodes: " << iobj.CountNode() << "\n";

    return 0;
}
```

## 🛠️ How to Run / Use:

1. **Navigate to the project directory:**
```bash
cd Customized-Standard-Template-library
```

2. **Compile the code using a C++ compiler:**
```bash
g++ main.cpp -o main
```

3. **Run the Program:**
Execute the compiled program: 
```bash
./main
```

## 📲 Contact:
For any questions or feedback, please contact **deshshantanu05@gmail.com**.
 
