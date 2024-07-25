#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> visited(V,-1);
	    queue<int> q;
	    
	    for(int i = 0; i<V; i++)
	    {
	        if(visited[i] == -1)
	        {
	            q.push(i);
        	    visited[i] = 0;
        	    
        	    while(!q.empty())
        	    {
        	        int node = q.front();
        	        int color = visited[node];
        	        q.pop();
        	        
        	        for(auto x : adj[node])
        	        {
        	            if(visited[x] == -1)
        	            {
        	                visited[x] = color == 1 ? 0 : 1;
        	                q.push(x);
        	            }
        	            else if(visited[x] == color)
        	            {
        	                return 0;
        	            }
        	        }
        	    }
	        }
	    }
	    
	    
	    return 1;
	    
	}

};

int main(){
	int V, E;
	cin >> V >> E;
	vector<int>adj[V];
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Solution obj;
	bool ans = obj.isBipartite(V, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	return 0;
}