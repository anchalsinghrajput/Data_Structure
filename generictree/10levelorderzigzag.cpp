#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int val)
    {
        this->data = val;
    }
};

Node* construct(int n, vector<int>&arr)
{
    Node *root = new Node(arr[0]);
    stack<Node*> st;
    st.push(root);
    for(int i = 1; i<n; i++)
    {
        if(arr[i] == -1)
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

void display_zigzag(Node *root){
    stack<Node*> mainStack;
    mainStack.push(root);
    stack<Node*> childStack;
    int flag_left_to_right = 1;
    while(!mainStack.empty()){
        Node *node = mainStack.top();
        mainStack.pop();
        cout<<node->data<<" ";
        if(flag_left_to_right){
            for(Node *child : node->children){
                childStack.push(child);
            }
        }
        else{
           for(int i = node->children.size()-1; i>=0; i--){
                childStack.push(node->children[i]);
           }
        }
       if(mainStack.size() == 0){
            mainStack = childStack;
            stack<Node*> st;
            childStack = st;
            flag_left_to_right = !flag_left_to_right;
            cout<<endl;
       }
    }
}

int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    display_zigzag(root);
}