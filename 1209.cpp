#include <iostream>
#include <cstring>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int arr[100][100] = { 0 };

int max_arr(int arr[][100]) {
	int max_sum = 0, sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			sum += arr[i][j];
		}
		max_sum = __max(max_sum, sum);
		sum = 0;
	}

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 100; i++) {
			sum += arr[i][j];
		}
		max_sum = __max(max_sum, sum);
		sum = 0;
	}

	int diagonal_sum1 = 0, diagonal_sum2 = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == j) diagonal_sum1 += arr[i][j];
			if (i + j == 99) diagonal_sum2 += arr[i][j];
		}
		max_sum = __max(diagonal_sum1, max_sum);
		max_sum = __max(diagonal_sum2, max_sum);
	}
	return max_sum;
}

int main() {
	int T;
	for(int x = 0; x < 10; x++){
		cin >> T;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = max_arr(arr);
		cout << "#" << T << " " << ans << endl;
		
	}
	return 0;
}