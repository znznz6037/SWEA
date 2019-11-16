#include <iostream>
#include <list>

using namespace std;

int main() {
	int N, n, x, y, s, num;
	char l;
	list<int> password;
	for (int i = 1; i < 11; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) { // 원본 암호문 입력
			cin >> num;
			password.push_back(num);
		}
		cin >> n; // 명령어의 개수
		for (int j = 0; j < n; j++) { //명령어 입력
			cin >> l;
			if (l == 'I') {
				cin >> x >> y;
				list<int>temp;
				for (int k = 0; k < y; k++) {
					cin >> s;
					temp.push_back(s);
				}
				list<int>::iterator iter;
				iter = password.begin();
				while (x > 0) { iter++;	x--; }
				password.splice(iter, temp);
			}
			else if (l == 'D'){
				cin >> x >> y;
				list<int>::iterator iter;
				iter = password.begin();
				while (x > 0) { iter++; x--; }
				for (int a = 0; a < y; a++)password.erase(iter++);
			}
			else if (l == 'A') {
				cin >> y;
				for (int a = 0; a < y; a++) {
					cin >> s;
					password.push_back(s);
				}
			}
		}
		cout << "#" << i << " ";
		for (int a = 0; a < 10; a++) {
			cout << password.front() << " ";
			password.pop_front();
		}
		cout << endl;
		password.clear();
	}
	return 0;
}