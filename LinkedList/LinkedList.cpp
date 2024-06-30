// #include<bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = NULL;        
        }
};

class LinkedList{
    Node* head = NULL;
    public:
        LinkedList(){
            head = NULL;
        }
        void insertNode(int);
        void printAll();   
        void deleteNodeAtBegOrEnd(int);
        void deleteNodeAtMid(int);
        void reverseLL();
};

void LinkedList :: reverseLL(){
    stack<Node*> st;
    Node* tmp = head;

    while(tmp != NULL){
        st.push(tmp);
        tmp = tmp -> next;
    }

    // while(!st.empty()){
    //     tmp = st.top();
    //     cout << tmp -> data;
    //     st.pop();
        
    // }
    tmp -> data;
    head = tmp;
    st.pop();

    while(!st.empty()){
        tmp -> next = st.top();
        st.pop();
        tmp = tmp -> next;
    }
    tmp -> next = NULL;
}

void LinkedList :: deleteNodeAtMid(int nodeData){
    Node* tmp = head;
    Node* tmp2 = head -> next;
    while(tmp2 -> data != nodeData){
        tmp2 = tmp2 -> next;
        tmp = tmp -> next;
    }
    tmp -> next = tmp2 -> next;
    delete(tmp2);
}

void LinkedList :: deleteNodeAtBegOrEnd(int nodeData){
    Node* tmp = head;

    if(tmp -> data == nodeData){
        head = tmp -> next;
        delete(tmp);
    }

    Node* tmp1 = head -> next;
    while (tmp1 -> next != NULL)
    {
        tmp1 = tmp1 -> next;
        tmp = tmp -> next;
    }

    tmp -> next = NULL;
    delete(tmp1);   
}

void LinkedList:: insertNode(int nodeData){
    Node* newNode = new Node();
    newNode -> data = nodeData;
    if(head == NULL){
        head = newNode;
        return;
    }
    
    Node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

void LinkedList :: printAll(){
    Node* tmp = head;

    if(head == NULL){
        cout << "List is empty";
        return ;
    }
    while(tmp != NULL){
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
}

int main(){
    LinkedList list;
    // list.printAll();
    list.insertNode(2);
    list.insertNode(5);
    list.insertNode(6);
    list.insertNode(8);
    list.printAll();
    // list.deleteNodeAtMid(6);
    list.reverseLL();
    list.printAll();
    // Node* head = NULL;

    // Node* newNode1 = new Node(5);
    // Node* newNode2 = new Node(6);
    
    // newNode1 -> data = 5;
    // newNode1 -> next = newNode2;
    // head -> next = newNode1;

    // // newNode2 -> data = 6;
    // newNode2 -> next = NULL; 

    // Node* current = head;
    // while(current != NULL){
    //     cout << current -> data;
    //     current = current -> next;
        
    // }

    // cout << "hello"
}