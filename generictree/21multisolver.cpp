#include<bits/stdc++.h>
using namespace std;

int size;
int mini;
int maxi;
int height;

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

void multisolver(Node *root, int depth){
    size++;
    mini = min(mini, root->data);
    maxi = max(maxi, root->data);
    height = max(height, depth);
    for(auto child : root->children){
        multisolver(child, depth+1);
    }
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);

    size = 0;
    mini = INT_MAX;
    maxi = INT_MIN;
    height = 0;

    multisolver(root, 0);

    cout<<"Size of the tree is "<<size<<endl;
    cout<<"Max element in the tree "<<maxi<<endl;
    cout<<"Mini element in the tree "<<mini<<endl;
    cout<<"Height of the tree "<<height<<endl;
}