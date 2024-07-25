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

vector<int> nodetoRootPath(Node *root, int target){
    vector<int> ans;
    if(root == NULL) return ans;
    if(root->data == target){
        ans.push_back(root->data);
        return ans;
    }
    if(ans.size()==0){
        ans = nodetoRootPath(root->left, target);
    }
    if(ans.size()==0){
        ans = nodetoRootPath(root->right, target);
    }
    if(ans.size() != 0){
        ans.push_back(root->data);
        return ans;
    }
}

int main(){
    vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = arr.size();
    Node *root = construct(n, arr);
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    vector<int> ans = nodetoRootPath(root, target);
    for(auto x : ans){
        cout<<x<<" ";
    }
}