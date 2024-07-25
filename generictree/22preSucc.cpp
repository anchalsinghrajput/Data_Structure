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

int predecessor = 0;
int successor = 0;
int state = 0;
void preSuc(Node *root , int value){
    if(state == 0){
        if(root->data == value)
            state = 1;
        else
            predecessor = root->data;
        // cout<<"p : "<<predecessor<<endl;
    }
    else if(state == 1){
        successor = root->data;
        // cout<<"s : "<<successor<<endl;
        state = 2;
    }
    for(auto child : root->children){
        preSuc(child, value);
    }
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    preSuc(root, 90);
    cout<<"predeccessor : "<<predecessor<<endl;
    cout<<"successor : "<<successor<<endl;
}