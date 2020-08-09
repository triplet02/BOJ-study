#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include"solutions.h"
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {
		// ���̼�
		return a.length() < b.length();
	}
	else { // ���̰� ������
		// ������
		return a < b;
	}
}

class DictSort {
private:
	string list[20001];
	int word_num;

public:
	DictSort() {
		fill_n(list, 20001, NULL);
		word_num = 0;
	}

	void load(string word) {
		list[word_num++] = word;
	}

	void sorting() {
		sort(list, list + word_num, compare);
	}

	void show() {
		for (int i = 0; i < word_num; i++) {
			if (list[i] != list[i + 1]) {
				cout << list[i] << endl;
			}
		}
	}
};


void boj1181() {
	int num;
	cin >> num;
	DictSort dict = DictSort();
	string word;

	for (int i = 0; i < num; i++) {
		cin >> word;
		dict.load(word);
	}
	dict.sorting();
	dict.show();
}