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

bool isTreeSame(Node *root1, Node *root2){
    if(root1->children.size() != root2->children.size()) return false;
    for(int i = 0; i<root1->children.size(); i++){
        bool ans = isTreeSame(root1->children[i], root2->children[i]);
        if(ans == false)
            return false;
    }
    return true;
}

int main(){
    vector<int> tree1 = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    vector<int> tree2 = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,-1};
    int n1 = tree1.size();
    Node *root1 = construct(n1,tree1);
    int n2 = tree2.size();
    Node *root2 = construct(n2, tree2);

    bool ans = isTreeSame(root1, root2);
    cout<<ans;
}