#include<bits/stdc++.h>
using namespace std;
int main() {
	long n, k;
	int r = 0;
	cin >> n >> k;
	long long * a = new long long[n];//尽量使用最大的
	//如果使用int会报错 使用long 或者 long long 则不会
	for (int p = 0; p < n; p++) {
		cin >> a[p];
	}
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) { //使用倒叙遍历 防止元素相同
											//注意为n - 1  防止越界 
			if ((i < j) && (a[i] * a[j] <= k)) {
				r++;
			}
		}
	}
	cout << r;
	system("pause");
	return 0;
}

