#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
vector<int> visited(N);
vector<vector<int>> adj(N);
class Graph {
public:
	
	void addEdge(int v, int w);
	void DFS(int v);
    void BFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
    adj[w].push_back(v);
}

void Graph::DFS(int v)
{

	
	cout << v << " ";
    visited[v] = 1;
    for (auto i : adj[v]) {
        if (!visited[i])
            DFS(i);
    }

    return;
}
int dls(int u, int d,int l,int ele){
    if(d>l){
        cout<<"Not Fund";

        return ;
    }
    visited[u]=1;
    if(ele==u){
        cout<<"Found";
        return;
    }
    for(auto i:gr[u]){
        if(!visited[i]){
            dls(i,d+1,l,ele);
        }
    }

    return ;
}

void Graph:: BFS(int v)
{
    
    queue<int> q;
    q.push(v);
    visited[v]=1;
    while(!q.empty())
    {
        int k=q.front();
        
        cout<<k<<" ";
        q.pop();
        for(auto i : adj[v])
        {
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return;
}

int main() {
    int n,e;
    cout<<"Enter the number of node of the graph\n";
    cin>>n;
    cout<<"Enter the number of edges:\n";
    cin>>e;
    Graph g;
    cout<<"Enter the connected Edges:\n";
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    int edge;
    cout<<"Enter the edge for which you want to search ";
    cin>>edge;
    int ch;
    cout<<"Enter 1 for DFS and 2 for BFS\n";
    cin>>ch;
    if(ch==1){
        for(int i=1;i<=n;i++)
	        {
	            if(!visited[i]) 
	            {
	                g.DFS(i);
	            }
	        }
    }
    else{
        for(int i=1;i<=n;i++)
            {
                if(!visited[i]) 
                {
                    g.BFS(i);
                }
            }
    }


  return 0;
}