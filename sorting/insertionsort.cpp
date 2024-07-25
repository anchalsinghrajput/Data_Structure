#include<bits/stdc++.h>
using namespace std;
void swapping( int *a, int *b)
{
    cout<<"swapping "<<*a<<" with "<<*b<<endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isSmaller(int a, int b)
{
    cout<<"comparing "<<a<<" with "<<b<<endl;
    if(a<b)
        return true;
    return false;
}

void insertionsort(int n, vector<int> & arr)
{
    for(int i = 1; i<n; i++)
    {
        for(int j = i-1; j>=0; j--)
        {
            if(isSmaller(arr[j+1],arr[j]))
            {
                swapping(&arr[j],&arr[j+1]);
            }
            else
                break;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    insertionsort(n,arr);

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<endl;
}