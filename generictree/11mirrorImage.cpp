#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};

Node* newNode(int val){
    Node* temp = new Node();
    temp->data = val;
    return temp;
}

Node* construct(int n, vector<int> &arr){
    Node *root = newNode(arr[0]);
    stack<Node*> st;
    st.push(root);
    for(int i = 1; i<n; i++){
        if(arr[i] == -1)
            st.pop();
        else{
            Node *temp = newNode(arr[i]);
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}

void reverse(vector<Node*> &children){
    int i = 0;
    int j = children.size() - 1;
    while(i < j){
        Node* temp = children[i];
        children[i++] = children[j];
        children[j--] = temp;
    }
}

void displayMirror(Node* root){
    for(Node *child : root->children){
        displayMirror(child);
    }
    reverse(root->children);
}

// void reverselevel(Node *root){
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         Node * node = q.front();
//         cout<<node->data<<" ";
//         q.pop();
//         for(int i = node->children.size()-1; i>=0; i--){
//             q.push(node->children[i]);
//         }
//     }
// }

void display(Node *root)
{
    cout<<root->data<<"->";
    for(Node *node : root->children){
        cout<<node->data<<",";
    }
    cout<<"."<<endl;
    for(Node *node : root->children){
        display(node);
    }
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    displayMirror(root);
    display(root);
    // reverselevel(root);
}