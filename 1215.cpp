#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char word[9][9] = { 0 };

int palindrome(vector<char> word, int len, int count) {
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (word[i] == word[len - i - 1]) ans++;
	}
	if (ans == len)	return 1;
	else return 0;
}

int main() {
	vector<char> copy;
	for (int T = 1; T <= 10; T++) {
		int len = 0;
		cin >> len;
		int count = 0;
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				cin >> word[y][x];
			}
		}
		for (int k = 0; k < 8; k++) {
			for (int i = 0; i <= 8 - len; i++) {
				for (int j = 0; j < len; j++) {
					copy.push_back(word[k][i + j]);
				}
				if (palindrome(copy, len, count) == 1)count++;
				copy.clear();
			}
		}
		for (int k = 0; k < 8; k++) {
			for (int i = 0; i <= 8 - len; i++) {
				for (int j = 0; j < len; j++) {
					copy.push_back(word[i + j][k]);
				}
				if (palindrome(copy, len, count) == 1)count++;
				copy.clear();
			}
		}
		cout << "#" << T << " " << count << endl;
	}
	return 0;
}