//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        
        for(auto x : wordList)
        {
            mp[x] = 0;
        }
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        int minlen = INT_MAX;
        while(!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            
            for(int i = 0; i<word.size(); i++)
            {
                for(int j = 0; j<26; j++)
                {
                    string curword = word.substr(0,i) + char(j+'a') + word.substr(i+1,word.size());
                    cout<<curword<<endl;;
                    if(curword == targetWord)
                    {
                        minlen = min(minlen,len);
                    }
                    else if(mp.find(curword)!=mp.end() && mp[curword] == 0)
                    {
                        cout<<curword<<endl;
                        q.push({curword,len+1});
                    }
                }
            }
        }
        
        return minlen;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends