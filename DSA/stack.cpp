//LIFO
//push, pop, top, empty

#include <iostream>
using namespace std;
#define MAX_SIZE 3

class stack{
    int *arr;
    int top = -1;
public:
    stack(){
        arr = new int[MAX_SIZE];
        top = -1;
    }
    void push(int val){
        if(top == MAX_SIZE - 1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
        return;
    }
    void pop(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return;
        }
        top--;
        return;
    }
    int Top(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
        
    }
    bool empty(){
        return (top == -1);
    }
};

int main(){
    stack s;
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.empty() ? cout<<"stack is empty"<<endl : cout<<"stack is not empty"<<endl; 
    cout<<"top element is "<<s.Top()<<endl;
    cout<<"top element is "<<s.Top()<<endl;
    s.pop();
    cout<<"top element is "<<s.Top()<<endl;
    s.pop();
    cout<<"top element is "<<s.Top()<<endl;
    s.pop();
    s.empty() ? cout<<"stack is empty"<<endl : cout<<"stack is not empty"<<endl; 
    return 0;
}