using namespace std;
#include "template.h"

DoubleLinkedList::DoubleLinkedList()
{
    size=0;
    first=NULL;
    last=NULL;
};
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList* DLL)
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
DoubleLinkedList::~DoubleLinkedList()
{
clr();
}
bool DoubleLinkedList::insertLast(int value)
{
    Node *tmp=(Node*) new Node*;
    if ( first!=NULL)
    {
        tmp->next=NULL;
        tmp->prev=last;
        tmp->value=value;
        last->next=tmp;
        last=tmp;
    }
    else
    {
        tmp->value=value;
        first=tmp;
        last=tmp;
    }
    size++;
    return true;
};
bool DoubleLinkedList::insertFirst (int value)
{
    Node *tmp=(Node*) new Node*;
    if ( first!=NULL)
    {
        tmp->next=first;
        tmp->prev=NULL;
        tmp->value=value;
        first->prev=tmp;
        first=tmp;
    }
    else
    {
        tmp->value=value;
        first=tmp;
        last=tmp;
    }
    size++;
    return true;
};
bool DoubleLinkedList::insertAtPos(int pos, int value)
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
                Node *tmp2=(Node*) new Node*;
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
bool DoubleLinkedList::deleteLast()
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
bool DoubleLinkedList::deleteFirst()
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
bool DoubleLinkedList::deleteAtPos(int pos)
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
bool DoubleLinkedList::clr()
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
const int DoubleLinkedList::getLast() const
{
    return last->value;
}
const int DoubleLinkedList::getFirst() const{
return first->value;
}
bool DoubleLinkedList::isContains(int value)
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
bool DoubleLinkedList::isEmpty()
{
    if (size>0) return true;
    else return false;
}
const size_t DoubleLinkedList::getSize() const
{
    return  size;
};

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& DLL)
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
std::ostream& operator<< (std::ostream &out, const DoubleLinkedList& DLL)
{
    if (DLL.size>0)
    {
        cout<<endl;
        Node *tmp=DLL.first;
        while (tmp!=NULL)
        {
            cout<<tmp->value<<" ";
            tmp=tmp->next;
        }
    }
    else cout<<"\nError\n";
}
