#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
vector<int>c;
vector<int>d;
int main() {
	int n;
	cin >> n;
	int a, b,e = 1;
	int deep = 0;
	int count = 0;
	while(count < n){
		if (deep % 2 != 0) {
			a = 1;
			b = e;
			while (b >= 1 && a <= e) {
				c.push_back(a);
				d.push_back(b);
				a++;
				b--;
				count++;
			}
		}
	else {//偶
		a = e;
		b = 1;
		while (b <= e && a >= 1) {
			c.push_back(a);
			d.push_back(b);
			a--;
			b++;
			count++;
		}
	}
	deep++;
	e++;
	}
	cout << "count =" << count << endl;
	cout << c[n - 1] << "/" << d[n - 1];
	return 0;
}
