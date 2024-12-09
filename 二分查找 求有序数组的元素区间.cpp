//https://www.bilibili.com/video/BV1fA411z7ru?spm_id_from=333.788.videopod.sections&vd_source=02f6e5314cea9dd0571654ef8f035d6b
//题目 输入一个数组 和要查找的数字
//输出 该数字在数组中的位置 没找到输出 -1
//例：
//输入
//6 3
//1 1 2 2 3 3 4
//3
//4
//5
//输出
//3 4
//5 5
//-1 -1
#include<iostream>
using namespace std;
const int N = 100010;//根据题目范围开略大的数值
int n, q;
int a[N];
int bs1(int* a, int len, int x) {
	int l = -1;
	int r = len;
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		//确定分界线的位置 来设定bool！！
		//如1 3 3 { 4 4 } 5
		//找的是第一个4 则分界限1在 3 4 之间 条件为 < 4
		if (a[mid] < x) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (a[r] == x)return r;
	//如1 3 3 (分界线1) 4 4 (分界线2) 5 分界线1右边为要求的数字4 则返回r
	else return -1;
}
int bs2(int* a, int len, int x) {
	int l = -1;
	int r = len;
	while (l + 1 != r) {
		int mid = (l + r) / 2;
		//找的是第二个4 则分界限2在 4 5 之间 条件为 < 5
		//1 3 3 { 4 4 } 5
		if (a[mid] < x + 1) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (a[l] == x)return l;
	//1 3 3 (分界线1) 4 4 (分界线2) 5 分界线2左边为要求的数字4 则返回l
	else return -1;
}

int main() {

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int b;
		cin >> b;
		int res1 = bs1(a, n, b);//优化：
		//若 res1 = -1 则表明没有这个元素 res2没必要查找了直接输出-1 -1 
		if (res1 == -1) {
			cout << "-1 -1" << endl;
			continue;
		}
		int res2 = bs2(a, n, b);
		cout << res1 << " " << res2 << endl;
	}
	return 0;
}
