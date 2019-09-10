#include <iostream>

using namespace std;

int T, N, x, max, max_points;
int points[101] = { 0 };
int main() {
	cin >> T;
	while (T--) {
		memset(points, 0, sizeof(points));
		cin >> N;
		for (int i = 0; i < 1000; i++) {
			cin >> x;
			points[x]++;
		}
		max = 0;
		for (int i = 0; i < 101; i++) {
			if (points[i] >= max) {
				max = points[i];
				max_points = i;
			}
		}
		cout << "#" << N << " " << max_points << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <fstream>

using namespace std;

int T, N, x, max, max_points;
int points[101] = { 0 };
int main() {
	ifstream stream;
	stream.open("input.txt");
	if (stream.is_open()) {
		stream >> T;
		while(T--){
			memset(points, 0, sizeof(points));
			stream >> N;
			for (int i = 0; i < 1000; i++) {
				stream >> x;
				points[x]++;
			}
			max = 0;
			for (int i = 0; i < 101; i++) {
				if (points[i] >= max) {
					max = points[i];
					max_points = i;
				}
			}
			cout << "#" <<  N << " " << max_points << endl;
		}
	}
	stream.close();
	return 0;
}*/