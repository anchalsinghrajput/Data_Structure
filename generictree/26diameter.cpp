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

int dia = 0;
int diameter(Node * root){
    int mx = -1;
    int smx = -1;
    
    for(Node* child : root->children){
        int ch = diameter(child);
        if(ch > mx){
            smx = mx;
            mx = ch;
        }
        else if(ch > smx){
            smx = ch;
        }
    }
    if(dia < mx + smx + 2){
        dia =  mx + smx + 2;
    }

    return mx+1;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,10,20,30,40,50,-1,-1,-1,-1,-1,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    diameter(root);
    cout<<dia;
}