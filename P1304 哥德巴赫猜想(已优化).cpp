https://www.luogu.com.cn/problem/P1304
#include<bits/stdc++.h>
using namespace std; 

bool zhishu(int a) {
  //判断质数
  //质数:大于1 且自身只能被1 和自身整除；
  //众所周知，除了2以外所有质数都是奇数
	for (int i = 2; i <= a - 1; i++) {
		if (a % i == 0) {
				return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	for (int r = 1; r <= (n - 2) / 2; r++) {//轮次
		int b = (2 * r) + 2;
		bool found = false;
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < n; j++) {

				if (zhishu(i) && zhishu(j)) {//i和j是质数
					if ((b == i + j) && (i <= j)) {
						cout << b << "=" << i << "+" << j << endl;
						found = true;//找到i最小的那个等式
					}
				}
				if (found == true) {
					break;//退出到最外层循环
				}
			}
			if (found == true) {
				break;//退出最外层循环
			}
		}
	}
	return 0;
}

优化后代码：

#include<bits/stdc++.h>
using namespace std; 

bool zhishu(int a) {
	for (int i = 2; i * i <= a; i++) {//变动1：只枚举到sqrt(a),即 i <= sqrt(a) 节省时间
		if (a % i == 0) {
				return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	for (int r = 1; r <= (n - 2) / 2; r++) {//轮次
		int b = (2 * r) + 2;
		bool found = false;
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < n; j++) {
					if ((b == i + j) && (i <= j) && zhishu(i) && zhishu(j)) {
						//变动2：将质数判断循环合并实现尽可能的少出现循环
						cout << b << "=" << i << "+" << j << endl;
						found = true;
					}
				}
				if (found == true) {
					break;
				}
			}
		if (found == true) {
			break;
		}
	}
	return 0;
}
