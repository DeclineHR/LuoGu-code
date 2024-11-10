#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int x = 1, y = 1, i = 1;
	int  n;
	int a[10][10] = {0};
	cin >> n;
	for (int b = 1; b <= n + 1; b++) {
		if (i == n * n) {//最后一个数字
			a[x][y] = i;
			break;
		}
		else {
			//每次循环判断下一个数字
			while (y != n && a[x][y + 1] == 0) {//右移
				a[x][y] = i;
				i++;
				y++;
			}
			while (x != n && a[x + 1][y] == 0) {//下移
				a[x][y] = i;
				i++;
				x++;
			}
			while (y != 1 && a[x][y - 1] == 0) {//左移
				a[x][y] = i;
				i++;
				y--;
			}
			while (x != 1 && a[x - 1][y] == 0) {//上移
				a[x][y] = i;
				i++;
				x--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%3d", a[i][j]);//使用printf使数字占三个字符
		}
		cout << endl;
	}
	return 0;
}
