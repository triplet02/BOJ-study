#include<iostream>
#include<algorithm>
#include"solutions.h"

#pragma warning(disable : 4996)

using namespace std;

void boj10816() {
	int num; scanf("%d", &num);
	int* list;
	list = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++) {
		scanf("%d", list[i]);
	}

	scanf("%d", num);
	int* cards;
	cards = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++) {
		scanf("%d", cards[i]);
	}
}