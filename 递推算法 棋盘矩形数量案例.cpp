#include<iostream>
using namespace std;
int main() {//递推算法 棋盘数量案例
	int n, m;
	cin >> n >> m;
	int Square = 0, NotSquare = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) {
			//从单位方块开始遍历
			int Chang = n - (i - 1);//长>=1
			int Kuang = m - (j - 1);//宽>=1
				int sum = Chang * Kuang;
      //总所周知：正方形是特殊的矩形
			if (i == j) {//边长相等 即为正方形
				Square += sum;//正方形
			}
			else {
				NotSquare += sum;//长方形
			}
		}
	}
	cout << Square << " " << NotSquare;
		return 0;
}
