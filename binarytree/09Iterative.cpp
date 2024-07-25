#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int n, vector<int> & arr){

    Node* root = new Node(arr[0]);

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    int idx = 1;

    while(!st.empty()){
        Node *node = st.top().first;
        int state = st.top().second;

        if(state == 1){
            st.top().second++;
            if(arr[idx] != -1){
                Node *leftNode = new Node(arr[idx]);
                node->left = leftNode;
                st.push({leftNode, 1});
            } 
            else{
                node->left = NULL;
            }
            idx++;
        }
        else if(state == 2){
            st.top().second++;
            if(arr[idx] != -1){
                Node *rightNode = new Node(arr[idx]);
                node->right = rightNode;
                st.push({rightNode, 1});
            } 
            else{
                node->right = NULL;
            }
            idx++;
        }
        else {
            st.pop();
        }   
    }
    return root;
}

void iterativePreInPost(Node *root){
    string pre = "", in = "", post ="";
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        Node *node = st.top().first;
        int state = st.top().second;
        if(state == 1){
            pre += to_string(node->data) + ", ";
            st.top().second++;
            if(node->left != NULL) st.push({node->left, 1});
        }
        else if(state == 2){
            in +=  to_string(node->data) + ", ";
            st.top().second++;
            if(node->right != NULL) st.push({node->right, 1});
        }
        else {
            post += to_string(node->data) + ", ";
            st.pop();
        }
    }
    cout<<"Preorder : "<<pre<<endl<<"Inorder : "<<in<<endl<<"Postorder : "<<post;
}

int main(){
    vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = arr.size();
    Node *root = construct(n, arr);
    iterativePreInPost(root);
}