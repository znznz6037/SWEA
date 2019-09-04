#include <iostream>
#include <string>

//using std::cin;
//using std::cout;
//using std::endl;

using namespace std;

int main() {
	int T = 0, t = 1, cnt = 0, result = 0;
	string word, str;
	while (T++ != 10) {
		cin >> t;
		cin >> str >> word;
		int str_len = str.length();
		int word_len = word.length();
		for (int i = 0; i < word_len - str_len; i++) {
			for (int j = 0; j < str_len; j++) {
				if (word[i + j] == str[j]) cnt++;
			}
			if (cnt == str_len) result++;
			cnt = 0;
		}
		cout << "#" << t << " " << result << endl;
	}
	return 0;
}
