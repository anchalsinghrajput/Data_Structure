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

void display_prepost(Node *root)
{
    if(root == NULL) return;
    
    cout<<"Node pre "<<root->data<<endl;
    for(Node *node : root->children)
    {
        cout<<"Edge Pre "<<root->data<<"--"<<node->data<<endl;
        display_prepost(node);
        cout<<"Edge Post "<<root->data<<"--"<<node->data<<endl;
    }
    cout<<"Node post "<<root->data<<endl;
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



int main()
{
    vector<int> arr = {10,20,-1,30,50,-1,60,-1,-1,40,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    display_prepost(root);
}