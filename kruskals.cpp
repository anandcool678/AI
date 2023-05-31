#include<bits/stdc++.h>
typedef long long ll ;
#define int ll 
using namespace std ;

const int MAX=1e5+7;

int parent[MAX],rank1[MAX];

void make_set(int v) {
    parent[v] = v;
    rank1[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            rank1[a]++;
    }
}


signed main( )
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n,m ;
        cin >> n>>m;
        
        vector<pair<int, pair<int,int>>> edgelist;
        
        for(int i=0;i<m;i++)
        {
        	int w,u,v;
        	cin>>w>>u>>v;
        	
        	edgelist.push_back({w,{u,v}});
        }
        
        int cost=0;
        
        sort(edgelist.begin(),edgelist.end());
        
        for(int i=1;i<=n;i++)
        {
        	make_set(i);
        }
        
        for(auto &ed:edgelist)
        {
            int w = ed.first;
            int x = ed.second.first;
            int y = ed.second.second;
 
            if (find_set(x) != find_set(y)) {
                union_sets(x, y);
                cost += w;
                
            }
        }
 
        cout << cost;
    }	
        
        
        cout << endl ;
    
    return 0 ;
}    