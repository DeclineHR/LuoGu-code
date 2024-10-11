#include<bits/stdc++.h>
using namespace std;
int main() {
	long a, b,r;//注意 题目表明a,b 在 32 位有符号整型范围内 要用long
	cin >> a >> b;
	long c = abs(a);
	//sgn(b)函数
	if (b > 0) {
		r = c;
	}
	else {
		r = -c;
	}
	cout << r;
	system("pause");
	return 0;
}

