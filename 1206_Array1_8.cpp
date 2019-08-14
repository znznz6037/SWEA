#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int length;
int building[1000] = { 0 };
int T = 1;
int main() {
	while (T<11) {
		memset(building, 0, sizeof(building));
		int count = 0;
		cin >> length;
		for (int i = 0; i < length; i++) {
			cin >> building[i];
		}
		for (int i = 2; i < length - 2; i++) {
			if (building[i] == 0) continue;
			if (building[i - 2] >= building[i] || building[i - 1] >= building[i] || building[i + 1] >= building[i] || building[i + 2] >= building[i]) continue;
			else {
				while (building[i] >building[i - 2] && building[i] > building[i - 1] && building[i] > building[i + 1] && building[i] > building[i + 2]) {
					count++;
					building[i]--;
				}
			}

		}
		cout << "#" << T << " " << count << endl;
		T++;
	}
	return 0;
}