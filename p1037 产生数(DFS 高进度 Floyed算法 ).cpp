//自己写的DFS 最后3个测试点 TLE MLE 超时 溢出
#include<bits/stdc++.h>
using namespace std;
const long long maxn = 10000005;
string a;
int k;
char v1[maxn];
char v2[maxn];
set<string>ans;
vector<string>s1;
map<string, int>mp;
bool b[maxn];
void dfs(string b,int t) {
	ans.insert(b);
	if (t == k)return;//递归终点
	dfs(b, t + 1);	
		auto it = find(b.begin(), b.end(), v1[t]);
		if(it != b.end()) *it = v2[t];	
		if(binary_search(ans.begin(), ans.end(),b))return;
		if (!mp[b]) { t = 0; mp[b] = 1; dfs(b, t); }
	}
int main() {
	ios::sync_with_stdio(false);
	cin >> a;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v1[i] >> v2[i];
	}
	dfs(a, 0);
	cout << ans.size();
	return 0;
}
//输入
/*
1234 3
2 3
3 2
3 5
*/
//输出9
优化后：：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
