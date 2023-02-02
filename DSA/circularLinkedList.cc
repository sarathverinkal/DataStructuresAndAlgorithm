#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtHead(node * &head,int val){
    node *temp = head;
    node *n = new node(val);
    if(head == NULL){
        n->next = n;
        head = n;
        return ;
    }
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
    return ;
}
void insertAtTail(node * &head,int val){
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != head){
       temp = temp->next; 
    }
    n->next = head;
    temp->next = n;
    return;
}
void deleteAtHead(node * &head){
    if(head == NULL){
        cout<<"cannot delete list is empty"<<endl;
        return;
    }
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    node *toDel = head;
    temp->next = head->next;
    head = head->next;
    delete toDel;
    return ;
}
void deleteAtPos(node * &head,int pos){
    if(head == NULL){
        cout<<"cannot delete list is empty"<<endl;
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int itr = 1;
    while ((temp->next != head) && (itr != pos - 1)){
        temp = temp->next;
        itr ++;
    }
    node *toDel = temp->next;
    temp->next = temp->next->next;
    delete toDel;
    return;
}
void display(node *head){
    node *temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;
    return;
}
int main(){
    node *head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,1);
    display(head);
    deleteAtPos(head,1);
    display(head);
    deleteAtPos(head,4);
    display(head);
    deleteAtPos(head,2);
    display(head);
    deleteAtHead(head);
    display(head);
 
    return 0;
}