//choose the minimum element and put it in beginning

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

void selectionsort(int n, vector<int> & arr)
{
    for(int i = 0; i<n-1; i++)
    {
        int min = i;
        for(int j = i+1; j<n; j++)
        {
            if(isSmaller(arr[j],arr[min]))
                min = j;
        }
        swapping(&arr[min],&arr[i]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    selectionsort(n,arr);

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<endl;
}