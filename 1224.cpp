#include <iostream>
#include <cstring>

using namespace std;

int getPriority(char op) {
	switch (op) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	}
	return -1;
}

bool compare(char op1, char op2) {
	int x = getPriority(op1), y = getPriority(op2);
	if (x > y) return true;
	else return false;
}

class Stack {
public:
	char *stack, *result;
	int *cal;
	int top, result_top, cal_top, size = 150;

	void InitStack() {
		stack = (char *)malloc(sizeof(char)*size);
		result = (char*)malloc(sizeof(char)*size);
		cal = (int *)malloc(sizeof(int)*size);
		result_top = -1, top = -1, cal_top = -1;
	}

	void Delete() {
		memset(stack, 0, sizeof(char) * size);
		memset(result, 0, sizeof(char) * size);
		memset(cal, 0, sizeof(int) * size);
		result_top = -1, top = -1, cal_top = -1;
	}

	int isFull() {
		if (top == size - 1)return 1;
		else return 0;
	}

	int isEmpty() {
		if (top == -1)return 1;
		else return 0;
	}

	int result_isEmpty() {
		if (result_top == -1)return 1;
		else return 0;
	}

	int cal_isEmpty() {
		if (cal_top == -1)return 1;
		else return 0;
	}

	int Push(char data) {
		if (!isFull()) {
			stack[++top] = data;
			return 1;
		}
		else return 0;
	}

	void Push_result(char data) {
		result[++result_top] = data;;
	}

	void Push_cal(int data) {
		cal[++cal_top] = data;
	}

	char Pop() {
		if (!isEmpty()) {
			return stack[top--];
		}
		else return -1;
	}

	char result_Pop() {
		if (!result_isEmpty())return result[result_top--];
		else return -1;
	}

	int cal_Pop() {
		if (!cal_isEmpty())return (cal[cal_top--]);
		else return 0;
	}

	char Top() {
		if (!isEmpty()) return stack[top];
		else return -1;
	}

	void print_result() {
		for (int i = 0; i < result_top + 1; i++) {
			cout << result[i] << " ";
		}
	}

	void postFix(char ch) {
		if ('0' <= ch && ch <= '9') Push_result(ch);
		else if (isEmpty())Push(ch);
		else {
			switch (ch) {
			case '(':
				Push(ch);
				break;
			case ')':
				while (1) {
					char pop = Pop();
					if (pop == '(')break;
					else Push_result(pop);
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (compare(Top(), ch)) {
					while (!isEmpty()) {
						char pop = Pop();
						if (pop == '(') { 
							Push('(');
							break;
						}
						else Push_result(pop);
					}
					Push(ch);
					break;
				}
				else {
					Push(ch);
					break;
				}
			}
		}
	}
	int calc(char *result) {
		while (*result) {
			int i;
			if (*result >= '0' && *result <= '9' && !result_isEmpty()) {
				i = *result - 48;
				Push_cal(i);
				result++;
			}
			else if (*result == '+') {
				Push_cal(cal_Pop() + cal_Pop());
				result++;
			}
			else if (*result == '-') {
				i = cal_Pop();
				Push_cal(cal_Pop() - i);
				result++;
			}
			else if (*result == '*') {
				Push_cal(cal_Pop() * cal_Pop());
				result++;
			}
			else if (*result == '/') {
				i = cal_Pop();
				Push_cal(cal_Pop() / i);
				result++;
			}
			else {
				result++;
			}
		}
		return cal_Pop();
	}
};

int main() {
	char input;
	Stack rstack;
	rstack.InitStack();
	for (int T = 1; T < 11; T++) {
		int len = 0;
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> input;
			rstack.postFix(input);
		}
		while (!rstack.isEmpty()) rstack.Push_result(rstack.Pop());
		cout << "#" << T << " " << rstack.calc(rstack.result) << endl;
		//rstack.print_result();
		rstack.Delete();
	}
	return 0;
}