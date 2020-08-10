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
	target�� ������ �������� üũ�ϸ� �Ҽ����� �� �� �ִٰ� ��.
	�ð� ������ ���ؼ��� �Ʒ� �ڵ带 ����ϴ� �� ���� ��

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