#include<iostream>
#include<algorithm>
#include<cstring>
#include"solutions.h"
using namespace std;

class Coef {
private:
	int N, K;

public:
	Coef(int n, int k) {
		N = n;
		K = k;
	}

	void calc() {
		// n!/(n-k!)k!
		cout << (factorial(N) / (factorial(N - K)*factorial(K))) << endl;
	}

	int factorial(int n) {
		return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
	}
};

void boj11050() {
	int n, k;
	scanf_s("%d %d", &n, &k);

	Coef coef = Coef(n, k);
	coef.calc();
}