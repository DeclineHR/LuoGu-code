#include<bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	cin >> a;
	int len = a.size();
	double num;
	
	//获取输入的数字
	for (int i = 0; i < len; i++) {
		if (a[i] != 'G' && a[i] != 'M'
			&& a[i] != 'K' && a[i] != 'B')//获取数字字符串
		{
			b += a[i]; //累加将字符数字拼接
			num = stoi(b); //stoi函数来转化获取输入的数字
		}
	}


	for (int i = 0; i < len; i++) {
		if (a[i] == '=') {
			if (a[i - 2] == 'G')//前面为GB
			{
				if (a[len - 2] == 'G') {
					double r1 = num;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'M') {
					double r1 = num * 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'K') {
					double r1 = num * 1024.0 * 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else {
					double r1 = num * 1024.0 * 1024.0 * 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
			}
			else if (a[i - 2] == 'M') //前面为MB
			{
				if (a[len - 2] == 'G') {
					double r1 = num / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'M') {
					double r1 = num;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'K') {
					double r1 = num * 1024;
					printf("%.6lf", r1);
					return 0;
				}
				else {
					double r1 = num * 1024 * 1024;
					printf("%.6lf", r1);
					return 0;
				}
			}
			if (a[i - 2] == 'K') //前面为KB
			{
				if (a[len -2] == 'G') {
					double r1 = (num / 1024.0) / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'M') {
					double r1 = num / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'K') {
					double r1 = num;
					printf("%.6lf", r1);
					return 0;
				}
				else {
					double r1 = num * 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
			}
			if (a[i - 2] != 'G' || a[i - 2] != 'M'
				|| a[i - 2] != 'K') //前面为B
			{
				if (a[len - 2] == 'G') {
					double r1 = num / 1024.0 / 1024.0 / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'M') {
					double r1 = num / 1024.0 / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else if (a[len - 2] == 'K') {
					double r1 = num / 1024.0;
					printf("%.6lf", r1);
					return 0;
				}
				else {
					double r1 = num;
					printf("%.6lf", r1);
					return 0;
				}
			}
		}
	}
	system("pause");
	return 0;
}

