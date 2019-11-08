#include <iostream>
#include <cstring>

using namespace std;

const int x_dir[4] = { -1, 0, 0, 1 };
const int y_dir[4] = { 0, -1, 1, 0 };

class Queue {
private:
	int front, rear;
	const int size = 20;
	char *queue;

public:
	Queue() {
		queue = (char *)malloc(sizeof(char)*size);
		front = rear = 0;
	}

	~Queue() {
		memset(queue, 0, sizeof(char)*size);
		front = rear = 0;
	}
	bool isFull() {
		if ((rear + 1) % size == front)return true;
		else return false;
	}

	bool isEmpty() {
		if (front == rear)return true;
		else return false;
	}

	int enQueue(char data) {
		if (!isFull()) {
			rear = (++rear) % size;
			queue[rear] = data;
			return 1;
		}
		else {
			cout << "Queue is Full" << endl;
			return 0;
		}
	}

	char deQueue() {
		if (!isEmpty()) {
			front = (++front) % size;
			return queue[front];
		}
		else {
			cout << "Queue is Empty" << endl;
			return 0;
		}
	}

	char return_front() {
		char x = queue[(front + 1) % size];
		return x;
	}
};

int solve_maze(char map[][100], Queue x_queue, Queue y_queue) {
	int x = 1, y = 1, nextX, nextY;
	x_queue.enQueue(x);
	y_queue.enQueue(y);
	while (!x_queue.isEmpty()) {
		x = x_queue.return_front();
		y = y_queue.return_front();
		for (int i = 0; i < 4; i++) {
			nextX = x + x_dir[i];
			nextY = y + y_dir[i];
			if (map[nextX][nextY] == '3') {
				return 1;
			}
			else if (nextX >= 0 && nextX < 100 && nextY >= 0 && nextY < 100 && map[nextX][nextY] == '0') {
				x_queue.enQueue(nextX);
				y_queue.enQueue(nextY);
				map[nextX][nextY] = 1;
			}
		}
		x_queue.deQueue();
		y_queue.deQueue();
	}
	return 0;
}


int main() {
	int T;
	char map[100][100] = { 0 }, data;
	Queue x_queue, y_queue;
	for (int i = 1; i < 11; i++) {
		memset(map, 0, sizeof(map));
		cin >> T;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> data;
				map[y][x] = data;
			}
		}
		cout << "#" << i << " " << solve_maze(map, x_queue, y_queue) << endl;
		x_queue.~Queue();
		y_queue.~Queue();
	}
	return 0;
}