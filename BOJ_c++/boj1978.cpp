#include<iostream>
#include<algorithm>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

bool check(int num) {
	if (num < 2) return false;

	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}

	/*
	target의 제곱근 값까지만 체크하면 소수인지 알 수 있다고 함.
	시간 단축을 위해서는 아래 코드를 사용하는 게 좋을 듯

	for (int i = 2; i*i < num; i++) {
		if (num % i == 0) return false;
	}
	*/

	return true;
}

void boj1978() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, target; scanf("%d", &num);
	int count = 0;

	while (num--) {
		scanf("%d", &target);
		if (check(target)) count++;
	}

	printf("%d", count);
}