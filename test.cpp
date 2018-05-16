#include<iostream>
#include"DoublyLinkedList.h"
using namespace std;
int main(){
    DoublyLinkedList list;

    for(int i=0;i<10;++i){
        list.append(i);
    }
    list.scroll();
    cout<<endl;

    list.prepend(6);
    list.scroll();
    cout<<endl;
    
    list.findOccurances(6);
    cout<<endl;

    list.insertBefore(9,13);
    list.insertAfter(5,14);
    list.scroll();
    cout<<endl;
    
    return 0;
}