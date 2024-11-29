//二叉树dfs深度搜索 给中序 后序 求前序
//https://www.luogu.com.cn/problem/P1030
//首先，一点基本常识，给你一个后序遍历，那么最后一个就是根（如ABCD，则根为D）。
//因为题目求 先序 ，意味着 要不断 找根。
//中序ACGDBHZKX，后序CDGAHXKZB，首先可找到主根B；
//那么我们找到中序遍历中的B，由这种遍历的性质，可将中序遍历分为ACGD和HZKX两棵子树，
//那么对应可找到后序遍历CDGA和HXKZ（从头找即可）
//从而问题就变成求1.中序遍历ACGD，后序遍历CDGA的树 2.中序遍历HZKX，后序遍历HXKZ的树；
//接着递归，按照原先方法，找到1.子根A，再分为两棵子树2.子根Z，再分为两棵子树。
//模板概括为
//step1:找到根并输出
//step2 : 将中序，后序各分为左右两棵子树；
//step3 : 递归，重复step1, 2；
#include<bits/stdc++.h>
using namespace std;
void tree(string mid, string after) {
	if (mid.size() > 0) {//递归终点
		char treetop = after[after.size() - 1];
		cout << treetop;
		int point = mid.find(treetop);
		//substr(start,count)函数作用解释： start表示获取起点 cout表示要获取的元素个数
		//1.当只有一个参数
		//string test = "abcde";
		//test[0] = 'a'
		//cout << test.substr(1);substr(1)得到 test中1位置后面的所有字符串 输出bcde
		//2.有两个参数test.substr(0,3)得到从test[0]开始的(包括test[0]在内的)后3个字符
		//cout << test.substr(0,3) 输出abc
		tree(mid.substr(0, point), after.substr(0, point));//递归左半子树
		tree(mid.substr(point + 1), after.substr(point, mid.size() - (point + 1)));//递归右半子树
		//mid.size() 是整个中序遍历序列的长度，point 是根节点的位置(由于在数组中 实际要+1)，
		//所以 mid.size() - (point + 1) 就是从根节点的下一个位置到序列末尾的长度，即右子树的长度。
		//右子树的中序遍历是 mid 的剩余部分（从 point + 1 开始）
	}
}
int main() {
	string mid, after;
	cin >> mid;
	cin	>> after;
	tree(mid, after);
}
