#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int ladder[101][101] = { 0 };
int flag = 0, T = 0, x = 0, y = 0, len = 0, minlen = 10000000, vertex = 0;

int main() {
	while (T < 10) {
		int t;
		cin >> t;
		memset(ladder, 0, sizeof(ladder));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];
			}
		}
		y = 0, x = 0;
		for (int i = 0; i < 100; i++) {
			x = i, y = 0, len = 0;
			flag = 1;
			while (y < 99 && flag) {
				if (x == 0) {
					if (ladder[y][x] == 1 && ladder[y][x + 1] == 1) { // 오른쪽 경로가 있을때. 오른쪽으로 이동
						while (1) {
							if (ladder[y + 1][x] >= 1 && ladder[y][x + 1] == 0) { // 밑으로 이동하는 경로가 나타날 때까지 오른쪽으로 이동
								y++, len++;
								break;
							}
							x++, len++;
						}
					}
					else if (ladder[y][x] == 1 && ladder[y + 1][x] >= 1 && ladder[y][x + 1] == 0) { // 오른쪽 경로가 없을때. 밑으로 이동
						y++, len++;
					}
					else { // 내려가는 경로, 오른쪽 경로 둘 다 없는 경우
						flag = 0, len = 0;
					}
				}
				else if (x == 99) {
					if (ladder[y][x] == 1 && ladder[y][x - 1] == 1) { // 왼쪽으로 가는 경로가 있을 때. 왼쪽으로 이동
						while (1) {
							if (ladder[y + 1][x] >= 1 && ladder[y][x - 1] == 0) { // 밑으로 이동하는 경로가 나타날 때까지 왼쪽으로 이동
								y++, len++;
								break;
							}
							x--, len++;
						}
					}
					else if (ladder[y + 1][x] >= 1 && ladder[y][x - 1] == 0) {
						y++, len++;
					}
					else {
						flag = 0, len = 0;
					}
				}
				else if (0 < x < 99) {
					if (ladder[y][x] == 1 && ladder[y][x - 1] == 0 && ladder[y][x + 1] == 0 && ladder[y + 1][x] >= 1) y++, len++;
					else if (ladder[y][x] == 1 && ladder[y][x + 1] == 1) {
						while (1) {
							if (ladder[y + 1][x] >= 1 && ladder[y][x + 1] == 0) {
								y++, len++;
								break;
							}
							x++, len++;
						}
					}
					else if (ladder[y][x] == 1 && ladder[y][x - 1] == 1) {
						while (1) {
							if (ladder[y + 1][x] >= 1 && ladder[y][x - 1] == 0) {
								y++, len++;
								break;
							}
							x--, len++;
						}
					}
					else flag = 0, len = 0;
				}
			}
			if (y == 99 && ladder[y][x] == 2 && len != 0 ) {
				if(minlen > len) minlen = len;
				vertex = i;
			}
		}
		cout << "#" << t << " " << vertex << endl;
		T++;
	}
	return 0;
}