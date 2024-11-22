#include <iostream>
#include <list>
#include <queue>
using namespace std;

int I, N, E, n1, n2;
list<int> *nodeLinks;
bool *visited;

int BFS(int i) {
	queue<int> q;
	int visit, linkSize, nextVisit;
	q.push(i);
	while (!q.empty()) {
		visit = q.front(); q.pop();
		if (!visited[visit]){
			cout << visit << " ";
			visited[visit] = true;
		}
		list<int>::iterator iter;
	    for (iter = nodeLinks[visit].begin(); iter != nodeLinks[visit].end(); iter++)
	        if (!visited[*iter])
				q.push(*iter);
	}
}

int main(int argc, char *argv[])
{
	cin >> I >> N >> E;
	// Create Graph
	nodeLinks = new list<int>[N+1];
	visited = new bool[N] {};
	for (int i=0; i<E; i++) {
		cin >> n1 >> n2;
		nodeLinks[n1].push_back(n2);
		nodeLinks[n2].push_back(n1);
	}
	// Sort (When the data is not in order)
	for (int i=1; i<=N; i++) {
		nodeLinks[i].sort();
	}
	// Breadth-First-Search
	BFS(I);
}
