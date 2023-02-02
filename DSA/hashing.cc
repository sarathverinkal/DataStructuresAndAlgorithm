#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>

using namespace std;

signed main(){
    map<int,int> m;
    m[8] = 2;//here key is 8 and data is 2
    cout<<"ordered map m[8] = "<<m[8]<<endl;
    unordered_map<int,int> um;
    um[2] = 7;
    cout<<"unordered map um[2] = "<<um[2]<<endl;
//counting the frequency of each item in an array using map
//TO change to unordered map use unordered map eveyrwhere
    int size = 5;
    vector<int> v(size);
    for(int i = 0;i < size;i++){
        cin >> v[i];
    }
    map<int,int> freq;
    for(int i = 0;i < size;i++){
        freq[v[i]]++;
    }
    map<int,int>::iterator it;
    for(it=freq.begin() ;it != freq.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}