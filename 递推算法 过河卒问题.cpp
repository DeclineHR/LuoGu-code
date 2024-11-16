#include<iostream>
using namespace std;
int main() {//递推算法 过河卒案例
	long long n,m,x,y;
	cin >> n >> m >> x >> y;//输入目的地点B坐标 和马的坐标
	long long arr[30][30] = {1};//注意int arr[30][30] = {1};只是把第一个元素赋值为1 其他用0填充
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {//全部初始化1
			arr[i][j] = 1;
		}//注意此处全部赋值为1对边缘以外的其他点没有影响
		//会被arr[i][j] = arr[i][j - 1] + arr[i - 1][j]覆盖
		//1单纯和0做了区别比较 而刚好在无马的情况下边界又都是1条路径
	}
		arr[x][y] = 0;//马
		if (x + 2 <= m && y - 1 >= 0) { arr[x + 2][y - 1] = 0; }//P1点
		if (x + 2 <= m && y + 1 <= n) { arr[x + 2][y + 1] = 0; }//P2点
		if (x + 1 <= m && y + 2 <= n) { arr[x + 1][y + 2] = 0; }//P3点
		if (x - 1 >= 0 && y + 2 <= n) { arr[x - 1][y + 2] = 0; }//P4点
		if (x - 2 >= 0 && y + 1 <= n) { arr[x - 2][y + 1] = 0; }//P5点
		if (x - 2 >= 0 && y - 1 >= 0) { arr[x - 2][y - 1] = 0; }//P6点
		if (x - 1 >= 0 && y - 2 >= 0) { arr[x - 1][y - 2] = 0; }//P7点
		if (x + 1 <= m && y - 2 >= 0) { arr[x + 1][y - 2] = 0; }//P8点
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) {
					continue;
				}//跳过A点本身
				if (arr[i][j] == 0) {
					continue;
				}//已经跳过被马遮挡的点
				if (i == 0) {
					arr[i][j] = arr[i][j - 1];
				}//为arr[i][j] = arr[i][j - 1] + arr[i - 1][j]的变式 确保在边界情况时 i - 1或者j - 1不越界
				else if (j == 0) {
					arr[i][j] = arr[i - 1][j];
				}
				else {
					arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
				}//规律为arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
		cout << arr[n][m];
		return 0;
	}
