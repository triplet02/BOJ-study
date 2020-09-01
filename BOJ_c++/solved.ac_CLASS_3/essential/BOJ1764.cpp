#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

void boj1764() {
	ios_base::sync_with_stdio(false); // �̰� �ϰ� ���� cin, cout�� printf, scanf ���� ȥ���ϸ� �ȵ�!
									  // �� ������ ��� �մϴ�... �̰Ŷ����� �󸶳� ����Ѱ���
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	set<string> hear;
	set<string> see;
	
	string tmp;

	while (N--) {
		cin >> tmp;
		hear.insert(tmp);
	}

	while (M--) {
		cin >> tmp;
		see.insert(tmp);
	}

	vector<string> container(hear.size()+see.size());

	auto itr = set_intersection(hear.begin(), hear.end(), see.begin(), see.end(), container.begin());
	container.erase(itr, container.end());

	set<string> answer;

	for (auto itr = container.begin(); itr != container.end(); itr++) {
		answer.insert(*itr);
	}
	
	cout << answer.size() << '\n';
	for (auto itr = answer.begin(); itr != answer.end(); itr++) {
		cout << *itr << '\n';
	}

}

void _boj1764() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; scanf("%d", &N); scanf("%d", &M); getchar();

	set<string> hear;
	set<string> answer;

	string tmp;

	while (N--) {
		cin >> tmp;
		hear.insert(tmp);
	}

	while (M--) {
		cin >> tmp;
		if (binary_search(hear.begin(), hear.end(), tmp)) {
			answer.insert(tmp);
		}
	}

	cout << answer.size() << '\n';
	for (auto itr = answer.begin(); itr != answer.end(); itr++) {
		cout << *itr << '\n';
	}
}