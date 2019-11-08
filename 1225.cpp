#include <iostream>
#include <cstring>

using namespace std;

class Queue {
public:
	int front, rear, size = 9;
	int *queue;

	Queue() {
		queue = (int *)malloc(sizeof(int)*size);
		front = rear = 0;
	}

	~Queue() {
		memset(queue, 0, sizeof(int)*size);
		front = rear = 0;
		//delete[] queue;
	}

	void enQueue(int data) {
		if (!isFull()) {
			rear = (++rear) % size;
			queue[rear] = data;
		}
		else cout << "Queue is Full" << endl;
	}

	int deQueue() {
		if (!isEmpty()) {
			front = (++front) % size;
			return queue[front];
		}
		else {
			cout << "Queue is Empty" << endl;
			return 0;
		}
	}

	bool isEmpty() {
		if (front == rear)return true;
		else return false;
	}

	bool isFull() {
		if ((rear + 1) % size == front) return true;
		else return false;
	}

	int return_front() {
		return queue[(front + 1) % size]; // Æ÷ÀÎÆ®!
	}

	int return_rear() {
		return queue[rear];
	}

	void password() {
		int temp, n = 0;
		while (1) {
			if (++n == 6)n = 1;

			if(return_front() - n > 0){
				enQueue(deQueue() - n);
			}
			else {
				deQueue();
				enQueue(0);
				break;
			}
		}
	}

	void print_queue() {
		if (front < rear) {
			for (int i = front + 1; i < rear + 1; i++) {
				cout << queue[i] << " ";
			}
		}
		else {
			for (int i = front + 1; i < 9; i++) {
				cout << queue[i] << " ";
			}
			for (int i = 0; i < rear + 1; i++) {
				cout << queue[i] << " ";
			}
		}
	}
};

int main() {
	int data, num;
	Queue queue;
	for (int T = 1; T < 11; T++) {
		cin >> num;
		for (int i = 0; i < 8; i++) {
			cin >> data;
			queue.enQueue(data);
		}
		queue.password();
		cout << "#" << T << " ";
		queue.print_queue();
		queue.~Queue();
		cout << endl;
	}
	return 0;
}