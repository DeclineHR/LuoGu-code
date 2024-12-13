https://www.luogu.com.cn/problem/P1009
//细节： 1! = 1
//细节： 2! = 1! * 2
//细节： 3! = 2! * 3
//细节： 4! = 3! * 4
//则可以从1的阶乘开始算起
//开一个结果数组result[]保存1结果
//创建一个b[]数组得到2!的结果 加给结果数组 
//然后在用b[]数组算下一个阶乘 即 n! = b[n - 2] * n 
//开一个a[]保存数组n
//开一个c[]保存相乘获得的临时结果 处理高精度相乘的问题
//其中b[n - 2]为 (n - 1)!的结果
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[200], b[200], c[600], result[200];
int lena;
int temp;
int m = 1;
int lenb = 1;
int lenc = 1;
int lenans = 0;
int num;

int main() {
	cin >> num;
	b[0] = 1;
	for (int i = 1; i <= num; i++) {//计算i的阶乘 已经计算好了i - 1的阶乘
		lena = 0;//重置lena为0
		int p = i;//下个阶乘
		while (p > 0) {//获取p的每个位的数字 倒叙存储
			a[lena++] = p % 10;
			p /= 10;
		}
		for (int n1 = 0; n1 < lena; n1++) {
			for (int n2 = 0; n2 < lenb; n2++) {
				c[n1 + n2] += a[n1] * b[n2];//实现相乘  初始化b[0] = 1; 
				//b[]数组为 i  - 1阶乘后的结果 
			}
		}
		//高精度乘法核心
		for (int t = 0; t < lenc; t++) {//处理进位问题
			c[t + 1] += c[t] / 10;
			//如果c[t] > 10,返回>1的数,则会进位
			//否则<1的小数，在int里小数会被隐藏
			c[t] %= 10;//确保c[t] < 10;
		}
		if (c[lenc])lenc++;//判断最高位是否进位
		temp = lenb, lenb = lenc, lenans = max(m, lenc);
		// 把c存进b数组，即存进i - 1的阶乘，下次循环b为i的阶乘
		for (int k = lenc - 1; k >= 0; k--) b[k] = c[k];
		lenc = lena + temp;
		//将 lenc 设置为 a 数组的长度加上 b 数组的长度。
		//这里的逻辑是基于两个数组相乘时，结果的位数最多是两个数组长度之和。
		//用于判断下一次该位置是否进位了
		memset(c, 0, sizeof(c)); //清零c数组，准备计算下个阶乘

		//高精相加核心
		for (int j = 0; j < lenans; j++) {
			result[j] += b[j];
			if (result[j] > 9) result[j + 1] += result[j] / 10, result[j] %= 10;
		}
	}
	for (int i = lenans; i >= 0; i--) cout << result[i]; //倒序输出
	return 0;
}
