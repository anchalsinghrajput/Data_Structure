#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;

    Node(int data)
    {
        this->data = data;
    }
};

void display_preorder(Node *root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(Node *node : root->children)
        display_preorder(node);
}

Node* construct(int n, vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    stack<Node*> st;
    st.push(root);

    for(int i = 1; i<n; i++)
    {
        if(arr[i]== -1)
            st.pop();
        else
        {
            Node *temp = new Node(arr[i]);
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}



int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    display_preorder(root);
}