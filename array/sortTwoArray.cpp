#include <iostream>
#include <vector>
using namespace std;

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}
vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    vector<int> ans;

    int i = 0;
    int j = 0;
    while(i<A.size() && j<B.size())
    {
        if(A[i]<B[j])
        {
            ans.push_back(A[i++]);
        }
        else
        {
            ans.push_back(B[j++]);
        }
    }

    while(i<A.size())
        ans.push_back(A[i++]);
    while(j<B.size())
        ans.push_back(B[j++]);

    return ans;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}


int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}