#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int getPriority(char op) {
	switch (op) {
	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;

	case '(':
		return 0;
	}
	return -1;
}

bool compare(char op1, char op2) {
	int x = getPriority(op1), y = getPriority(op2);
	if (x >= y) return true;
	else return false;
}

class Stack {
public:
	char *stack, *result;
	int *cal;
	int top, result_top, cal_top, size = 200;

	void InitStack() {
		stack = (char *)malloc(size);
		result = (char*)malloc(size);
		cal = (int *)malloc(sizeof(int)*size);
		result_top = -1, top = -1, cal_top = -1;
	}

	void Delete() {
		/*free(stack);
		free(result);
		free(cal);*/
		memset(stack, 0, sizeof(char)*200);
		memset(result, 0, sizeof(char) * 200);
		memset(cal, 0, sizeof(int) * 200);
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
		if(!isEmpty()) return stack[top];
		else return -1;
	}

	void print_result() {
		for (int i = 0; i < result_top + 1; i++) {
			cout << result[i] << " ";
		}
	}

	void postFix(char ch) {
		if ('0' <= ch && ch <= '9' && !isFull()) Push_result(ch);
		else if (!isFull()) {
			switch (ch) {
			case '(':
				Push(ch);
				break;
			case ')':
				while (1) {
					if(!isEmpty()) {
						char pop = Pop();
						if (pop == '(')break;
						else Push_result(pop);
					}
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if (compare(Top(), ch)) {
					while (!isEmpty()) Push_result(Pop());
					Push(ch);
					break;
				}
				else {
					Push(ch);
					break;
				}
			default:
				Push_result(ch);
				break;
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
				result ++;
			}
			else if (*result == '-') {
				i = cal_Pop();
				Push_cal(cal_Pop() - i);
				result ++;
			}
			else if (*result == '*') {
				Push_cal(cal_Pop() * cal_Pop());
				result ++;
			}
			else if (*result == '/') {
				i = cal_Pop();
				Push_cal(cal_Pop() / i);
				result ++;
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
		cout << "#" << T << " 후위연산 결과 값 : " << rstack.calc(rstack.result) << endl;
		cout << "후위 연산 결과 식 : ";
		rstack.print_result();
		rstack.Delete();
	}
	return 0;
}