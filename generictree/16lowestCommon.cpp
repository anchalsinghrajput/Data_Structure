#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>children;
};

Node* construct(int n , vector<int>&arr){
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

void display(Node *root){
    cout<<root->data<<"->";
    for(auto child : root->children){
        cout<<child->data<<", ";
    }
    cout<<"."<<endl;
    for(auto child : root->children){
        display(child);
    }
}


vector<int> nodeToRootPath(int node, Node *root){
    vector<int> ans;
    if(root->data == node){
        ans.push_back(root->data);
        return ans;
    }
    for(auto child : root->children){
        ans = nodeToRootPath(node, child);
        if(ans.size()!=0){
            ans.push_back(root->data);
            return ans;
        }
    }
    return ans;
}

int findLowestCommon(vector<int> ans1, vector<int> ans2){
    int n1 = ans1.size()-1;
    int n2 = ans2.size()-1;
    int ans = 0;
    while(n1 && n2){
        if(ans1[n1] == ans2[n2]){
            ans = ans1[n1];
            n1--;
            n2--;
        }
        else
            break;
    }
    return ans;
}

int main(){
    vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n = arr.size();
    Node *root = construct(n, arr);
    // display(root);
    int node1, node2;
    cout<<"Enter two node : ";
    cin>>node1>>node2;
    vector<int> ans1 = nodeToRootPath(node1, root);
    vector<int> ans2 = nodeToRootPath(node2, root);
    int ans =  findLowestCommon(ans1, ans2);
    cout<<ans;
}