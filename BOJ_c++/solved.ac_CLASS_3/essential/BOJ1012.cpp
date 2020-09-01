#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
#include<queue>
#include<stack>
#include"solutions.h"

using namespace std;

void BFS(int** farm, pair<int, int>coordinate, int M, int N) {
	queue<pair<int, int>> q;
	q.push(coordinate);

	int x_bias[4] = { -1,0,1,0 };
	int y_bias[4] = { 0,-1,0,1 };

	int x, y;

	while (!q.empty()) {
		pair<int, int>coord = q.front(); q.pop();
		x = coord.first; y = coord.second;
		//cout << "[BFS] Current : " << "(" << x << " , " << y << ")\n";
		farm[y][x] = 0;

		for(int i = 0; i < 4; i++) {
			int tmp_x, tmp_y;
			tmp_x = x + x_bias[i];
			tmp_y = y + y_bias[i];
			if (tmp_x<0 || tmp_y<0 || tmp_x>M-1 || tmp_y>N-1)  continue;
			else {
				if (farm[tmp_y][tmp_x] == 1) {
					//cout << "[BFS] 1 found : " << "(" << tmp_x << " , " << tmp_y << ")\n";
					farm[tmp_y][tmp_x] = 0;
					q.push(pair<int, int>(tmp_x, tmp_y));
				}
			}
		}
	}
}

void DFS(int** farm, pair<int, int>coordinate, int M, int N) {
	stack<pair<int, int>> q;
	q.push(coordinate);

	int x_bias[4] = { -1,0,1,0 };
	int y_bias[4] = { 0,-1,0,1 };

	int x, y;

	while (!q.empty()) {
		pair<int, int>coord = q.top(); q.pop();
		x = coord.first; y = coord.second;
		//cout << "[DFS] Current : " << "(" << x << " , " << y << ")\n";
		farm[y][x] = 0;

		for (int i = 0; i < 4; i++) {
			int tmp_x, tmp_y;
			tmp_x = x + x_bias[i];
			tmp_y = y + y_bias[i];
			if (tmp_x<0 || tmp_y<0 || tmp_x>M - 1 || tmp_y>N - 1)  continue;
			else {
				if (farm[tmp_y][tmp_x] == 1) {
					//cout << "[DFS] 1 found : " << "(" << tmp_x << " , " << tmp_y << ")\n";
					farm[tmp_y][tmp_x] = 0;
					q.push(pair<int, int>(tmp_x, tmp_y));
				}
			}
		}
	}
}

void boj1012() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int M, N, K; cin >> M >> N >> K;

		int** farm;
		farm = (int**)malloc(sizeof(int*)*N);

		for (int i = 0; i < N; i++) {
			farm[i] = (int*)malloc(sizeof(int)*M);
			fill_n(farm[i], M, 0);
		}

		int X, Y;

		while (K--) {
			cin >> X >> Y;
			farm[Y][X] = 1;
		}

		int count = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (farm[j][i] == 1) {
					//cout << "[main] 1 found : " << "(" << i << " , " << j << ")\n";
					count++;
					DFS(farm, pair<int, int>(i, j), M, N);
				}
			}
		}

		cout << count << '\n';
	}
}