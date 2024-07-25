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


Node *findNode(Node* root, int target){
    
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node *node = st.top();
        if(node->data == target)
            return node;
        st.pop();
        if(node->left != NULL) st.push(node->left);
        if(node->right != NULL) st.push(node->right);
    }
    
    return root;
}


vector<Node*> nodetoRootPath(Node *root, int target){
    vector<Node*> ans;
    if(root == NULL) return ans;
    if(root->data == target){
        ans.push_back(root);
        return ans;
    }
    if(ans.size()==0){
        ans = nodetoRootPath(root->left, target);
    }
    if(ans.size()==0){
        ans = nodetoRootPath(root->right, target);
    }
    if(ans.size() != 0){
        ans.push_back(root);
        return ans;
    }
}

vector<int> kthLevelDown(Node* root, int k, Node* avoid_node) {
    vector<int> ans;

    queue<Node*> q1;
    q1.push(root);
    int level = 0;

    while (q1.size()) {
        int size = q1.size();

        for (int i = 0; i < size; i++) {
            Node* curr = q1.front();
            q1.pop();

            if (k == level) {
                ans.push_back(curr->data);
                continue;
            }

            if (curr->left && curr->left != avoid_node) {
                q1.push(curr->left);
            }

            if (curr->right && curr->right != avoid_node) {
                q1.push(curr->right);
            }
        }

        level++;
    }

    return ans;
}

vector<int> NodesKthLevel(Node* root, int target, int distance){
    Node *targetNode = findNode(root, target);
    vector<Node*> pathToTarget = nodetoRootPath(root, target);

    for (auto n: pathToTarget) {
        cout << n->data << " ";
    }
    cout << endl;

    vector<int> res;
    vector<int> temp;

    for (int i = 0; i < pathToTarget.size(); i++) {
        Node* curr = pathToTarget[i];
        if (i == 0) {
            temp = kthLevelDown(curr, distance - i, nullptr);
        } else {
            temp = kthLevelDown(curr, distance - i, pathToTarget[i - 1]);
        }

        for (const int& num: temp) {
            res.push_back(num);
        }
    }

    return res;
}

int main(){
    vector<int> arr = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = arr.size();
    Node *root = construct(n, arr);
    int target , distance;
    cout<<"Enter the target node and distance : ";
    cin>>target>>distance;
    vector<int> ans = NodesKthLevel(root, target, distance);

    for (const int& num: ans) {
        cout << num << " ";
    }

    cout << endl;
}