
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;
};

void display(Node *root){
    Node *temp = root;
    cout<<temp->data<<"->";
    for(auto *node : temp->children){
        cout<<node->data<<", ";
    }
    cout<<"."<<endl;
    for(auto *node : temp->children){
        display(node);
    }
}

// Node *getTail(Node *node){
//     while(node->children.size() == 1){
//         node = node->children[0];
//     }
//     return node;
// }

// void linearize(Node *node){
//     for(Node *child : node->children){
//         linearize(child);
//     }

//      for (int i = node->children.size() - 1; i >= 1; i--){
//         Node *lastChild = node->children[i];
//         Node *slt = getTail(node->children[i - 1]);
//         slt->children.push_back(lastChild);
//         node->children.pop_back();
//     }
// }

// efficient code 

Node* linearize(Node *node){
    if(node->children.size() == 0)
        return node;
    
    Node* lastTail = linearize(node->children[node->children.size() - 1]);
    while(node->children.size() > 1){
        Node* last = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node* sl = node->children[node->children.size() - 1];
        Node* slt = linearize(sl);
        slt->children.push_back(last);
    }
    return lastTail;
}

Node* construct(int n, vector<int> & arr){
    stack<Node*> st;
    Node* root = new Node();
    root->data = arr[0];
    st.push(root);
    for(int i = 1; i<n ; i++){
        if(arr[i] == -1)
            st.pop();
        else{
            Node* temp = new Node();
            temp->data = arr[i];
            st.top()->children.push_back(temp);
            st.push(temp);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n,arr);
    linearize(root);
    display(root);
}

