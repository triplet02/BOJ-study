#include<iostream>
#include<algorithm>
#include<cstring>
#include"solutions.h"
using namespace std;

class Check {
private:
	int num;

public:
	Check(int number) {
		num = number;
	}

	void set_number(int number) {
		num = number;
	}

	void calc() {
		if (num == 0) return;

		char arr[6];
		sprintf_s(arr, "%d", num);

		bool check = true;
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] != arr[strlen(arr) - i - 1]) {
				check = false;
				break;
			}
		}
		if (check) cout << "yes" << endl;
		else cout << "no" << endl;
	}
};

void boj1259() {
	int target = -1;
	Check check = Check(target);
	do{
		cin >> target;
		check.set_number(target);
		check.calc();
	} while (target != 0);
}
