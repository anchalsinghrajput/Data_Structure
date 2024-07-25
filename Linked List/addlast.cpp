#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int val;
    node *next;
};

node* create_node(int data)
{
    node *temp = new node;
    temp->val = data;
    temp->next = NULL;
    return temp;
}
void insert_at_tail(node *head, int data)
{
    if(head == NULL)
    {
        // cout<<data;
        node *newnode = create_node(data);
        head = newnode;
        cout<<"new : "<< newnode->val;
    }
    else
    {
        // cout<<data;l
        node *newnode = create_node(data);
        node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}
void print(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}

int size(node *head)
{
    node *temp = head;
    int count = 0;
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int last(node *head)
{
    node *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    return temp->val;
}

int main()
{
    node *head = new node;
    string s;
    cin>>s;
    while(s!="quit")
    {
        int data;
        cin>>data;
        // cout<<data;
        insert_at_tail(head,data);
        cin>>s;
    }

    // if(head == NULL)
    // {
    //     cout<<0<<endl;
    //     return 0;
    // }

    print(head);
    cout<<size(head)<<endl;
    cout<<last(head);
}
