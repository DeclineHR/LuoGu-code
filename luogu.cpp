#include<bits/stdc++.h>
using namespace std;
int main() {
	string a,b;
	cin >> a;
	int len = a.size();
	double num;
	
	//��ȡ���������
	for (int i = 0; i < len; i++) {
		if (a[i] != 'G' && a[i] != 'M'
			&& a[i] != 'K' && a[i] != 'B')//��ȡ�����ַ���
		{
			b += a[i]; //�ۼӽ��ַ�����ƴ��
			num = stoi(b); //stoi������ת����ȡ���������
		}
	}


	for (int i = 0; i < len; i++) {
		if (a[i] == '=') {
			if (a[i - 2] == 'G')//ǰ��ΪGB
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
			else if (a[i - 2] == 'M') //ǰ��ΪMB
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
			if (a[i - 2] == 'K') //ǰ��ΪKB
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
				|| a[i - 2] != 'K') //ǰ��ΪB
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

