https://www.luogu.com.cn/problem/P1601?contestId=204562
#include<iostream>
#define Len 10000
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	long c[Len] = {0}, d[Len] = {0};
	for (int i = 0; i < a.size(); i++) {
		c[i] = a[a.size() - i - 1] - '0';
		//极其重要：字符a中得到的是字符数字要减去字符0来得到数字
	}
	for (int i = 0; i < b.size(); i++) {
		d[i] = b[b.size() - i - 1] - '0';
	}
	int size1;
	a.size() >= b.size() ? (size1 = a.size()) : (size1 = b.size());
	//三目运算符 如果前面成立 执行 ？后面的 如果不成立执行：后面的
	long e[Len] = {0};
	for (int j = 0; j < size1; j++) {
		e[j] += c[j] + d[j];//极其重要：此处为+=而不是 =
		//在if判断里面的e[j + 1] += 1;即为下次循环的e[j]避免覆盖要用+=
		 if (e[j] >= 10) {
			e[j + 1] += 1;
			e[j] %= 10;
		}
	}
	a.size() >= b.size() ? (size1 = a.size()) : (size1 = b.size());
	if (e[max(a.size(), b.size())] == 1) {
		size1++;
	}//极其重要：会判断当最大的位数的进1了要扩大位数
	for (int p = size1 - 1; p >=0; p--) {
		cout << e[p];
	}
	return 0;
}
