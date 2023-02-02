#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *prev;
    node *next;
    node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head,int val){
    node *n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
    return;
}
void insertAtTail(node* &head,int val){
    node *n = new node(val); 
    if(head == NULL){
       head = n;
       return;
    }
    node *temp = head;
 
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    
    return;
}
void deleteAtPos(node * &head,int pos){
    node *temp = head;
    if((head == NULL) || (pos < 1)){
        cout << "cannot delete, list is empty or invalid position" << endl;
        return;
    }
    if(pos == 1){
       head = head->next;
       if(temp->next != NULL){
            temp->next->prev = NULL;
       }
       delete temp;
       return; 
    }
    int itr = 1;
    while((temp != NULL) && (itr != pos)){
        temp = temp->next;
        itr++;
    }
    if(temp != NULL){
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    return;
}
void display(node *head){
    if(head == NULL){
        cout<<"nothing to display, list is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
int main(){
    node *head = NULL;
    deleteAtPos(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,1);
    display(head);
    cout<<"deletion starts"<<endl;
    deleteAtPos(head,0);
    deleteAtPos(head,1);
    display(head);
    deleteAtPos(head,3);
    display(head);
    deleteAtPos(head,1);
    display(head);
    deleteAtPos(head,1);
    display(head);

    return 0;
}