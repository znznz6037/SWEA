#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int box[100] = { 0 };

int main() {
	for (int T = 1; T <= 10; T++) {
		int dump;
		cin >> dump;
		for (int i = 0; i < 100; i++) {
			cin >> box[i];
		}
		int max_height = 0, min_height = 100, max_index = 0, min_index = 0;
		while (dump--) {
			max_height = 0, min_height = 100;
			for (int i = 0; i < 100; i++) {
				if (max_height <= box[i]) {
					max_height = box[i];
					max_index = i;
				}
				if (min_height >= box[i]) {
					min_height = box[i];
					min_index = i;
				}
			}
			box[max_index]--;
			box[min_index]++;
		}
		for (int i = 0; i < 100; i++) {
			if (max_height <= box[i]) {
				max_height = box[i];
				max_index = i;
			}
			if (min_height >= box[i]) {
				min_height = box[i];
				min_index = i;
			}
		}
		cout << "#" << T << " " << box[max_index] - box[min_index] << endl;
	}
	return 0;
}