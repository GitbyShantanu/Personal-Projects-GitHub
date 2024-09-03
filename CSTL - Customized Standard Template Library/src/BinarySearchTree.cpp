// Generic Binary Search Tree using CSTL.

// Include the absolute path of the related header file.
#include "...\CSTL\headers\Trees\BinarySearchTree.h"

#include <iostream>
using namespace std;

int main()
{
    // Creating BST objects for different data types
    BinarySearchTree<int> iobj;
    BinarySearchTree<float> fobj;
    BinarySearchTree<double> dobj;
    BinarySearchTree<char> cobj;

    cout << "\nBinary Search Tree of Integers:\n";
    iobj.Insert(50);
    iobj.Insert(30);
    iobj.Insert(20);
    iobj.Insert(40);
    iobj.Insert(70);
    iobj.Insert(60);
    iobj.Insert(80);
    
    cout << "Inorder Traversal: ";
    iobj.Inorder();
    cout << "Preorder Traversal: ";
    iobj.Preorder();
    cout << "Postorder Traversal: ";
    iobj.Postorder();

    if (iobj.Search(30))
    {
        cout << "Element 30 found in the BST.\n";
    }
    else
    {
        cout << "Element 30 not found in the BST.\n";
    }

    cout << "Total Nodes: " << iobj.CountNode() << "\n";
    cout << "Leaf Nodes: " << iobj.CountLeaf() << "\n";
    cout << "Parent Nodes: " << iobj.CountParent() << "\n";
    cout << "Sum of all elements: " << iobj.Sum() << "\n";
    cout << "Count of Even elements: " << iobj.CountEven() << "\n";
    cout << "Count of Odd elements: " << iobj.CountOdd() << "\n";

    cout << "\nBinary Search Tree of Floats:\n";
    fobj.Insert(50.5);
    fobj.Insert(30.3);
    fobj.Insert(20.2);
    fobj.Insert(40.4);
    fobj.Insert(70.7);
    fobj.Insert(60.6);
    fobj.Insert(80.8);
    
    cout << "Inorder Traversal: ";
    fobj.Inorder();

    cout << "\nBinary Search Tree of Doubles:\n";
    dobj.Insert(50.5555);
    dobj.Insert(30.3333);
    dobj.Insert(20.2222);
    dobj.Insert(40.4444);
    dobj.Insert(70.7777);
    dobj.Insert(60.6666);
    dobj.Insert(80.8888);
    
    cout << "Inorder Traversal: ";
    dobj.Inorder();

    cout << "\nBinary Search Tree of Characters:\n";
    cobj.Insert('M');
    cobj.Insert('B');
    cobj.Insert('A');
    cobj.Insert('C');
    cobj.Insert('Z');
    cobj.Insert('Y');
    cobj.Insert('X');
    
    cout << "Inorder Traversal: ";
    cobj.Inorder();

    return 0;
}
