// big element get placed at last

#include<iostream>
#include<vector>
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

void bubblesort(int n, vector<int> &arr)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 1; j<n-i; j++)
        {
            if(isSmaller(arr[j],arr[j-1]))
            {
                swapping(&arr[j],&arr[j-1]);
            }
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
    
    bubblesort(n,arr);

    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<endl;
    }
}