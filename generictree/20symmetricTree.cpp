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

bool areTreeMirrorImageInShape(Node *root1, Node *root2){
    if(root1->children.size() != root2->children.size()) return false;
    for(int i = 0; i<root1->children.size(); i++){
        int j = root1->children.size() - 1- i;
        bool ans = areTreeMirrorImageInShape(root1->children[i], root2->children[j]);
        if(ans == false)
            return false;
    }
    return true;
}

int main(){
    vector<int> tree = {1,2,3,-1,-1,-1};
    int n = tree.size();
    Node *root = construct(n,tree);
    bool ans = areTreeMirrorImageInShape(root, root);
    cout<<ans;
}