#include<iostream>
#include<algorithm>
#include<string>
#include"solutions.h"

using namespace std;

class Calculator {
private:
	int x, y;
	int LCM, GCD;

public:
	Calculator(int a, int b) {
		x = a;
		y = b;
	}

	int getLCM() {
		return (x*y) / GCD;
	}

	int getGCD(int a, int b) {
		int m, n;
		if (a >= b) {
			m = a;
			n = b;
		}
		else {
			n = a;
			m = b;
		}
		return (m % n == 0) ? n : getGCD(n, m % n);
	}

	void compute() {
		GCD = getGCD(x, y);
		LCM = getLCM();

	}

	void show() {
		cout << GCD << endl << LCM << endl;
	}
};

void boj2609() {
	int x, y;
	scanf_s("%d %d", &x, &y);

	Calculator cal = Calculator(x, y);
	cal.compute();
	cal.show();
}