#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED
#include<iostream>
using namespace std;
struct Node {
    float value;
    struct Node *next=NULL;
    struct Node *prev=NULL;
};
template <typename T>
class DoubleLinkedList {
public:
int size;
Node *first;
Node *last;
public:
DoubleLinkedList();
DoubleLinkedList(const DoubleLinkedList* DLL);
~DoubleLinkedList();
bool insertLast(T value);
bool insertFirst (T value);
bool insertAtPos(int pos, T value);
bool deleteLast();
bool deleteFirst();
bool deleteAtPos(int pos);
bool clr ();
const T getLast() const;
const T getFirst()const;
bool isContains(T value);
bool isEmpty();
const int getSize() const;
DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& DLL);
friend ostream& operator<< (ostream &out, const DoubleLinkedList<int>& DLL);
    };

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    size=0;
    first=NULL;
    last=NULL;
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList* DLL)
{
    size=0;
    first=NULL;
    last=NULL;
    if (DLL->size>0)
    {
        Node *tmp=DLL->first;
        while (tmp!=NULL)
        {

        insertLast(tmp->value);
        tmp=tmp->next;
        }
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
clr();
}

template <typename T>
bool DoubleLinkedList<T>::insertLast(T value)
{
    Node *tmp= new Node;
    if(first==NULL)
    {

        tmp->value=value;
        tmp->next=NULL;
        tmp->prev=NULL;
        first=tmp;
        last=tmp;
    }
    else
    {
        tmp->next=NULL;
        tmp->prev=last;
        tmp->value=value;
        last->next=tmp;
        last=tmp;
    }
    size++;
    return true;
};

template <typename T>
bool DoubleLinkedList<T>::insertFirst (T value)
{
     Node *tmp= new Node;
    if ( first==NULL)

    {
        tmp->value=value;
        tmp->next=NULL;
        tmp->prev=NULL;
        first=tmp;
        last=tmp;
    }
    else
        {
        tmp->next=first;
        tmp->prev=NULL;
        tmp->value=value;
        first->prev=tmp;
        first=tmp;
    }
    size++;
    return true;
};

template <typename T>
bool DoubleLinkedList<T>::insertAtPos(int pos, T value)
{

    if (pos<1||pos>size+1) return false;
    if (pos==1)
    {
        insertFirst(value);
        return true;
    }
    else if(pos==size+1)
    {
        insertLast(value);
        return true;
    }
    else
    {
        int i=1;
        Node *tmp1=first;
        while (i<=size)
        {
            i++;
            tmp1=tmp1->next;
            if (i==pos-1)
            {
                Node *tmp2=new Node;
                tmp2->prev=tmp1;
                tmp2->next=tmp1->next;
                tmp1->next=tmp2;
                tmp1=tmp2->next;
                tmp1->prev=tmp2;
                tmp2->value=value;
                size++;
                break;
            }
        }
        return true;
    }
}

template <typename T>
bool DoubleLinkedList<T>::deleteLast()
{
    if (size<1) return false;
    else if (size==1)
    {
        delete first;
        first=NULL;
        last=NULL;
        size--;
        return true;
    }
    Node *tmp=last;
    last=last->prev;
    last->next=NULL;
    delete tmp;
    size--;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteFirst()
{
    if (size<1) return false;
    else if (size==1)
    {
        delete first;
        first=NULL;
        last=NULL;
        size--;
        return true;
    }
    Node *tmp=first;
    first=first->next;
    first->prev=NULL;
    delete tmp;
    size--;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteAtPos(int pos)
{

    if (pos<1||pos>size) return false;
    if (pos==1)
    {
        deleteFirst();
        return true;
    }
    else if(pos==size)
    {
        deleteLast();
        return true;
    }
    else
    {
        int i=1;
        Node *tmp1=first;
        Node *tmp2;
        while (i<=size)
        {
            i++;
            tmp1=tmp1->next;
            if (i==pos-1)
            {
                tmp2=tmp1->next;
                tmp1->next=tmp2->next;
                tmp1=tmp2->next;
                tmp1->prev=tmp2->prev;
                delete tmp2;
                size--;
                break;
            }
        }
        return true;
    }
}

template <typename T>
bool DoubleLinkedList<T>::clr()
{
    if (size<1) return false;
    Node *tmp1=first->next;
    Node *tmp2;
    delete first;
    size--;
    while (tmp1!=NULL)
    {
        tmp2=tmp1;
        tmp1=tmp1->next;
        delete tmp2;
        size--;
    }
    return true;
}

template <typename T>
const T DoubleLinkedList<T>::getLast() const
{
    return last->value;
}

template <typename T>
const T DoubleLinkedList<T>::getFirst() const{
return first->value;
}

template <typename T>
bool DoubleLinkedList<T>::isContains(T value)
{
    if (size<1) return false;
    Node *tmp=first;
    while(tmp!=NULL)
    {
        if (tmp->value==value) return true;
        tmp=tmp->next;
    }
    return false;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
    if (size>0) return true;
    else return false;
}

template <typename T>
const int DoubleLinkedList<T>::getSize() const
{
    return  size;
};

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& DLL)
{
    size=0;
    first=NULL;
    last=NULL;
    if (DLL.size>0)
    {
        Node *tmp=DLL.first;
        while (tmp!=NULL)
        {

        insertLast(tmp->value);
        tmp=tmp->next;
        }
    }
}


ostream& operator<< (ostream &out, const DoubleLinkedList<float>& DLL)
{

        if (DLL.getSize()>0)
    {
        Node *tmp;
        tmp=DLL.first;
        for(int i=1;i<=DLL.getSize();i++)
        {
            cout<<tmp->value<<" ";
            tmp=tmp->next;
        }
        tmp=NULL;
    }
    else cout<<"\nError\n";
}


#endif // TEMPLATE_H_INCLUDED
