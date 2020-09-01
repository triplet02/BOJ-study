#include<iostream>
#include<algorithm>
#include<stack>
#include"solutions.h"

using namespace std;

void boj11724() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	int answer = 0;

	int** graph = (int**)malloc(sizeof(int*)*N);
	bool* visited = (bool*)malloc(sizeof(bool)*N);
	fill_n(visited, N, false);

	for (int i = 0; i < N; i++) {
		graph[i] = (int*)malloc(sizeof(int)*N);
		fill_n(graph[i], N, 0);
	}

	while (M--) {
		int src, dest;
		cin >> src >> dest;
		graph[src-1][dest-1] = 1;
		graph[dest-1][src-1] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		stack<int> s;
		s.push(i);
		while (s.size()) {
			int curr = s.top(); s.pop();
			for (int j = 0; j < N; j++) {
				if (graph[curr][j] && visited[j] == false) {
					s.push(j);
					visited[j] = true;
				}
			}
		}

		answer++;
	}

	cout << answer << '\n';
}