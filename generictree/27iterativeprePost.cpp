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

void interativePrePost(Node* root){
    stack<pair<Node*,int>> st;
    st.push({root, -1});
    string pre = "";
    string post = "";
    while(!st.empty()){
        Node* node = st.top().first;
        int state = st.top().second;
        if(state == -1){
            pre += to_string(node->data) + ", ";
            st.top().second++;
        } else if(state == node->children.size()){
            post += to_string(node->data) + ", ";
            st.pop();
        } else {
            st.top().second++;
            st.push({node->children[state], -1});
        }
        cout<<state<<endl;
    }
    cout<<"preorder "<<pre<<endl;
    cout<<"postorder "<<post<<endl;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    interativePrePost(root);
}