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

void insertTail(node * &head,int val){
    node *n = new node(val);
    
    if(head == NULL){ 
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return;
}
void insertHead(node * &head,int val){
    node *n = new node(val);
    n->next = head;
    head = n;
    return;
}
void diplayList(node *head){
  
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
bool searchList(node *head,int s){
    while(head != NULL){
        if(s == head->data){
            return true;
        }
        head = head->next;
    }
    return false;
}
void deleteAtHead(node * &head){
    node *toDel = head;
    head = head->next;
    delete toDel;
    return;
}
void deleteNode(node * &head,int dV){
    node *temp = head;
    if(temp == NULL){
        return ;
    }
    if(temp->data == dV){
        deleteAtHead(head);
        return;
    }
    node *prev = NULL;
    while((temp->data != dV) && (temp->next != NULL)){
        prev = temp;
        temp = temp->next;
    }
    if(temp->data == dV){
    node *toDel = temp;
    prev->next = temp->next;
    delete toDel;
    }
    else{
        cout<<"element not found" <<endl;
    }
    return;
}
void revList(node * &head){
    if((head == NULL) || (head->next == NULL)){
        return;
    }

    node *prev = NULL;
    node *cur = head;
    node *next;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return ;
}
node* revListRec(node *head){
    if((head == NULL) || (head->next == NULL)){
        return head;
    }
    node *newHead = revListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
int main(){
    node *head = NULL;
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertHead(head,1);
    cout<<"original list"<<endl;
    diplayList(head);
    //reversing the list
    revList(head);
    cout<<"reversed list via iteration"<<endl;
    diplayList(head);
    cout<<"reversed list via recursion"<<endl;
    node *newHead = revListRec(head);
    diplayList(newHead);
    return 0;
}
#if 0
int main(){
    node *head = NULL;
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertHead(head,1);
    diplayList(head);
    cout<<"is 5 present in the list ? " << searchList(head,5) << endl; 
    cout<<"is 7 present in the list ? " << searchList(head,7) << endl; 
    deleteNode(head,1);
    diplayList(head);
    deleteNode(head,2);
    deleteNode(head,3);
    deleteNode(head,4);
    diplayList(head);
    deleteNode(head,5);
    diplayList(head);

    return 0;
}
#endif 