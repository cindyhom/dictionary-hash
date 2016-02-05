//
//  DLL.h
//  DataStruct_Project1
//
//  Created by Cindy Hom on 9/19/15.
//  Copyright © 2015 Cindy Hom. All rights reserved.
//

#ifndef DLL_h
#define DLL_h

#include <iostream>
#include <string>
#include <new>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;



/*****************************************************
 *                                                   *
 *              class Node definition                *
 *                                                   *
 *****************************************************/

template <typename T>
struct Node
{
    T info;
    //info of type T for each Node
    
    Node<T> *prev;
    
    Node<T> *next;
    //pointer that points to next Node of type T
    
    Node();
    
    Node(T a, Node<T> *ptr = NULL, Node<T> *ptr2 = NULL);
    //constructor with parameters
    //Postcondition: Initializes each member variable of Node
};



/*****************************************************
 *                                                   *
 *       class Node implementation details           *
 *                                                   *
 *****************************************************/


template <typename T>
Node<T>::Node()
{
    next = NULL;
    prev = NULL;
}




template <typename T>
Node<T>::Node(T a, Node<T> *ptr, Node<T> *ptr2)
{
    info = a;
    next = ptr;
    prev = ptr2;
    
}//END constructor with parameters for Node class




/*****************************************************
 *                                                   *
 *              class DLL definition                 *
 *                                                   *
 *****************************************************/

template <typename T>
class DLL
{
private:
    int count;
    // count of Nodes
    
    Node<T> *sentinel;
    //sentinel->next points to the start of list
    //sentinel->prev points to the end of the list
    
    void copyList(const DLL<T> &listToCopy);
    //Function to copy contents of one LL to another
    //Postcondition: deep copy of listToCopy is created
    
public:
    DLL();
    //constructor
    
    DLL(const DLL<T> &otherLL);
    //copy constructor
    //Postcondition: deep copy of otherLL is created
    
    ~DLL();
    //destructor
    
    void push_back(T rhsObj);
    //inserts Node at the end of LL
    
    void push_front(T rhsObj);
    //inserts Node at the beginning of LL
    
    void pop_back();
    //deletes last Node of LL
    
    void clear();
    //removes all Nodes in LL
    
    int size() const;
    //returns size of LL
    
    bool isEmpty();
    
    T& at(int ndx);
    //gets info of Node at specific index
    //Postcondition: Returns reference to info of Node
    //at a specific index
    
    T& operator[](int ndx);
    //gets info of Node at specific index
    //Postcondition: Returns reference to info of Node
    //at a specific index
    
    T& at(int ndx) const;
    //gets info of Node at specific index
    //Postcondition: Returns reference to info of Node
    //at a specific index
    
    T& operator[](int ndx) const;
    //gets info of Node at specific index
    //Postcondition: Returns reference to info of Node
    //at a specific index
    
    const DLL& operator=(const DLL<T> &rhsObj);
    //overloaded assignment operator
    
    void rearrange();
    //bubble sort
    
    void display();
    //displays info
    
    void removeItem(T &obj);
    
    bool lookFor(T &obj);
    
};





/*****************************************************
 *                                                   *
 *       class DLL implementation details            *
 *                                                   *
 *****************************************************/

template <typename T>
void DLL<T>::copyList(const DLL<T> &listToCopy)
{
    int nodesToCopy = listToCopy.count;
//    cout << "Preparing to copy " << nodesToCopy << " objects from right hand ";
//    cout << "DLL object \n to left hand DLL object\n";
    
    Node<T> *current = sentinel->next;
    
    count = 0;
    
    Node<T> *otherCurrent = listToCopy.sentinel->next;
    while (otherCurrent != listToCopy.sentinel)
    {
//        cout << "in while" << endl;
        push_back(otherCurrent->info);
        otherCurrent = otherCurrent->next;
    }
//    cout << "Exiting DLL::copyList(const LL<T> &otherLL) " << endl;
}//END function copyList



template <typename T>
DLL<T>::DLL()
{
//    cout << "Entered constructor DLL<T>::DLL()\n";
    
    count = 0;
    
    sentinel = new Node<T>();
    //initializes sentinel to point to itself since list is empty
    
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
//    
//    cout << "Exiting constructor DLL<T>::DLL()\n";
}//END constructor for DLL class



template <typename T>
DLL<T>::DLL(const DLL<T> &otherLL)
{
    cout << "Entered copy constructor DLL<T>::DLL(const DLL<T> &otherLL)\n";
    
    
    count = 0;
    
    sentinel = new Node<T>();
    //initializes sentinel to point to itself since list is empty
    
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    
    copyList(otherLL);
    
    cout << "Exiting copy constructor DLL<T>::DLL(const DLL<T> &otherLL)\n";
}//END copy constructor for DLL class




template <typename T>
DLL<T>::~DLL()
{
//    cout << "Entered destructor DLL<T>::~DLL()\n";
    
    clear();
    
//    cout << "Exiting destructor DLL<T>::~DLL()\n";
}//END destructor for LL class




template <typename T>
void DLL<T>::push_back(T rhsObj)
{
    try
    {
        Node<T> *addMe = new Node<T>(rhsObj);
        Node<T> *current;
        //creates Node to be added to the end of the list
        
        current = sentinel->next;
        
        if (isEmpty())
        {
            sentinel->next = addMe;
            addMe->prev = sentinel;
            
            sentinel->prev = addMe;
            addMe->next = sentinel;
        }
        
        else
        {
            while(current->next != sentinel)
            {
                current = current->next;
            }
            
            current->next = addMe;
            addMe->prev = current;
            
            addMe->next = sentinel;
            sentinel->prev = addMe;
            
        }
        
        count++;
        
    }
    catch(std::bad_alloc ba)
    {
        throw ba;
        //rethrows exception
    }
}//END function push_back



template <typename T>
void DLL<T>::push_front(T rhsObj)
{
    try
    {
        Node<T> *addMe = new Node<T>(rhsObj, sentinel->next);
        //creates Node to be added to the front of the list
        
        Node<T> *current;
        
        current = sentinel->next;
        
        if (isEmpty())
        {
            sentinel->next = addMe;
            addMe->prev = sentinel;
            
            sentinel->prev = addMe;
            addMe->next = sentinel;
        }
        else
        {
            sentinel->next = addMe;
            addMe->prev = sentinel;
            
            addMe->next = current;
            current->prev = addMe;
        }
        
        count++;
    }
    catch(std::bad_alloc ba)
    {
        throw ba;
        //rethrows exception
    }
}//END function push_front



template <typename T>
void DLL<T>::pop_back()
{
    Node<T> *current;
    Node<T> *temp;
    
    current = sentinel->next;
    
    if (isEmpty())
    {
        cout << "Nothing here. List is empty.";
    }
    else
    {
        while (current->next != sentinel)
        {
            current = current->next;
        }
        temp = current->prev;
        temp->next = sentinel;
        sentinel->prev = temp;
        
        delete current;
        current = temp;
        
    }
    count--;
    
}//END function pop_back



template <typename T>
int DLL<T>::size() const
{
    return count;
}//END function size




template <typename T>
void DLL<T>::clear()
{
    Node<T> *current;
    
    current = sentinel->next;
    
    
    if (isEmpty())
    {
        cout << "List is already empty, nothing to do here.\n" << endl;
    }
    else
    {
//        cout << "Removing all " << size() << " nodes from the list.\n";
        
        int deleteCount = 0;
        
        while (current != sentinel)
        {
            //deletes Nodes in the list from beginning to end
            sentinel->next = current->next;
            current->next->prev = sentinel;
            delete current;
            deleteCount++;
            count--;
            current = sentinel->next;
        }
//        cout << deleteCount << " nodes were deallocated and removed from the list.\n\n";
    }
}//END function clear



template <typename T>
bool DLL<T>::isEmpty()
{
    bool empty = false;
    
    Node<T> *current;
    current = sentinel->next;
    
    if(current == sentinel)
    {
        bool empty = true;
    }
    return empty;
}


template <typename T>
T& DLL<T>::at(int ndx)
{
    try
    {
        if(ndx < 0 || ndx >= count || isEmpty())
        {
            string outOfBounds = "Index entered is out of bounds\n ";
            throw outOfBounds;
        }
        
        Node<T> *current = sentinel->next;
        
        for (int i = 0; i < ndx; i++)
        {
            current = current->next;
        }
        
        return current->info;
        //returns Node info at specific index
        
    }
    catch(string ndxErr)
    {
        throw ndxErr;
    }
}//END function at


template <typename T>
T& DLL<T>::operator[](int ndx)
{
    return at(ndx);
}//END function operator[]




template <typename T>
T& DLL<T>::at(int ndx) const
{
    try
    {
        if(ndx < 0 || ndx >= count || isEmpty())
        {
            string outOfBounds = "Index entered is out of bounds\n ";
            throw outOfBounds;
        }
        
        Node<T> *current = sentinel->next;
        
        for (int i = 0; i < ndx; i++)
        {
            current = current->next;
        }
        
        return current->info;
        //returns Node info at specific index
        
    }
    catch(string ndxErr)
    {
        throw ndxErr;
    }
    
}//END function at


template <typename T>
T& DLL<T>::operator[](int ndx) const
{
    return at(ndx);
}//END function operator[]



template <typename T>
const DLL<T>& DLL<T>::operator=(const DLL<T> &rhsObj)
{
    if (this != &rhsObj)
    {
        //NOT self-assignment
        this->clear();
        copyList(rhsObj);
    }
    return *this;
}//END function operator=




template <typename T>
void DLL<T>::rearrange()
{
    //bubble sort to rearrange order
    int swapCount = 0;
    
    T temp;
    int i;
    int j;
    
    for (i = 1; i < size(); i++)
    {
        for (j = 0; j < size() - i; j++)
        {
            //if current element is less than next element, swap
            if (at(j) < at(j + 1))
            {
                temp = at(j);
                at(j) = at(j + 1);
                at(j + 1) = temp;
                swapCount++;
            }
        }
    }
    
}


template <typename T>
void DLL<T>::display()
{
    //traverses the list to display the coefficients and exponents
    Node<T> * current = sentinel->next;
    
    while (current != sentinel)
    {
        cout << current->info << endl;
        current = current->next;
    }
    
}



template <typename T>
void DLL<T>::removeItem(T &obj)
{
    if (isEmpty())
    {
        cout << "Nothing to delete since list is empty. " << endl;
    }
    else
    {
        Node<T> *current = sentinel->next;
        
        while(current->info != obj)
        {
            current = current->next;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        delete current;
    }
}



template <typename T>
bool DLL<T>::lookFor(T &obj)
{
    bool found = false;
    
    Node<T> *current = sentinel->next;
    
    //traverses the list and sees if the obj is in the list
    while(current != sentinel && found == false)
    {
        if(current->info == obj)
            found = true;
        current = current->next;
    }
    
    return found;
    
}


#endif /* DLL_h */
