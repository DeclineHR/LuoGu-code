#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 0;
	int ans2 = 0;
	int t = 0;
	for (int i = 0; i < s.size(); i++) {
    //ans记录从起点开始 转化为010101...的代价
    //ans2记录转化为101010...的代价
		if (s[i] == t + '0') ans += i + 1;
		if (s[i] != t + '0') ans2 += i + 1;//代价为i + 1
		t = !t;//一开始t = 0 取反后得到1 来回往复
    //t + '0' : 
    //当 t = 1,   t + '0'得到'1'
    //当 t = 0,   t + '0'得到'0' 
	}
	cout << min(ans, ans2);
	return 0;
}
