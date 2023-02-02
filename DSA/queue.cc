//FIFO
//enqueue,dequeue,oeek,empty
#include<iostream>
using namespace std;
#define ARRAY_IMPL 0
#define LINKED_LIST_IMPL 0
// 2 for two stack implementation 1 for function call stack
#define STACK_IMPL 1
#define MAX_SIZE 3


//using 1 stacks
#if STACK_IMPL == 1
#include "bits/stdc++.h"

class Queue{
    stack<int> s1;
public:
    void enqueue(int val){
        s1.push(val);
    }
    void dequeue(){
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        int ele = s1.top();
        s1.pop();
        if(s1.empty()){
            return;
        }
        dequeue();
        s1.push(ele);
        return;
    }
    int peek(){
        if(s1.empty()){
            cout<<"queue is empty ";
            return -1;
        }
        int ele = s1.top();
        s1.pop();
        if(s1.empty()){
            s1.push(ele);
            return ele;
        }
        int res = peek();
        s1.push(ele);
        return res;
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q;
    q.empty() ? cout<<"queue is empty"<<endl :cout<<"queue is non empty"<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    return 0;
}
#endif // using one stack

//using 2 stacks
#if STACK_IMPL == 2
#include "bits/stdc++.h"

class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    void enqueue(int val){
        s1.push(val);
    }
    void dequeue(){
        if(s1.empty() and s2.empty()){
            cout<<"queue empty"<<endl;
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    int peek(){
               if(s1.empty() and s2.empty()){
            cout<<"queue empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q;
    q.empty() ? cout<<"queue is empty"<<endl :cout<<"queue is non empty"<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"top element is "<<q.peek()<<endl;
    q.dequeue();
    return 0;
}
#endif //STACK_IMPL , 2 stacks

#if LINKED_LIST_IMPL //Array implementation
class queue{
    int *arr;
    int front,back;
public:
    queue(){
        arr = new int[MAX_SIZE];
        front = -1;
        back  = -1;
    }
    void enqueue(int ele){
        if(back == MAX_SIZE - 1){
            cout<<"queue is full"<<endl;
            return;
        }
        back++;
        arr[back] = ele;
        if(front == -1){
            front++;
        }
        return;
    }
    void dequeue(){
        if((front == -1) || (front > back)){
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
        return;
    }
    int peek(){
       if((front == -1) || (front > back)){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isempty(){
        return ((front == -1) || (front > back));
    }
};

int main(){
    queue q1;
    q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<"front element is "<<q1.peek()<<endl;
    q1.isempty() ? cout<<"queue is empty"<<endl:cout<<"queue is not empty"<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.isempty() ? cout<<"queue is empty"<<endl:cout<<"queue is not empty"<<endl;
    return 0;
}
#endif //LINKED_LIST_IMPL

#if ARRAY_IMPL //ARRAY_IMPL
class node{
public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node *front;
    node *back;
public:
    queue(){
        front = NULL;
        back = NULL;
    }
    void enqueue(int data){
        node *n = new node(data);
        if(back == NULL){
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
        return;
    }
    void dequeue(){
        if(front == NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        node *toDel = front;
        front = front->next;
        return;
    }
    int peek(){
        if(front == NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        else{
            return false;
        }        
    }
};


int main(){
    queue q;
    q.isEmpty() ? cout<<"queue is empty"<<endl:cout<<"queue is not empty"<<endl;
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"peak element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"peak element is "<<q.peek()<<endl;
    q.dequeue();
    cout<<"peak element is "<<q.peek()<<endl;
    q.dequeue();
    q.dequeue();
    q.isEmpty() ? cout<<"queue is empty"<<endl:cout<<"queue is not empty"<<endl;
    return 0;
}
#endif //ARRAY_IMPL