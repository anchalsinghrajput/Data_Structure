#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    vector<Node*> children;
    Node(int val) : data(val) {}
};


Node* construct(int n, vector<int>& arr){
    Node *root = new Node(arr[0]);
    stack<Node*> st;
    st.push(root);

    for(int i = 1; i<n; i++){
        if(arr[i] == -1) st.pop();
        else{
            Node *temp = new Node(arr[i]);
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}

void display(Node *node)
{
    string str = to_string(node->data)+"->";
    for(Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<endl;
    for(Node *child : node->children)
    {
        display(child);
    }
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *node = construct(n,arr);
    display(node);
}