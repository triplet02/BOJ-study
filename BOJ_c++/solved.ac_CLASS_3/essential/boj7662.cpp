#include<iostream>
#include<algorithm>
#include<set>
#include"solutions.h"

using namespace std;

void boj7662() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int k; cin >> k;
		multiset<int> dpq;

		while(k--) {
			char cmd; int num; cin >> cmd >> num;

			if (cmd == 'I') {
				dpq.insert(num);
			}
			else if(cmd == 'D'){
				if (dpq.size() != 0) {
					if (num == 1) dpq.erase(--dpq.end());
					else dpq.erase(dpq.begin());
				}
			}
		}

		if (dpq.size() != 0) {
			cout << *(--dpq.end()) << ' ' << *dpq.begin() << '\n';
		}
		else cout << "EMPTY\n";
	}
}