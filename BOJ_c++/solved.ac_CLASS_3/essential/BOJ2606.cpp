#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include"solutions.h"

using namespace std;

void boj2606() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int conn_num; cin >> conn_num;

	// vector 동적 생성
	vector<int>* graph = new vector<int>[N + 1];

	bool* visited;
	visited = (bool*)malloc(sizeof(bool)*(N + 1));

	fill_n(visited, N + 1, false);

	int src, dest;
	while(conn_num--) {
		cin >> src >> dest;
		
		graph[src].push_back(dest);
		graph[dest].push_back(src);
	}

	queue<int> q;
	q.push(1);
	int count = 0;
	int current;

	while (q.size()) {
		current = q.front(); q.pop();
		if (visited[current]) continue;
		visited[current] = true;
		count++;
		for (auto itr = graph[current].begin(); itr != graph[current].end(); itr++) {
			q.push(*itr);
		}
	}

	cout << count-1 << '\n';
}