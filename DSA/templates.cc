#include <iostream>
using namespace std;

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T a,T b){
   // cout<<"type is "<<string(typeid(a).name())<<endl;
    return a > b ? a : b;
}

//class template with one argument
template <typename T> class Array{
private:
    T *ptr;
    int size;
public:
    Array(T arr[],int s);
    void print();
};
template <typename T> Array<T>::Array(T arr[],int s){
    ptr = new T[s];
    size = s;
    for(int i = 0;i < size;i++){
        ptr[i] = arr[i];
    }
}
template <typename T> void Array<T>:: print(){
    for(int i = 0; i < size;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

//we can replace keyword typename with class. These keywords can be interchanged.
template <class C1> class dummy{
private:
    C1 var;
public:
    dummy(C1 v);
    void print();
};
template <class C1> dummy<C1>::dummy(C1 v){
    var = v;
    cout<<"constructor called"<<endl;
} 
template <class C1> void dummy<C1>::print(){
    cout << "val = "<<var<<endl;
}

//multiple arguments in template
//class can be replaced with typename
template <class V,class U> class multipleArg{
private:
    V var1;
    U var2;
public:
    multipleArg(V vbl1,U vbl2);
    void print();
};

template <class V,class U> multipleArg<V,U>::multipleArg(V vbl1,U vbl2){
    var1 = vbl1;
    var2 = vbl2;
    cout<<"constructor called"<<endl;
}
template <class V,class U> void multipleArg<V,U>::print(){
    cout<<"var1 = "<<var1<<" "<<"var2 = "<<var2<<endl;
}

//default argument
template <typename S,typename T = char> class defArg{
private:
    S var1;
    T var2;
public:
    defArg(S v1,T v2){
        var1 = v1;
        var2 = v2;
    }
    void print(){
         cout<<"var1 = "<<var1<<" "<<"var2 = "<<var2<<endl;
    }
};
int main(){
    //function template
    cout<<"test function template"<<endl;
    cout<<"max element is "<<myMax<int>(3,4)<<endl;
    cout<<"max element is "<<myMax<double>(3.0,4.0)<<endl;
    cout<<"max element is "<<myMax<char>('g','e')<<endl;
    //class template
    cout<<"test class template"<<endl;
    int arr[] = {1,2,3,4,5};
    Array<int> A(arr,sizeof(arr)/sizeof(arr[0]));
    A.print();
    char carr[] = {'a','b','c','d','e'};
    Array<char> C(carr,sizeof(carr)/sizeof(carr[0]));
    C.print();
    cout<<"test dummy"<<endl;
     dummy <int> D(5);
     D.print();
    /*test multiple arguments in template*/
    cout<<"test multiple arguments"<<endl;
    multipleArg<char,int> M('x',6);
    M.print();
    /*test default argument in template*/
    cout<<"test default arguments"<<endl;
    defArg<int> DF(3,'y');
    DF.print();
    return 0;
}