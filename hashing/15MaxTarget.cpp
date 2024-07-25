// https://leetcode.com/discuss/interview-question/3114099/AMAZON-OA-(INTERN-2024)

#include<bits/stdc++.h>
using namespace std;
int maxNumberOfTimeTargetAppearInStr(string &str, string &target)
{
    int ans = INT_MAX;
    vector<int> strFreq(26,0);
    vector<int> targetFreq(26,0);

    for(auto x : str)
    {
        strFreq[x - 'a']++;
    }
    
    for(auto x : target)
    {
        targetFreq[x - 'a']++;
    }
    // for(int i = 0; i<26; i++)
    // {
    //     cout<<char(i+'a')<<"  : "<<strFreq[i]<<"\t\t"<<char(i+'a')<<"  : "<<targetFreq[i]<<endl;
    // }
    for(int x : target)
    {
        ans = min(ans, strFreq[x-'a']/targetFreq[x - 'a']);
    }
    
    return (ans == INT_MAX) ? -1 : ans;
}
int main()
{
    string str;
    string target;
    cin>>str>>target;
    cout<<maxNumberOfTimeTargetAppearInStr(str, target);
}