https://ac.nowcoder.com/acm/contest/98215/E
注意此题为两点之间的线段过的轴   而不是两点的直线
#include<iostream>
using namespace std;
int main() {
	long long n = 0, a = 0, b = 0, c = 0, d = 0, x = 0, y = 0;
	cin >> n;
	while (n-- && cin >> x >> y) { 
		(x > 0) ? (  (y > 0) ? (b++) : (d++)  ) : ((y > 0) ? (a++) : (c++));
		//先判断x是否大于0 再判断y是否大于0  
		//1. x > 0 y > 0 b++ 第一象限
		//2. x > 0 y < 0 d++ 第四象限
		//3. x < 0 y > 0 a++ 第二象限
		//4. x < 0 y < 0 c++ 第三象限
	}	
		//我们优先将不同象限的点配对，因为这样可以确保每对点的权值最大为2。
		//ad为24 象限 b c为13象限 权值为2 优先配对(min(a, d) + min(b, c) ) * 2
		//二四象限剩下的点为max(a, d) - min(a, d)
		//一三象限剩下的点为max(b, c) - min(b, c)
		//剩下的点 任意两点都只能形成1权值 因为是相邻象限
		//形成的线段只过一条轴
	cout << (min(a, d) + min(b, c) ) * 2 + min(max(a, d) - min(a, d), max(b, c) - min(b, c));
	return 0;
}
