#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*>next;
};
int cnt=0;
void display(Node* root){
    if(root==nullptr) return;
    cnt++;
    cout<<root->data<<" ";
    for(int i=0; i<root->next.size(); i++){
        display(root->next[i]);
    }
    // count++;
}
int main(){
    Node* root=nullptr;
    stack<Node*>st;
    vector<int>val={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    for(int i=0; i<val.size(); i++){
        if(val[i]==-1) st.pop();
        else{
            Node* newNode = new Node;
            newNode->data=val[i];
            newNode->next.push_back(nullptr);
            if(st.size()==0){
                root=newNode;
            }
            else{
                Node* temp=st.top();
                temp->next.push_back(newNode);
            }
            st.push(newNode);
        }
    }
    display(root);
    cout<<"\n"<<cnt;
}
