//실행시간. 시간복잡도 줄이기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char word[101][101] = { 0 };

bool palindrome(vector<char> word, int len) {
	for (int i = 0; i < len / 2; i++) {
		if (word[i] != word[len - i - 1]) return false;
	}
	return true;
}

int main() {
	vector<char> width, height;
	int t;
	for (int T = 1; T <= 10; T++) {
		cin >> t;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> word[y][x];
			}
		}
		int maxlen = 0;
		for (int len = 1; len < 51; len++) {
			for (int k = 0; k < 100; k++) {
				for (int i = 0; i <= 100 - len; i++) {
					for (int j = 0; j < len; j++) {
						width.push_back(word[k][i + j]);
						height.push_back(word[i + j][k]);
					}
					if (palindrome(width, len) || palindrome(height, len)) maxlen = max(maxlen, len);
					width.clear();
					height.clear();
				}
			}
		}
		cout << "#" << T << " " << maxlen << endl;
	}
	return 0;
}
