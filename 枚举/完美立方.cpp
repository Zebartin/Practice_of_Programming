#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a;
	for (int i = 6; i <= a; i++)
		for (b = 2; b < i; b++)
			for (c = b; c < i; c++)
				for (d = c; d < i; d++)
					if (i*i*i == b*b*b + c*c*c + d*d*d)
						cout << "Cube = " << i << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
	return 0;
}
