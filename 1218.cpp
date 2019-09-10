#include <iostream>
#include <cstring>
#define SIZE 1000

using namespace std;

char stack[SIZE] = { 0 };
int top;

int IsEmpty(void) {
	return (top == 0);
}

int IsFull(void) {
	return (top == SIZE);
}

void Push(char n) {
	stack[top] = n;
	++top;
}

void Pop(char* n) {
	--top;
	*n = stack[top];
}

int main() {
	int len = 0;
	char n;
	for (int T = 1; T < 11; T++) {
		int result = 1;
		top = 0;
		memset(stack, 0, sizeof(stack));
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> n;
			if (IsFull())break;
			if (n == '(' || n == '{' || n == '[' || n == '<') Push(n);
			else {
				if (stack[top - 1] == '(' && n == ')' && IsEmpty() == 0) Pop(&n);
				else if (stack[top - 1] == '{' && n == '}' && IsEmpty() == 0) Pop(&n);
				else if (stack[top - 1] = '[' && n == ']' && IsEmpty() == 0) Pop(&n);
				else if (stack[top - 1] = '<' && n == '>' && IsEmpty() == 0) Pop(&n);
				else result = 0;
			}
		}
		cout << "#" << T << " " << result << endl;
	}
	return 0;
}