/******************************************************/
/*********min heap implementation using an array*******/
/******************************************************/

#include<iostream>
using namespace std;

class minHeap{
    int capacity = 10;
    int size = 0;
    int *items = new int[capacity];
    /*          index starts from zero.                         */
    /*  left child index = 2 x parent index + 1                 */
    /*  right child index = 2 x parent index + 2                */
    /*  parent index = (child Index - 1) / 2                    */
    /*  position of first non leaf node = (size - 2) / 2        */
    int getLeftChildIndex(int ParentIndex){return 2 * ParentIndex + 1;}
    int getRightChildIndex(int ParentIndex){return 2 * ParentIndex + 2;}
    int getParentIndex(int childIndex){return (childIndex - 1) / 2;}
    
    bool hasLeftChild(int index){return getLeftChildIndex(index) < size;}
    bool hasRightChild(int index){return getRightChildIndex(index) < size;}
    bool hasParent(int index){return getParentIndex(index) >= 0;}

    int getLeftChild(int index){return items[getLeftChildIndex(index)];}
    int getRightChild(int index){return items[getRightChildIndex(index)];}
    int getParent(int index){return items[getParentIndex(index)];}

    void swap(int index1 , int index2){
        int temp = items[index1];
        items[index1] = items[index2];
        items[index2] = temp;
    }
    void ensureExtraCapacity(){
        if(size == capacity){
            int *temp = items;
            items = new int[capacity * 2];
            for(int i = 0;i < capacity;i++){
                items[i] = temp[i];
            }
            delete temp;
        }
    }
    void heapifyUp(){
        int index = size - 1;
        while(hasParent(index) && getParent(index) > items[index]){
            swap(getParentIndex(index),index);
            index = getParentIndex(index);
        }
    }
    void heapifyDown(int index){
        while(hasLeftChild(index)){
            int smallerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && getRightChild(index) < getLeftChild(index)){
                smallerChildIndex = getRightChildIndex(index);
            }
            if(items[index] < items[smallerChildIndex]){
                break;
            }
            else{
                swap(index,smallerChildIndex);
            }
            index = smallerChildIndex;
        }
    }
public:
    int getCapacity(){
        return capacity;
    } 
    int getSize(){
        return size;
    }
    void fillRandomData(){
        for(int i = 0;i < capacity; i++){
            items[i] = (int)(rand() & UINT8_MAX);
        }
        size = capacity;
    }
    //building heap using bottom-up approach
    void buildMinHeap(){
        int posNonLeafNode = (size - 2) / 2;
        for (int i = posNonLeafNode;i >= 0; i--){
            heapifyDown(i);
        }
    }
//get the element at root
    int peek(){
        if(size == 0){
            cout<<"heap empty"<<endl;
            return -1;
        }
        return items[0];
    }
    //delete root node
    int pull(){
        if(size == 0){
            cout<<"heap empty"<<endl;
            return -1;
        }
        //0 is the root index
        int item = items[0];
        items[0] = items[size - 1];
        size--;
        heapifyDown(0);
        return item;
    }
//insert an element
    void add(int item){
        ensureExtraCapacity();
        items[size] = item;
        size++;
        heapifyUp();
        return;
    }
    /* heap sort inplace -> Descending order        */
    /* use max heap for ascending order.            */
    /* if we are using seperate array(not inplace)  */
    /* then copy the last element at the end        */
    void heapSort(){
        //stage 1
        buildMinHeap();
        //stage 2
        //size > 1 because the last element is minimum.
        while(size > 1){
            int minEle = pull();
            items[size] = minEle;
        }
    }
    void display(){
        for(int i = 0;i < size;i++){
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }
    void printArray(int n){
        for(int i = 0;i < n;i++){
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }
};  


int main(){
    minHeap h;
    h.add(5);
    h.add(7);
    h.add(13);
    h.add(6);
    h.add(4);
    h.add(10);
    h.add(11);
    cout<<"peek : "<<h.peek()<<endl;
    h.display();
    cout<<"pull : "<<h.pull()<<endl;
    h.display();
    //build heap from array
    cout<<"building a min heap from an array filled with random numbers"<<endl;
    h.fillRandomData();
    cout<<"capacity of heap is "<<h.getCapacity()<<endl;
    h.display();
    h.buildMinHeap();
    cout<<"constructed heap"<<endl;
    h.display();
    //heap sort
    cout<<"heap sort descending order"<<endl;
    cout<<"initial unsorted data"<<endl;
    h.fillRandomData();
    h.display();
    int numEle = h.getSize();
    h.heapSort();
    cout<<"data after heap sort"<<endl;
    h.printArray(numEle);
    return 0;
}