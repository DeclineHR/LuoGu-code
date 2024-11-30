//借鉴题解：dbxxx https://www.luogu.com.cn/article/tle6xrur
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn = 5000005;
LL a[maxn];
LL sum = 0;
LL n;	
LL cnt; 
LL s;
bool isP(int a) {//质数：大于1并且只能被1或者其本身相除的数字 
	//质数除了2都是奇数
	if (a <= 1)return false;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {//为偶数
			return false;
		}
	}
	return true;
}
void dfs(int m,LL sum,int startx) {
//m代表现在选择了多少个数 用于取完s个数后结束递归
//sum表示当前的和 在m == s的时候使用isP判断是否为质数
//startx表示升序排列，以免算重 这是每次递归的起点 
	if (m == s) {//递归终点
		if (isP(sum)) cnt++;
		return;
	}
	for (int i = startx; i < n; i++)dfs(m + 1, sum + a[i], i + 1);
	//从 startx 开始遍历数组 a。
	//对于每个索引 i，递归调用 dfs，将 m 增加 1，将 sum 增加 a[i]，并将 startx 设置为 i + 1。
	//这样可以确保每个整数只被选择一次，并且所有可能的组合都会被考虑。
	return;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0);
	cout << cnt;
	return 0;
}
//其实这里的难点是：如何去重？
//答案是：不降原则

//对于数选择的递归
//for (int i = startx; i < n; i++)dfs(m + 1, sum + a[i], i + 1);
//使用 不降原则
//拿6个里面选3个举例子
//startx = 1
//1 2 3
//1 2 4
//1 2 5
//1 2 6
//第一轮枚举完毕。
//第二个数加一
//1 3 ？
//这个“？”应该是4，因为是升序排列
//1 3 4
//1 3 5
//1 3 6
//接着，就是这样
//1 4 5
//1 4 6
//1 5 6
//第一位是1枚举完毕
//第一位是2呢 ?
//startx = 2
//2 3 4
//2 3 5
//2 3 6
//2 4 5
//2 4 6
//2 5 6
//就是这样的，枚举还是蛮清晰的吧
//以此类推.....
//startx = 3
//3 4 5
//3 4 6
//3 5 6
//4 5 6
