#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include"solutions.h"

#define SIZE 100000

using namespace std;

void boj1697() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	queue<pair<int, int>> q;

	bool visited[SIZE + 1];
	fill_n(visited, SIZE + 1, false);

	int answer;
	q.push({ N, 0 });

	pair<int, int> curr;
	while (q.size()) {
		curr = q.front();
		q.pop();
		//cout << "current value : " << curr.first << " , " << curr.second << '\n';

		if (curr.first == K) {
			answer = curr.second;
			//cout << ">>> Way Found; Length = " << answer << '\n';
			break;
		}

		visited[curr.first] = true;

		if (curr.first - 1 >= 0 && visited[curr.first -1] == false) {
			q.push({ curr.first - 1, curr.second + 1 });
			visited[curr.first -1] = true;
		}
		if (curr.first + 1 <= SIZE && visited[curr.first +1] == false) {
			q.push({ curr.first + 1, curr.second + 1 });
			visited[curr.first +1] = true;
		}
		if (curr.first * 2 <= SIZE && visited[curr.first*2] == false) {
			q.push({ curr.first * 2, curr.second + 1 });
			visited[curr.first * 2] = true;
		}
	}

	cout << answer << '\n';
}