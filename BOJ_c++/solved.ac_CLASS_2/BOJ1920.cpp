#include<iostream>
#include<algorithm>
#include<vector>

#pragma warning(disable : 4996)

using namespace std;

void boj1920() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int list_len, target_len, target;
	scanf("%d", &list_len);

	vector<int> list(list_len);

	for (int i = 0; i < list_len; i++) {
		scanf("%d", &list[i]);
	}

	sort(list.begin(), list.end());

	scanf("%d", &target_len);

	while(target_len--) {
		scanf("%d", &target);
		printf("%d\n", binary_search(list.begin(), list.end(), target));
	}
}
