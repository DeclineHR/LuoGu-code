#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, v, m, a;
	cin >> n >> v >> m >> a;
	int sum1 = v;
	int sum2 = 0;
	for (int i = 1; i <= n; i++) {//限量n份
		sum2 += sum1;//每份
		if (i % m == 0) {//注意前后顺序 卖完再加价
			sum1 += a;
		}
	}
	cout << sum2;
	system("pause");
	return 0;
}

