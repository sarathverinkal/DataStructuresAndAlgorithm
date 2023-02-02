#include<iostream>
#include<vector>
using namespace std;

class Trie{
    class node{
public:
        bool end;
        node *next[26];
        node(){
            end = false;
            for(int i = 0;i < 26;i++){
                next[i] = NULL;
            }
        }
    };
private:
    node *trie;
public:
     Trie(){
        trie = new node();
     }

     void insert(string word){
        int i = 0;
        node *itr = trie;
        while(i < word.size()){
            if(itr->next[word[i] - 'a'] == NULL){
                itr->next[word[i] - 'a'] = new node();
            }
            itr = itr->next[word[i] - 'a'];
            i++;
        }
        itr->end = true;
     }
     bool search(string word){
        int i = 0;
        node *itr = trie;
        while(i < word.size()){
            if(itr->next[word[i] - 'a'] == NULL){
                return false;
            }
            itr = itr->next[word[i] - 'a'];
            i++;
        }
        return itr->end;
     }
};

int main(){
    Trie *T = new Trie();
    vector<string> words = {"alan","turing"}; 
    //insert
    for(auto w : words){
        T->insert(w);
    }
    //search
    T->search("turing") ? cout<<"word found"<<endl : cout<<"word not found"<<endl;
    T->search("enigma") ? cout<<"word found"<<endl : cout<<"word not found"<<endl;
    T->search("alan") ? cout<<"word found"<<endl : cout<<"word not found"<<endl;
    return 0;
}