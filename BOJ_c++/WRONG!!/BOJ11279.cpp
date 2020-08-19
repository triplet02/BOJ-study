#include<iostream>
#include<algorithm>
#include<utility>
#include"solutions.h"

#define HEAP_SIZE 100000
#define INF 2147483648

using namespace std;

class MaxHeap {
private:
	int heap[HEAP_SIZE +1];
	int count = 0;

public:
	MaxHeap(void){
		heap[0] = INF;
	}

	void push(int n) {
		if (count < HEAP_SIZE) {
			heap[++count] = n;
		}

		int child = count;
		int parent = child / 2;

		while ( child > 1 && (heap[child] > heap[parent])) {
			swap(heap[child], heap[parent]);
			child = parent;
			parent = child / 2;
		}
	}

	int pop() {
		if (count == 0) return 0;

		int ret = heap[1];
		swap(heap[1], heap[count--]);

		int parent = 1;
		int left = parent * 2;
		int right = left + 1;

		while ((parent < count) && (heap[parent] < heap[left] || heap[parent] < heap[right])) {
			if (heap[parent] < heap[left]) {
				swap(heap[parent], heap[left]);
				parent = left;
				left = parent * 2;
				right = left + 1;
			}
			else {
				swap(heap[parent], heap[right]);
				parent = right;
				left = parent * 2;
				right = left + 1;
			}
		}

		return ret;
	}

};


void boj11279() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int max_heap[HEAP_SIZE];

	int N, cmd; cin >> N;
	int count = 0;

	MaxHeap mh = MaxHeap();

	while (N--) {
		cin >> cmd;
		if (cmd == 0) {
			cout << mh.pop() << '\n';
		}
		else {
			mh.push(cmd);
		}
	}
}