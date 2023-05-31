// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

class Graph {
	int V; 
	list<pair<int, int> >* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
	
	priority_queue<iPair, vector<iPair>, greater<iPair> >pq;
	vector<int> dist(V, INF);
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		
		int u = pq.top().second;
		pq.pop();

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
			
			int v = (*i).first;
			int weight = (*i).second;


			if (dist[v] > dist[u] + weight) {
				
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}


	cout<<"Vertex Distance from Source\n";
	for (int i = 0; i < V; ++i){
	cout<<endl;
		cout<< i<<"              "<< dist[i];
		}
}

// Driver's code
int main()
{
	// create the graph given in above figure
int n,m;
    cin>>n>>m;

	Graph g(n);
    for(int i=0;i<m;i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        g.addEdge(a,b,wt);
    }

	// Function call
	g.shortestPath(0);

	return 0;
}
   