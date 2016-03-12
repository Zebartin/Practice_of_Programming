#include<iostream>
#include<string>
#include<cstring>
#include<memory.h>
using namespace std;
int kn = 1;
class LargeInteger {
	int size;
	int *number;
public:
	LargeInteger(string s) :size(s.length()) {
		number = new int[size];
		for (int i = 0; i < size; i++)
			number[i] = s.at(size - 1 - i) - '0';
	}
	LargeInteger(int n) :size(n) {
		number = new int[size];
		memset(number, 0, size * 4);
	}
	LargeInteger substr(int, int);
	bool operator<(LargeInteger);
	LargeInteger &operator=(LargeInteger);
	LargeInteger &operator+(LargeInteger);
	LargeInteger &operator-(LargeInteger);
	LargeInteger &operator*(LargeInteger);
	LargeInteger &operator/(LargeInteger);
	friend ostream &operator<<(ostream &, LargeInteger);
	friend LargeInteger cat(const LargeInteger &, const LargeInteger &);
};
LargeInteger cat(const LargeInteger &a, const LargeInteger &b) {
	LargeInteger *n = new LargeInteger(a.size + b.size);
	memcpy(n->number, b.number, b.size * 4);
	memcpy(n->number + b.size, a.number, a.size * 4);
	return *n;
}
LargeInteger LargeInteger::substr(int begin, int end) {
	LargeInteger *n = new LargeInteger(end - begin);
	memcpy(n->number, number + begin, n->size * 4);
	return *n;
}
bool LargeInteger::operator<(LargeInteger l) {
	while (!number[size - 1] && size >= 1)
		size--;
	while (!l.number[l.size - 1] && l.size >= 1)
		l.size--;
	if (size != l.size)
		return size < l.size;
	for (int i = size - 1; i >= 0; i--)
		if (number[i] != l.number[i])
			return number[i] < l.number[i];
	return false;
}
LargeInteger &LargeInteger::operator=(LargeInteger l) {
	size = l.size;
	memcpy(number, l.number, size * 4);
	return *this;
}
LargeInteger &LargeInteger::operator+(LargeInteger l) {
	int i, max = size > l.size ? size : l.size;
	LargeInteger *n = new LargeInteger(max + 1);
	for (i = 0; i < size + l.size - max; i++)
		n->number[i] = number[i] + l.number[i];
	for (; i < max; i++)
		if (max == size)
			n->number[i] = number[i];
		else
			n->number[i] = l.number[i];
	for (i = 0; i < max; i++)
		if (n->number[i] >= 10) {
			n->number[i] -= 10;
			n->number[i + 1] += 1;
		}
	return *n;
}
LargeInteger &LargeInteger::operator-(LargeInteger l) {
	int i;
	LargeInteger *n = new LargeInteger(size);
	for (i = 0; i < l.size; i++)
		n->number[i] = number[i] - l.number[i];
	for (; i < size; i++)
		n->number[i] = number[i];
	for (i = 0; i < size; i++)
		if (n->number[i] < 0) {
			n->number[i] += 10;
			n->number[i + 1] -= 1;
		}
	return *n;
}
LargeInteger &LargeInteger::operator*(LargeInteger l) {
	int i, j;
	LargeInteger *n = new LargeInteger(size + l.size);
	for (i = 0; i < size; i++)
		for (j = 0; j < l.size; j++)
			n->number[i + j] += number[i] * l.number[j];
	for (i = 0; i < size + l.size - 1; i++) {
		n->number[i + 1] += n->number[i] / 10;
		n->number[i] %= 10;
	}
	return *n;
}
LargeInteger &LargeInteger::operator/(LargeInteger l) {
	int i, j, m = size - l.size;
	LargeInteger *remainer = new LargeInteger(l.size), *n = new LargeInteger(m + 1);
	*remainer = substr(m, m + l.size);
	for (i = m; i >= 0; i--) {
		for (j = 1; j <= 10; j++) {
			if (*remainer < l)
				break;
			*remainer = *remainer - l;
		}
		j--;
		n->number[i] = j;
		*remainer = cat(*remainer, substr(i - 1, i));
	}
	delete remainer;
	return *n;
}
ostream &operator<<(ostream &o, LargeInteger l) {
	while (!l.number[l.size - 1] && l.size >= 1)
		l.size--;
	if (!l.size)
		cout << 0;
	for (int i = l.size - 1; i >= 0; i--)
		cout << l.number[i];
	return o;
}
int main() {
	string s1, s2;
	char mark;
	cin >> s1 >> mark >> s2;
	LargeInteger n1(s1), n2(s2);
	switch (mark) {
	case '+':cout << n1 + n2 << endl; break;
	case '-': {
		if (n1 < n2)
			cout << "-" << n2 - n1 << endl;
		else
			cout << n1 - n2 << endl;
	} break;
	case '*':cout << n1 * n2 << endl; break;
	case '/': {
		if (n1 < n2)
			cout << 0 << endl;
		else
			cout << n1 / n2 << endl;
	}
	}
	system("pause");
	return 0;
}