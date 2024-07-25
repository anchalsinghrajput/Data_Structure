#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    vector<Node*> children;
};


Node* construct(int n, vector<int>& arr){
    Node *root = new Node();
    root->data = arr[0];
    stack<Node*> st;
    st.push(root);

    for(int i = 1; i<n; i++){
        if(arr[i] == -1) st.pop();
        else{
            Node *temp = new Node();
            temp->data = arr[i];
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}
int floor_value= INT_MIN; ///floor means value se just chota
int ceil_value = INT_MAX; /// ceil means value se just badha

void floorCeil(Node *root, int value){
    if(root->data  < value && floor_value < root->data)
        floor_value= root->data;
    else if(root->data > value && ceil_value > root->data){
        ceil_value = root->data;
    }
    for(auto child : root->children){
        floorCeil(child, value);
    }
}

int kthLargestElement(Node *root, int k){
    int factor = INT_MAX;
    for(int i = 0; i<k; i++){
        floorCeil(root,factor);
        // cout<<"f : "<<floor_value<<endl;
        factor = floor_value;
        floor_value = INT_MIN;
    }
    return factor;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    int k;
    cout<<"Enter the K value : ";
    cin>>k;
    int ans = kthLargestElement(root, k);
    cout<<ans;
}
