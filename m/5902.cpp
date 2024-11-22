#include <iostream>
#include <list>
#include <stack>
using namespace std;

int I, N, E, n1, n2;
list<int> *nodeLinks;
bool *visited;

int DFS(int i) {
	stack<int> s;
	int visit, linkSize, nextVisit;
	s.push(i);
	while (!s.empty()) {
		visit = s.top(); s.pop();
		if (!visited[visit]){
			cout << visit << " ";
			visited[visit] = true;
		}
		list<int>::reverse_iterator iter;
	    for (iter = nodeLinks[visit].rbegin(); iter != nodeLinks[visit].rend(); iter++)
	        if (!visited[*iter])
				s.push(*iter);
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
	// Depth-First-Search
	DFS(I);
}
