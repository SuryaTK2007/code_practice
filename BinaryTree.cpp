#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
int cnt=0;
void display(Node* root){
    if(root==nullptr) return;
    cnt++;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int height(Node* root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}
int main(){
    vector<int>val={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    stack<pair<Node*,int>>st;
    // cout<<val.size()<<endl;
    Node* root=nullptr;
    for(int i=0; i<val.size(); i++){
        while(!st.empty() && st.top().second>=3){
            st.pop();
        }
        if(val[i]==-1){
            st.top().second+=1;
            continue;
        }
        Node* newNode=new Node;
        newNode->data=val[i];
        newNode->left=nullptr;
        newNode->right=nullptr;
        if(st.size()==0){
            root=newNode;
            st.push({root,1});
        }
        else{
            if(st.top().second==1){
                st.top().first->left=newNode;
                st.top().second+=1;
            }
            else if(st.top().second==2){
                st.top().first->right=newNode;
                st.top().second+=1;
            }
        }
        st.push({newNode,1});
    }
    display(root);
    cout<<endl;
    int h=height(root);
    cout<<h;
    cout<<endl;
    cout<<cnt<<endl;
}