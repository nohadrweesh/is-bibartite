#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
int oo;
int bipartite(vector<vector<int> > &adj) {
	//write your code here
	queue<int>q;
	vector<int>prev(adj.size(), -1);
	vector<int>dist(adj.size(), oo);
	dist[0] = 0;
	q.push(0);//s
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++){
			if (dist[adj[v][i]] == oo){
				q.push(adj[v][i]);
				dist[adj[v][i]] = dist[v] + 1;
				prev[adj[v][i]] = v;
			}
			else{
				if ((dist[adj[v][i]] - dist[v]) % 2 == 0){
					return 0;
				}
			}
		}
	}

	return 1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	oo = n + 1;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << bipartite(adj);
	//system("pause");
}
