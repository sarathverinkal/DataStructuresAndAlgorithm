#include<iostream>
#include<set>
using namespace std;

int main(){
///////////set///////////
cout<<"-------set----------"<<endl;
    set <int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(2);
    s.insert(5);
    //print
    for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i = s.begin();i != s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    //printing in reverse
     for (auto i = s.rbegin();i != s.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    //lower bound and upper bound
    cout<<"upper_bound(1) = "<<*s.upper_bound(1)<<endl;
    cout<<"lower_bound(1) = "<<*s.lower_bound(1)<<endl;

    cout<<endl;
    cout<<"size of set = "<<s.size()<<endl;
    s.erase(2);
       for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(s.begin());
   for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
///////////////multiset////////////////////
cout<<"-------multiset----------"<<endl;
 multiset <int> ms;
 ms.insert(1);
 ms.insert(5);
 ms.insert(3);
 ms.insert(3);
 ms.insert(3);
 ms.insert(3);
 ms.insert(2);
 for(auto i : ms){
    cout<<i<<" ";
 }
 cout<<endl;
 ms.erase(ms.find(3));//deleted only one occurance of 3.
 for(auto i : ms){
    cout<<i<<" ";
 }
 cout<<endl;
 ms.erase(3);
 for(auto i : ms){
    cout<<i<<" ";
 }
 cout<<endl;
    return 0;
}