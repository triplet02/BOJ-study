#include <iostream>
#include <algorithm>
#include"solutions.h"
using namespace std;

class Rectangle {
private:
	int now_x, now_y, rect_x, rect_y;

public:
	Rectangle(int x, int y, int w, int h) {
		now_x = x;
		now_y = y;
		rect_x = w;
		rect_y = h;
	}

	void calc(void) {
		int min;

		int arr[4];
		arr[0] = now_x;
		arr[1] = now_y;
		arr[2] = rect_x - now_x;
		arr[3] = rect_y - now_y;

		min = *min_element(arr, arr + 4);
		cout << min;
	}
};



void boj1085()
{
	int x, y, w, h;

	scanf_s("%d %d %d %d", &x, &y, &w, &h);

	Rectangle rect = Rectangle(x, y, w, h);
	rect.calc();
}
