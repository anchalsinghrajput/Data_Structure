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

vector<int> kth_level(Node* root, int level){
    queue<pair<Node* , int>> q;
    q.push({root,1});
    while(!q.empty() && q.front().second < level){
        Node * node = q.front().first;
        int level = q.front().second;
        q.pop();
        if(node->left != NULL) q.push({node->left, level+1});
        if(node->right != NULL) q.push({node->right, level+1});
    }

    vector<int> ans;
    
    while(!q.empty()){
        ans.push_back(q.front().first->data);
        q.pop();
    }
    return ans;
}

void kth_level(Node* root, int level){  
    if(root == NULL || level<=0){
        return;
    }
    if(level == 1){
        cout<<root->data<<", ";
    }
    kth_level(root->left, level-1);
    kth_level(root->right, level-1);
}

int main(){
    vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = arr.size();
    Node *root = construct(n, arr);
    int level;
    cout<<"Enter the level : ";
    cin>>level;
    // vector<int> ans = kth_level(root, level);
    // for(auto x : ans){
    //     cout<<x<<" ";
    // }

    // ====== 2nd approach

    kth_level(root, level);
}