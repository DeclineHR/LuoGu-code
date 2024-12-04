https://www.luogu.com.cn/problem/P1007
贪心 其实当两个士兵相遇时
我们可以想象他们对穿了过去
相当于交换了路程 彼此走过了对方的路程
如1 2 3 4
在 1 3 上有士兵
相遇后当作穿过 3向左走3格 1向右走4格
但其实本来是  1向左走3格 3向右走4格
得到最大值
而最小时间便是离岸边最远的士兵的距离
把士兵分为左半和右半 分别距离左岸 右岸最近
  
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int a[5005] = { 0 };
int main() {
	int Length = 0, num = 0;
	int mn = 0, mx = 0;
	cin >> Length >> num;
	int hh = Length / 2;
	int min1 = 0,b = 0,min2 = 0,c = 0,d = 0;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < num; i++) {
		if (a[i] >= Length / 2) {
			mn = max(Length + 1 - a[i], mn);
			mx = max(mx, a[i]);
			
		}
		else {
			mn = max(a[i], mn);
			mx = max(mx, Length + 1 - a[i]);
		}
	}
	cout << mn << " " << mx<< endl;
}
