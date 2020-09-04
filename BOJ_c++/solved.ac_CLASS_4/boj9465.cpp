#include<iostream>
#include<algorithm>
#include"solutions.h"

using namespace std;

void show_progress(int** answer, int n) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void boj9465() {
	// DPÀÏÁÙÀº... ¤¤¤·¤¡
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;

		int* stickers[2];
		int* answer[3];

		for (int i = 0; i < 2; i++) {
			stickers[i] = (int*)malloc(sizeof(int)*n);
		}
		for (int i = 0; i < 3; i++) {
			answer[i] = (int*)malloc(sizeof(int)*n);
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				int score; cin >> score;
				stickers[i][j] = score;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 0) {
					answer[0][0] = stickers[0][0];
					answer[1][0] = stickers[1][0];
					answer[2][0] = 0;
				}
				else if (i == 1) {
					answer[0][1] = stickers[1][0] + stickers[0][1];
					answer[1][1] = stickers[0][0] + stickers[1][1];
					answer[2][1] = max({ answer[0][0], answer[1][0], answer[2][0] });
				}
				else {
					int none = max({ answer[0][i - 1], answer[1][i - 1], answer[2][i - 1] });
					int past = max({ answer[0][i - 2], answer[1][i - 2], answer[2][i - 2] });
					if (j == 0) {
						answer[j][i] = max({ past, answer[1][i - 1], answer[2][i - 1] }) + stickers[j][i];
					}
					else if (j == 1) {
						answer[j][i] = max({ past, answer[0][i - 1], answer[2][i - 1] }) + stickers[j][i];
					}
					else {
						answer[j][i] = none;
					}
				}
			}
			show_progress(answer, n);
		}

		int ret = max({ answer[0][n - 1], answer[1][n - 1], answer[2][n - 1] });
		cout << ret << '\n';
	}
}