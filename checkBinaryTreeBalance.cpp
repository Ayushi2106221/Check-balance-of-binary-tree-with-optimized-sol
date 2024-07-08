#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *left;
    int data;
    Node *right;
    
};
int height(Node *root){
    if(root==NULL)
    return 0;
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}
//here complexity in o(N^2)
bool isbalanced(Node *root){
    if(root==NULL)
    return true;
    bool left=isbalanced(root->left);
    bool right=isbalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff)
    return true;
    else 
    return false;
}

//optimized solution TC=0(N^2)
pair<bool,int> fastbalance(Node *root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int>left=fastbalance(root->left);
    pair<bool,int>right=fastbalance(root->right);
    bool leftans=left.first;
    bool rightans=right.first;
    bool diff=abs(left.second-right.second)<=1;
    //to return a pair as an answer
    pair<int,int>ans;
    ans.second=max(left.second,right.second)+1;
    //condition for a balanced tree
    if(leftans && rightans && diff)
        ans.first=true;
    else
    ans.first=false;

    return ans;
}
bool checkisbalanced(Node *root){
    return fastbalance(root).first;
}