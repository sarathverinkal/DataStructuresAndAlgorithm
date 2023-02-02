#include <iostream>
using namespace std;
//pass by reference
void passByReff(int &v){
    v++;
}
void passByRef(int &v){
    v++;
    passByReff(v);
}
int main(){
    int x = 0;
    cout<<"before pass by reference : " << x << endl;
    passByRef(x);
    cout<<"after pass by reference : " << x << endl;
    return 0;
}