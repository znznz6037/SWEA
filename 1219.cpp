#include <iostream>
#include <cstring>

using namespace std;

int graph1[100] = { 0 }, graph2[100] = { 0 }, visit[100] = { 0 }, num = 0, vertex = 0, obj = 0, vnum = 100, result = 0;

void DFS(int v) {
	if (v == 99) {
		result = 1;
		return;
	}
	if (visit[v]) return;
	else visit[v] = 1;

	for (int i = 0; i < num; i++) {
		if (graph1[v] != 0 && !visit[graph1[v]]) DFS(graph1[v]);
		else if (graph2[v] != 0 && !visit[graph2[v]]) DFS(graph2[v]);
		else break;
	}
}

int main() {
	int t;
	for (int T = 1; T < 11; T++) {
		result = 0;
		memset(visit, 0, sizeof(visit));
		memset(graph1, 0, sizeof(graph1));
		memset(graph2, 0, sizeof(graph2));
		cin >> t >> num;
		for (int i = 0; i < num; i++) {
			cin >> vertex >> obj;
			if (graph1[vertex] != 0) graph2[vertex] = obj;
			else graph1[vertex] = obj;
		}
		DFS(0);
		cout << "#" << T << " " << result << endl;
	}
	return 0;
}