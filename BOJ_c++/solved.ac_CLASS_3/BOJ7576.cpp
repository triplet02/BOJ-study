#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<numeric>
#include "solutions.h"

using namespace std;

void i_show_field(vector<vector<int>> field) {
	for (vector<int>line : field){
		for (int each : line) {
			cout << each << ' ';
		}
		cout << '\n';
	}
}

void b_show_field(vector<vector<bool>> visited) {
	for (vector<bool> line : visited) {
		for (bool each : line) {
			cout << each << ' ';
		}
		cout << '\n';
	}
}

void boj7576() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N; cin >> M >> N;

	vector<vector<int>> field;
	vector<vector<bool>> visited;

	queue<vector<pair<int, int>>> q;
	vector < pair<int, int>> bias = { {-1,0},{0,1},{1,0},{0,-1} };

	vector<pair<int, int>> carrier;

	for (int i = 0; i < N; i++) {
		vector<int> i_tmp;
		vector<bool> b_tmp;
		field.push_back(i_tmp);
		visited.push_back(b_tmp);
		for (int j = 0; j < M; j++) {
			int val;
			cin >> val;
			field[i].push_back(val);

			if (val == -1) visited[i].push_back(true);
			else if (val == 1) {
				visited[i].push_back(true);
				carrier.push_back({ i,j });
			}
			else visited[i].push_back(false);
		}
	}
	q.push(carrier);
	//cout << carrier.size() << '\n';
	carrier.clear();

	//cout << "Initial state\n";
	//i_show_field(field);
	

	int count = 0;
	while (q.size()) {
		//cout << "Day " << count + 1 << '\n';
		vector<pair<int, int>> today = q.front(); q.pop();
		for (pair<int, int> point : today) {
			int x = point.first; int y = point.second;
			//cout << "curr : " << x << ", " << y << '\n';
			for (pair<int, int> tuning : bias) {
				int new_x = x + tuning.first; int new_y = y + tuning.second;
				//cout << "check : " << new_x << ", " << new_y << '\n';
				if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
				//cout << "found : " << new_x << ", " << new_y << '\n';
				if (field[new_x][new_y] == 0 && visited[new_x][new_y] == false) {
					carrier.push_back({ new_x, new_y });
					field[new_x][new_y] = 1;
					visited[new_x][new_y] = true;
				}
			}
		}
		//cout << carrier.size() << '\n';
		if (carrier.size()) {
			q.push(carrier);
			count++;
			carrier.clear();
		}
		//i_show_field(field);
	}

	for (vector<bool> line : visited) {
		if (accumulate(line.begin(), line.end(), 0) != M) count = -1;
	}

	cout << count << '\n';
}