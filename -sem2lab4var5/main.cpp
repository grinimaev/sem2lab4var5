#include <iostream>
#include "template.h"
using namespace std;



int main()
{
//    int ans;
//    setlocale(0,"");
//    DoubleLinkedList<int> list1;
//     //ostream& operator<< (ostream &out, const DoubleLinkedList<int>& DLL);
//  int value; // указываем тоже самое, что и строкой выше
//while (1)
//{
//system("cls");
//cout<<"Список: "<<list1<<"Size: "<<list1.getSize()<<endl;
//cout<<"\nМеню:\n1 - insertLast\n";
//cout<<"2 - insertFirst\n";
//cout<<"3 - insertAtPos\n";
//cout<<"4 - deleteLast\n";
//cout<<"5 - deleteFirst\n";
//cout<<"6 - deleteAtPos\n";
//cout<<"7 - clear \n";
//cout<<"8 - getLast\n";
//cout<<"9 - isContains \n";
//cout<<"10 - isEmpty\n";
//cout<<"0 - ВЫХОД\n\n";
//cout<<"Ввод: ";
//cin>>ans;
//switch(ans)
//{
//case 1:
//    system("cls");
//    cout<<"Список: "<<list1<<endl<<"Size: "<<list1.getSize()<<endl;
//    cout<<"Введите значение: ";
//    cin>>value;
//    list1.insertFirst(value);
//   // cout<<list1.size;
//    break;
//}
//}
DoubleLinkedList<float> List;
DoubleLinkedList<float> List1(List);
List.insertLast(0);
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List.insertLast(1.1);
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List.insertFirst (2.2);
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List.insertAtPos(1,3.0);
List.insertAtPos(1,4.0);
List.insertAtPos(3,5.0);
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List.deleteLast();
List.deleteFirst();
List.deleteAtPos(3);
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List1=List;
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
List.clr ();
List1.clr ();
cout<<"\nSize List1: "<<List1.getSize();
cout<<"\nList1: "<<List1;
cout<<"\nSize List: "<<List.getSize();
cout<<"\nList: "<<List;
//List.getLast();
//List.getFirst();
//List.isContains(3.0);
//List.isEmpty();
return 0;
}

