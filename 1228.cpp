#include <iostream>
#include <cstring>

using namespace std;

class List {
private:
	class Node {
	public :
		int data;
		Node *next;

		Node() {
			data = 0;
			next = NULL;

		}
		Node(int item) {
			Node * node = new Node();
			data = item;
			next = NULL;
		}
	};

	int count;
	Node *Head = new Node(0);

public:
	List() {
		Head->next = NULL;
		count = 1;
	}

	~List() {
		Node *temp = Head;
		while (temp != NULL) {
			Head = temp->next;
			delete temp;
			temp = Head;
		}
		delete Head;
		count = 1;
	}

	int get(int index) {
		Node *temp = Head;
		for (int i = 1; i <= index; i++)temp = temp->next;
		return temp->data;
	}

	int size() {
		return count;
	}

	void add(int item) {
		Node *newNode = new Node(item);
		if (Head->next == NULL)Head->next = newNode;
		else {
			Node *temp = Head;
			while (temp->next != NULL)temp = temp->next;
			temp->next = newNode;
		}
		count++;
	}

	void add(int item, int index) {
		Node * newNode = new Node(item);
		if (Head->next == NULL)Head->next = newNode;
		else {
			Node *temp = Head;
			for (int i = 1; i <= index; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		count++;
	}
};

int main() {
	int N, n, x, y, s[11], num, item;
	char l;
	for (int i = 1; i < 11; i++) {
		List password;
		cin >> N;
		for (int j = 0; j < N; j++) { // 원본 암호문 입력
			cin >> num;
			password.add(num);
		}

		cin >> n; // 명령어의 개수
		for (int k = 0; k < n; k++) { //명령어 입력
			cin >> l >> x >> y;
			memset(s, 0, sizeof(s));
			for (int a = 0; a < y; a++) cin >> s[a];
			for (int a = y - 1; a >= 0; a--) {
				item = s[a];
				password.add(item, x);
			}
		}
		cout << "#" << i << " ";
		for (int m = 1; m < 11; m++) {
			cout << password.get(m) << " ";
		}
		cout << endl;
		password.~List();
	}
	return 0; 
}