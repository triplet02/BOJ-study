#include<iostream>
#include<algorithm>
#include<stack>
#include"solutions.h"

using namespace std;

void DFS(int** graph, int* count, int node, int N) {
	bool flag = false;
	stack<int> q;

	q.push(node);
	while (q.size()) {
		int current = q.top(); q.pop();
		for (int j = 0; j < N; j++) {
			if (graph[current][j] == 1) {
				if (!flag) flag = true;
				q.push(j);
				graph[current][j] = 0;
				graph[j][current] = 0;
			}
		}
	}
	if(flag) *count += 1;
}

void boj11724() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	
	int** graph;
	graph = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int)*N);
		fill_n(graph[i], N, 0);
	}

	int src, dest;
	while (M--) {
		cin >> src >> dest;
		graph[src - 1][dest - 1] = 1;
		graph[dest - 1][src - 1] = 1;
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		DFS(graph, &count, i, N);
	}	

	cout << count << '\n';
}