https://www.luogu.com.cn/problem/P1042
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char a;
int ans5[6500] = { 0 };
int ans6[6500] = { 0 };
int ans7[6500] = { 0 };
int ans8[6500] = { 0 };
int main() {
	int g = 0;
	int k = 0;
	while (1) {
		cin >> a;
		if (a == 'E') break;
		if (a == '\n')continue;
		if (a == 'W') {
			ans5[g]++;
			ans7[k]++;
		}
		else {
			ans6[g]++;
			ans8[k]++;
		}
//细节！！！：
题目说 如果一局比赛刚开始，则此时比分为 0 比 0。 那么当刚好比完后 出现E 则应该输出下一场的0：0
使用该判断可以准确的表明该状态
		if ((ans5[g] >= 11 || ans6[g] >= 11) && (abs(ans5[g] - ans6[g]) >= 2)) g++;
		if ((ans7[k] >= 21 || ans8[k] >= 21) && (abs(ans7[k] - ans8[k]) >= 2)) k++;
	}

	for(int i = 0;i <= g;i++){
		cout << ans5[i] << ":" << ans6[i] << endl;
	}
	cout << endl;
	for (int j = 0; j <= k; j++) {
		cout << ans7[j] << ":" << ans8[j] << endl;
	}
	return 0;
}
