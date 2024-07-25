#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        vector<Node*> children;
};

Node* newNode(int val)
{
    Node *node = new Node();
    node->data = val;
    return node;
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

Node* construct(int n, vector<int> &arr)
{
    Node *root = newNode(arr[0]);
    stack<Node*> st;
    st.push(root);

    for(int i = 1; i<n; i++)
    {
        if(arr[i]== -1)
            st.pop();
        else
        {
            Node *temp = newNode(arr[i]);
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}

int maximum(Node* root)
{
    int max = INT_MIN;
    for(Node *node : root->children)
    {
       int cm = maximum(node);
       if(cm > max)
            max = cm;
    }
    if(root->data>max) max = root->data;
    return max;
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    cout<<maximum(root);
}