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

// == using 2 queue
// void display_levelorder(Node *root)
// {
//     if(root == NULL) return;
//     queue<Node*> q;
//     q.push(root);
//     queue<Node*> cq;

//     while(!q.empty())
//     {
//         Node* node = q.front();
//         cout<<node->data<<" ";
//         q.pop();
        
//         for(Node* child : node->children)
//         {
//             cq.push(child);
//         }
//         if(q.empty())
//         {
//             cout<<endl;
//             q=cq;
//             queue<Node*> temp;
//             cq = temp;
//         }
//     }
// }

// with null flag
// void display_levelorder(Node *root)
// {
//     if(root == NULL) return;
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty())
//     {
//         Node* node = q.front();
//         q.pop();
//         if(node == NULL && q.size()>0)
//         {
//             q.push(NULL);
//             cout<<endl;
//             continue;
//         }
//         cout<<node->data<<" ";
//         for(Node* child : node->children)
//         {
//             q.push(child);
//         }
//     }
// }

// ==size
// void display_levelorder(Node *root)
// {
//     if(root == NULL) return;
//     queue<Node*> q;
//     q.push(root);
   
//     while(!q.empty())
//     {
//        int size = q.size();
//        for(int i = 0; i<size; i++)
//        {
//             Node *node = q.front();
//             q.pop();
//             cout<<node->data<<" ";
//             for(Node* child : node->children)
//             {
//                 q.push(child);
//             }
//        }
//        cout<<endl;
//     }
// }

// // == pair of node and level
void display_levelorder(Node *root)
{
    if(root == NULL) return;
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int prevLevel = 0;
    while(!q.empty())
    {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        cout<<node->data<<" ";
        if(prevLevel!= level)
            cout<<endl;
        for(Node* child : node->children)
        {
            q.push({child,level+1});
        }
        prevLevel = level;
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



int main()
{
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    display_levelorder(root);
}