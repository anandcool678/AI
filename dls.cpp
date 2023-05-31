#include<bits/stdc++.h>
typedef long long ll ;
#define int ll 
using namespace std ;
const int N=1e3+2;
vector<vector<int>> v(N);
vector<int> vis(N);

void dls(int u, int d,int l,int ele)
{
    if(d>l) {
        cout<<" Not found" ;
        return;
    }
    vis[u]=1;
    if(ele==u)
    {
      cout<<" found";
      return;
    }
   
    for(auto i:v[u]) 
    {
        if(!vis[i]){
            dls(i,d+1,l,ele);
        }
    }

    return;
}

signed main( )
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l;
    cin>>l;
    int ele;
    cin>>ele;
    for(int i=0;i<m;i++) 
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    dls(0,0,l,ele);
    
    return 0 ;
}  