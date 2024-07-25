#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};

void display(Node *root){
    Node *temp = root;
    cout<<temp->data<<"->";
    for(auto *node : temp->children){
        cout<<node->data<<", ";
    }
    cout<<"."<<endl;
    for(auto *node : temp->children){
        display(node);
    }
}

void removeleaf(Node *root){
    Node *temp = root;
    for(int i = temp->children.size() - 1; i>= 0; i--){
        Node *child = temp->children[i];
        if(child->children.size() == 0){
            temp->children.erase(temp->children.begin()+i);
        }
    }
    for(auto *node : temp->children){
        removeleaf(node);
    }
}


Node* construct(int n, vector<int> & arr){
    stack<Node*> st;
    Node* root = new Node();
    root->data = arr[0];
    st.push(root);
    for(int i = 1; i<n ; i++){
        if(arr[i] == -1)
            st.pop();
        else{
            Node* temp = new Node();
            temp->data = arr[i];
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    removeleaf(root);
    display(root);
}