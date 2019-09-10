#include <iostream>

using namespace std;

int power(int n, int exp) {
	if (exp == 1)return n;
	else
		return n * power(n, --exp);
}

int main() {
	int T, n, exp = 0;
	for (int i = 1; i < 11; i++) {
		cin >> T >> n >> exp;
		cout << "#" << T << " " << power(n, exp) << endl;
	}
	return 0;
}