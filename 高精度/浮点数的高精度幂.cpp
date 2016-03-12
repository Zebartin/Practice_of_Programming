#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void multi(vector<int> &r, vector<int> s) {
	vector<int> temp(r.size() + s.size());
	for (unsigned i = 0; i<r.size(); ++i)
		for (unsigned j = 0; j<s.size(); ++j)
			temp[i + j] += r[i] * s[j];
	for (unsigned i = 0; i<temp.size(); ++i)
		if (temp[i] >= 10) {
			temp[i + 1] += temp[i] / 10;
			temp[i] %= 10;
		}
	for (unsigned i = temp.size() - 1; i >= 0; --i)
		if (temp[i] == 0)
			temp.erase(temp.begin() + i, temp.begin() + i + 1);
		else
			break;
	r.clear();
	for (int i = 0; i < temp.size(); ++i)
		r.push_back(temp[i]);
}
int main() {
	int m, pointpos;
	string s;
	while (cin >> s) {
		for (int i = s.length() - 1; i >= 0; --i)
			if (s[i] == '0')
				s.erase(i, i + 1);
			else
				break;
		int f = s.find('.');
		if (f != string::npos)
			pointpos = s.length() - f - 1;
		vector<int> result, ts;
		for (int k = s.length() - 1; k >= 0; --k) {
			if (k == f)
				--k;
			if (k >= 0) {
				result.push_back(s[k] - '0');
				ts.push_back(s[k] - '0');
			}
		}
		cin >> m;
		int t = pointpos;
		for (int i = 0; i < m - 1; ++i) {
			multi(result, ts);
			t += pointpos;
		}
		if (t >= result.size()) {
			cout << ".";
			int p = t - result.size();
			while (p--)
				cout << 0;
		}
		for (int i = result.size() - 1; i >= 0; --i) {
			if (i == t - 1)
				cout << ".";
			cout << result[i];
		}
		cout << endl;
	}
	return 0;
}
