#include <iostream>
#include <string>
#include <vector>
using namespace std;
void add(vector<int> &a, vector<int> &b) {
	vector<int> r;
	for (int i = 0;; ++i) {
		if (i<b.size() && i<a.size())
			r.push_back(a[i] + b[i]);
		else if (i<b.size() && i >= a.size())
			r.push_back(b[i]);
		else if (i<a.size() && i >= b.size())
			r.push_back(a[i]);
		else
			break;
	}
	for (int i = 0; i<r.size() - 1; ++i)
		if (r[i] >= 10) {
			r[i] -= 10;
			r[i + 1] += 1;
		}
	if (r[r.size() - 1] >= 10) {
		r.push_back(1);
		r[r.size() - 2] -= 10;
	}
	a.assign(r.begin(), r.end());
}
int main() {
	string sLargeInteger;
	vector<int> iLargeInteger,t(1,0);
	vector<vector<int> > vLargeInteger;
	cin >> sLargeInteger;
	while (sLargeInteger != "0") {
		for (int i = 0; i < sLargeInteger.length(); ++i)
			if (sLargeInteger[i] == '0') {
				sLargeInteger.erase(i, i + 1);
				i--;
			} else
				break;
		for (int i = sLargeInteger.length() - 1; i >= 0; --i)
			iLargeInteger.push_back(sLargeInteger[i] - '0');
		add(t,iLargeInteger);
		iLargeInteger.clear();
		cin >> sLargeInteger;
	}
	for (int i = t.size() - 1; i >= 0; --i)
		cout << t[i];
	cout<<endl;
	return 0;
}
