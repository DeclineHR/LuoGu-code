https://www.luogu.com.cn/problem/P1003
#include<iostream>
int n;
long long ans[10005][10005] = { 0 };
int x[10005] = {0};
int y[10005] = {0};
int a[10005] = {0};
int b[10005] = {0};
using namespace std;

int main() {
	cin >> n;
	int x2, y2;
	for (int i = 0; i < n; i++) {
		cin >> x[i]>> y[i] >> a[i] >> b[i];
	}
	cin >> x2 >> y2;
	for(int i =0;i <n;i++){
		if (x2 >= x[i] && y2 >=y[i] && (x[i] + a[i]) >= x2 && (y[i] + b[i]) >= y2) {
    //判断地左下角是否小于所求的点  并且是否在地毯覆盖范围  否则直接跳过
			ans[x2][y2] = i + 1;//要求的是最后一块地毯的编号 
		}
	}
	if (ans[x2][y2] == 0) {//全部初始化为0了 题目要求若没有则输出-1
		cout << -1;
		return 0;
	}
	cout << ans[x2][y2];
	return 0;
}
