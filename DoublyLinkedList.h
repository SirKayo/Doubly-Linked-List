#include<iostream>
class DoublyLinkedList{
    private:
        struct Node{
            int value;
            Node* prev;
            Node* next;
        };
        Node *head, *tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void append(int newValue);
        void prepend(int newValue);
        void pop();
        void shift();

        void scroll();
        void scrollReverse();

        void findOccurances(int value);

        void insertBefore(int node, int element);
        void insertAfter(int node, int element);
    private:
        void findOccurances(Node* node, int value);

        void scroll(Node* node);
        void scrollReverse(Node* node);

        void insertBefore(Node* current, int node, int element);
        void insertAfter(Node* current, int node, int element);

        void destroyer(Node* node);
};

DoublyLinkedList::DoublyLinkedList(){
    head=nullptr;
    tail=nullptr;
}
DoublyLinkedList::~DoublyLinkedList(){
    destroyer(head);
}
void DoublyLinkedList::append(int newValue){
    Node* newNode = new Node;
    newNode->value=newValue;
    newNode->next=nullptr;
    
    if(head==nullptr){
        newNode->prev=nullptr;
        head=newNode;
    }else{
        newNode->prev=tail;
        tail->next=newNode;
    }
    tail=newNode;
}
void DoublyLinkedList::prepend(int newValue){
    Node* newNode = new Node;
    newNode->value=newValue;
    newNode->prev=nullptr;

    if(head==nullptr){
        newNode->next=nullptr;
        tail=newNode;
    }else{
        head->prev=newNode;
        newNode->next=head;
    }
    head=newNode;
}
void DoublyLinkedList::pop(){
    Node* newTail=tail->prev;
    newTail->next=nullptr;

    delete tail;
    tail=newTail;
}
void DoublyLinkedList::shift(){
    Node* newHead=head->next;
    newHead->prev=nullptr;

    delete head;
    head=newHead;
}
void DoublyLinkedList::scroll(){
    scroll(head);
}
void DoublyLinkedList::scroll(Node* node){
    if(node!=nullptr){
        std::cout<<node<<" "<<node->value<<std::endl;
        scroll(node->next);
    }
}
void DoublyLinkedList::scrollReverse(){
    scrollReverse(tail);
}
void DoublyLinkedList::scrollReverse(Node* node){
    if(node!=nullptr){
        std::cout<<node<<" "<<node->value<<std::endl;
        scrollReverse(node->prev);
    }
}

void DoublyLinkedList::insertBefore(int node, int value){
    if(head->value==node){
        prepend(node);
    }else{
        insertBefore(head,node,value);
    }
}
void DoublyLinkedList::insertAfter(int node, int value){
    if(tail->value==node){
        append(node);
    }else{
        insertAfter(head,node,value);
    }
}
void DoublyLinkedList::insertBefore(Node* current, int node, int value){
    if(current->next->value != node){
        insertBefore(current->next,node,value);
    }else{
        Node* newNode= new Node;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}
void DoublyLinkedList::insertAfter(Node* current, int node, int value){
    if(current->value != node){
        insertAfter(current->next,node,value);
    }else{
        Node* newNode= new Node;
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void DoublyLinkedList::findOccurances(int value){
    findOccurances(head,value);
}
void DoublyLinkedList::findOccurances(Node* node, int value){
    if(node!=nullptr){
        if(node->value==value){
            std::cout<<"Found occurance of "<<value<<" at address: "<<node<<std::endl;
        }
        findOccurances(node->next,value);
    }
}

void DoublyLinkedList::destroyer(Node* node){
    if(node!=nullptr){
        destroyer(node->next);
        delete node;
    }
}