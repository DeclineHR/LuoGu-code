#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int a[2000] ={0}, b[2000] = {0}, c[6000] = {0};
	char ch;
	int i = 0;
	int j = 0;
	bool flag = 0;
	while (scanf_s("%c", &ch) && ch != '\n') {
		a[i++] = ch - 48;//-48（'0'）形成数字保存
	}
	while (scanf_s("%c", &ch) && ch != '\n') {
		b[j++] = ch - 48;
	}
	//注意！！！！！：
	//由于洛谷每行输入的数字最后是空格所以应该往前移动两个
	//如123456 \n
	i--; j--;//将ij从指向\n变成指向最后一个数字
	i--; j--;//将ij从指向\n变成指向最后一个数字
	for (int n1 = 0; n1 <= j; n1++) {
		for (int n2 = 0; n2 <= i; n2++) {
			c[n1 + n2] += a[i - n2] * b[j - n1];
			//使用编译器进行乘法最重要的关键就是
			//乘积的下标正好等于两个乘数下标相加之和！
			//这也就是实现错位相加的核心原理。
		}
	}
	for (int t = 0; t < 5999; t++) {//处理进位问题
		c[t + 1] += c[t] / 10;
		//如果c[t] > 10,返回>1的数,则会进位
		//否则<1的小数，在int里小数会被隐藏
		c[t] %= 10;//确保c[t] < 10;
	}
	for (int p = 5999; p >= 0; p--) {
		//输出
		if (c[p]) { flag = 1; }
		if (flag) { cout << c[p]; }
	}
	if (!flag) printf("0");//如果整个乘积结果为0，则输出0。
	cout << " ";
	return 0;
}
