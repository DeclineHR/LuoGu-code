#include<iostream>
#include<string>
#include<map>
using namespace std;
int seeing[100005];
string name[100005];
string rank[100005];
int g[100005];
int step[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		seeing[i] = b;//保存朝向
		string a;
		cin >> a;
		name[i] = a;//保存名称
	}
	for (int i = 0; i < m; i++) {
		cin >> g[i] >> step[i];
	}
	int ans = 0;//ans为人员的编号
	for (int i = 0; i < m; i++) {
		if (g[i] == 0 && seeing[ans] == 0) {
			ans += (n - step[i]);
			ans %= (n);
		}
		else if (g[i] != 0 && seeing[ans] == 0) {
			ans += step[i];
			ans %= (n);
		}
		else if (g[i] != 0 && seeing[ans] != 0) {
			ans += (n - step[i]);
			ans %= (n);
		}
		else if (g[i] == 0 && seeing[ans] != 0) {
			ans += step[i];
			ans %= (n);
		}
	}
	cout << name[ans] << endl;
	return 0;
}
