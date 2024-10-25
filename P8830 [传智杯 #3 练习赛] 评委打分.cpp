优化前：会超时
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	double m = 1.0;
	double result = 0;
	cin >> n;
	int* p = new int[n];
	cin >> p[0];
	cin >> p[1];
	int sum = p[0] + p[1];
	for (int i = 2; i < n; i++) {
		cin >> p[i];
		sum += p[i];
用element 查找最大最小值
		auto max = max_element(p, p + i + 1);
		auto min = min_element(p, p + i + 1);
		result = (sum - *max - *min )/ m;
		printf("%.2lf\n", result);
		m++;
	}
	system("pause");
	return 0;
}
优化后
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	double m = 1.0;
	double result = 0;
	cin >> n;
	int* p = new int[n];
	cin >> p[0];
	cin >> p[1];
	int sum = p[0] + p[1];
	int max_val = max(p[0], p[1]);
	int min_val = min(p[0], p[1]);
	for (int i = 2; i < n; i++) {
		cin >> p[i];
		sum += p[i];动态更新sum 每添加一个新元素则加上 避免浪费时间
		if (p[i] > max_val) max_val = p[i]; 使用if来动态更新最大最小值 避免每一次都查找 浪费时间
		if (p[i] < min_val) min_val = p[i];
		result = (sum - max_val - min_val)/ m;
		printf("%.2lf\n", result);
		m++;
	}
	system("pause");
	return 0;
}
