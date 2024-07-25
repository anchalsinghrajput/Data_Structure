// total number of nodes

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
};


Node* construct(int n , vector<int> &arr){
    Node *root = new Node();
    root->data = arr[0];
    stack<Node*> st;
    st.push(root);

    for(int i = 1; i<n; i++){
        if(arr[i] == -1)
            st.pop();
        else{
            Node *temp = new Node();
            temp->data = arr[i];
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}


void display(Node *root)
{
    cout<<root->data<<"->";
    for(Node *node : root->children)
    {
        cout<<node->data<<",";
    }
    cout<<"."<<endl;
    for(Node *node : root->children)
    {
        display(node);
    }
}

int size(Node *root)
{
    if(root == NULL)
        return -1;
    int len = 0;
    for(Node* node : root->children)
    {
        len += size(node);
    }
    return len+1;
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    display(root);
    cout<<size(root)<<endl;
}