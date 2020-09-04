#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include"solutions.h"

using namespace std;

string cheat[101][101];

string collosal(string a, string b) {
	string answer;
	string longer = a.length() > b.length() ? a : b;
	string shorter = a.length() > b.length() ? b : a;
	int shorter_len = shorter.length();

	long long int carry = 0;
	while (shorter_len--) {
		long long int sum = (*(longer.end() - 1) - '0') + (*(shorter.end() - 1) - '0') + carry;
		carry = sum / 10;
		sum %= 10;
		answer.push_back(sum + '0');
		longer.pop_back(); shorter.pop_back();
	}

	while (longer.size()) {
		long long int sum = (*(longer.end() - 1) - '0') + carry;
		carry = sum / 10; 
		sum %= 10;
		answer.push_back(sum + '0');
		longer.pop_back();
	}

	if (carry) answer.push_back(carry + '0');

	reverse(answer.begin(), answer.end());

	return answer;
}

void boj2407() {
	int n, m; cin >> n >> m;

	cheat[0][0] = "1";
	cheat[1][0] = "1"; cheat[1][1] = "1";
	cheat[2][0] = "1"; cheat[2][1] = "2"; cheat[2][2] = "1";
	cheat[3][0] = "1"; cheat[3][1] = "3"; cheat[3][2] = "3"; cheat[3][3] = "1";
	cheat[4][0] = "1"; cheat[4][1] = "4"; cheat[4][2] = "6"; cheat[4][3] = "4"; cheat[4][4] = "1";

	for (int i = 5; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) cheat[i][j] = "1";
			else cheat[i][j] = collosal(cheat[i - 1][j - 1], cheat[i - 1][j]);
		}
	}

	cout << cheat[n][m] << '\n';
}