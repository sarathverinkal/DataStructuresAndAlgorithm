#include <bits/stdc++.h>
using namespace std;
#define BINARY_TREE 0
#define BINARY_SEARCH_TREE 1
//Binary tree
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}NODE;

void preorder(NODE *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(NODE *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(NODE *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
#if BINARY_SEARCH_TREE
node* insertBST(node *root,int val){
    node *n = new node(val);
    if(root == NULL){
        root = n;
        return root;
    }
    if(val < root->data){
        root->left = insertBST(root->left,val);
    }
    else if(val > root->data){
         root->right = insertBST(root->right,val);
    }
    else{
        cout<<"duplicates not allowed"<<endl;
    }
    return root;
}
node* searchBST(node *root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data < key){
        return searchBST(root->right,key);
    }
    return searchBST(root->left,key);
}
node* inorderSucc(node *root){
    node *temp = root;
    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
node* deleteBST(node *root,int key){
    if(key > root->data){
        root->right = deleteBST(root->right,key);
    }
    else if(key < root->data){
        root->left = deleteBST(root->left,key);
    }
    else{
        if(root->left == NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}
int heightBST(node *root){
    if(root == NULL){
        return 0;
    }
    int leftHgt = heightBST(root->left);
    int rgtHgt = heightBST(root->right);
    return max(leftHgt,rgtHgt) + 1;
}
//O(n^2)
int calcDiam(node *root){
    if(root == NULL){
        return 0;
    }
    int leftHgt = heightBST(root->left);
    int rgtHgt = heightBST(root->right);
    int curDiam = leftHgt + rgtHgt + 1;
    int leftDiam = calcDiam(root->left);
    int rgtDiam = calcDiam(root->right);
    return max(curDiam,max(leftDiam,rgtDiam));
}
//O(n)
int calcDiamOpt(node *root,int *hgt){
    if(root == NULL){
        *hgt = 0;
        return 0;
    }
    int lh=0,rh = 0;
    int ld = calcDiamOpt(root->left,&lh);
    int rd = calcDiamOpt(root->right,&rh);
    int curDiam = lh+rh+1;
    *hgt = max(lh,rh) + 1;
    return max(ld,max(rd,curDiam));
}
int main(){
    node *root = NULL;
    root = insertBST(root,6);
    insertBST(root,1);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,5);
    insertBST(root,8);
    //traversals
    cout<<"inorder"<<endl;
    inorder(root);
     cout<<endl<<"preorder"<<endl;
    preorder(root);
    cout<<endl<<"postorder"<<endl;
    postorder(root);
    //search
    cout<<endl<<"search in BST"<<endl;
    if(searchBST(root,10) != NULL){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not present"<<endl;
    }
    //deletion
    // cout<<"deletion"<<endl;
    // deleteBST(root,7);
    // cout<<"inorder"<<endl;
    // inorder(root);
    // deleteBST(root,4);
    // cout<<"inorder"<<endl;
    // inorder(root);
    //height
    cout<<"height of a tree = "<<heightBST(root)<<endl;
    //diameter
    cout<<"diameter of the tree = "<<calcDiam(root)<<endl;
    //calling opt function
    int height = 0;
    cout<<"diameter of the tree = "<<calcDiamOpt(root,&height)<<endl;
    return 0;
}
#endif //BINARY_SEARCH_TREE
#if BINARY_TREE
int searchPos(int inorder[],int start,int end,int data){
    for(int i=start;i<=end;i++){
        if(inorder[i] == data){
            return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[],int inorder[],int start,int end){
    if(end < start){
        return NULL;
    }
    static int ind = 0;
    int curEle = preorder[ind];
    ind++;
    node *n = new node(curEle);
    if(start == end){
        return n;
    }
    int pos = searchPos(inorder,start,end,curEle);
    n->left = buildTree(preorder,inorder,start,pos-1);
    n->right = buildTree(preorder,inorder,pos+1,end);
    return n;
}
//Build tree from preorder and inorder
int main(){
    int preorderData[] = {1,2,4,5,3,6,7};
    int inorderData[] = {4,2,5,1,6,3,7};
    int start = 0;
    int end = (sizeof(inorderData)/sizeof(int)) - 1;
    cout<<"end = "<<end<<endl;
    node *root = buildTree(preorderData,inorderData,start,end);
    cout<<"inorder data "<<endl;
    inorder(root);
    return 0;
}
#endif //BUNARY_TREE
#if 0 //traversal functions 
//inorder, preorder,postorder
int main(){

    struct node *root;
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
/***************************************************************************************************
            1    -> root node
          /  \
        2     3  -> leaves (last nodes)
       /\     /\
     4   5   6  7

1 2 4 5 3 6 7 preorder
4 2 5 1 6 3 7 inorder
4 5 2 6 7 3 1 postorder
****************************************************************************************************/    

    preorder(root);
    cout<<"preorder"<<endl;
    inorder(root);
    cout<<"inorder"<<endl;
    postorder(root);
    cout<<"postorder"<<endl;
    return 0;
}
#endif 