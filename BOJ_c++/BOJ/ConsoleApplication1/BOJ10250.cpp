#include<iostream>
#include<algorithm>
#include"solutions.h"
using namespace std;

class Hotel {
private:
	int W, H;

public:
	Hotel(int w, int h) {
		W = w;
		H = h;
	}

	void calc(int n) {
		int XX, YY;
		YY = n % H;
		XX = n / H + 1;
		if (YY == 0) {
			YY = H;
			XX = n / H;
		}

		cout << YY * 100 + XX << endl;
	}
};

void boj10250() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int w, h, n;
		scanf_s("%d %d %d", &h, &w, &n);
		Hotel hotel = Hotel(w, h);
		hotel.calc(n);
	}
}