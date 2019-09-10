#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int length;
int box[1000] = { 0 };
int T = 1;
int main() {
	while (T<11) {
		memset(box, 0, sizeof(box));
		int count = 0;
		cin >> length;
		for (int i = 0; i < length; i++) {
			cin >> box[i];
		}
		for (int i = 2; i < length - 2; i++) {
			if (box[i] == 0) continue;
			if (box[i - 2] >= box[i] || box[i - 1] >= box[i] || box[i + 1] >= box[i] || box[i + 2] >= box[i]) continue;
			else {
				while (box[i] >box[i - 2] && box[i] > box[i - 1] && box[i] > box[i + 1] && box[i] > box[i + 2]) {
					count++;
					box[i]--;
				}
			}

		}
		cout << "#" << T << " " << count << endl;
		T++;
	}
	return 0;
}