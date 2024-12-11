#include<iostream>
#include<string>
using namespace std;
char c[200][200];
char ans[200][200];
int main() {
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cin >> c[i][j];
		}
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			int count = 0;
			if (c[i][j] == '*')ans[i][j] = '*';
			else{
				if (c[i + 1][j + 1] == '*')count++;
				if (c[i - 1][j - 1] == '*')count++;
				if (c[i + 1][j - 1] == '*')count++;
				if (c[i - 1][j + 1] == '*')count++;
				if (c[i + 1][j] == '*')count++;
				if (c[i - 1][j] == '*')count++;
				if (c[i][j + 1] == '*')count++;
				if (c[i][j - 1] == '*')count++;
				ans[i][j] = (count % 10 + '0');// 0 ~ 9的字符
				//'0'是字符'0'的ASCII值，所以number % 10 + '0'实际上是将数字转换为对应的字符。
			}

		}
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
