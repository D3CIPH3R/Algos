#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next, *prev;

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node *head;

    DoublyLinkedList(){
        head = NULL;
    }

    void insert(int data);
    void print();
    void deleteNodeAtIndex(int pos);
};

/*inserts node at last position*/
void DoublyLinkedList :: insert(int data){
    Node *newnode = new Node(data);
    
    if(head == NULL){
        head = newnode;
        return;
    }

    Node *tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }

    tmp -> next = newnode;
    newnode -> prev = tmp;
}

void DoublyLinkedList ::print(){
    Node*tmp = head;

    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }

    while(tmp != NULL){
        cout << tmp -> data << endl;
        tmp = tmp -> next;
    }

    cout << tmp -> data;
}

/*deletes a node given its position*/
void DoublyLinkedList :: deleteNodeAtIndex(int pos){
    if(head == NULL){
        return;
    }

    Node* tmp = head;

    if(pos == 1){
        head = tmp -> next;
        delete(tmp);
        return;
    }

    while(--pos){
        tmp = tmp -> next;
    }   

    if(tmp -> next == NULL){
        tmp -> prev -> next = NULL;
        delete(tmp);
    }
    else{
        Node* tmp1;
        Node* tmp2;

        tmp1 = tmp -> prev;
        tmp2 = tmp -> next;
        delete(tmp);
        tmp1 -> next = tmp2;
        tmp2 -> prev = tmp1;
    }
    
}

int main(){
    DoublyLinkedList ll;

    ll.insert(25);
    ll.insert(36);
    ll.insert(2);

    // ll.print();

    ll.deleteNodeAtIndex(3);

    ll.print();

}