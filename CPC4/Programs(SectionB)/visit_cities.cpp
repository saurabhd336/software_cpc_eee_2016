#include<bits/stdc++.h>
using namespace std;
/*
Sample input
	5 5 3
	1 2
	1 3
	2 3
	3 4
	3 5
	3 5 2
Expected output: 8
*/
vector<int> dist (1000, INT_MAX);

void bfs(vector<vector<int> > &graph, int start)
{
	//Visited[i] represnts whether or not node 'i' has been visited
	vector<int> visited (graph.size() + 1, 0);
	
	//dist[i] -> minimum distance to node 'i' from '1'
	dist[start] = 0;
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int i = 0; i < graph[temp].size(); i++)
			if(!visited[graph[temp][i]])
			{
				visited[graph[temp][i]] = 1;
				dist[graph[temp][i]] = dist[temp] + 1;
				q.push(graph[temp][i]);
			}
	}
}

int main()
{
	//We represent the network using a graph (adjancency list)
	//We perform BFS on the graph with '1' as start and therefore generate shortest distance to each city from '1'
	//For each of the k cities where his friends live, we add 2 * distance of the city from '1' to the final answer
	//Can read about BFS online
	int n, m, k, a, b;
	cin>>n>>m>>k;
	
	//graph[i] represents all nodes connected to node 'i' directly
	vector<vector<int> > graph (n + 1);
	
	for(int i = 0; i < m; i++)
	{
		cin>>a>>b;
		//Bidirectional hence both pushes
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	int ans = 0;
	bfs(graph, 1);
	for(int i = 0; i < k; i++)
	{
		//For each city, add 2 * distance to it from '1'
		cin>>a;
		ans += 2 * dist[a];
	}
	
	cout<<ans<<"\n";
	return 0;
}
