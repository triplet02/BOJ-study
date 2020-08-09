#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<cstring>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

bool check(string str) {
	stack<char> stack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') stack.push(str[i]);
		else {
			if (stack.empty()) return false;
			if (stack.top() == '(') {
				stack.pop();
			}
			else return false;
		}
	}
	if (stack.empty()) return true;
	else return false;
}

void boj9012() {
	int num; scanf("%d", &num); getchar();
	string target;

	bool* list;
	list = (bool*)malloc(sizeof(bool)*num);

	for (int i = 0; i < num; i++) {
		getline(cin, target);
		list[i] = check(target);
	}

	for (int i = 0; i < num; i++) {
		if (list[i]) printf("YES\n");
		else printf("NO\n");
	}
}