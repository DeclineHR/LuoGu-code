https://www.bilibili.com/video/BV1v5411B71F?spm_id_from=333.788.videopod.sections&vd_source=02f6e5314cea9dd0571654ef8f035d6b
#include<iostream>
#include<algorithm>
using namespace std;
int main() {//贪心算法 打水案例
	int n,r;
	long a[600] = { 0 };//将a[0]初始化为0,其余默认用0填充 实现全部0初始化
	int sum = 0;
	cin >> n >> r;//输入人数n    水龙头数r
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);//将速度最快的排前面
	for (int i = 1; i <= r; i++) {
		sum += a[i];
	}//速度最快的前r个人最先打水
	for (int i = r + 1; i <= n; i++) {
		a[i] = a[i] + a[i - r];//核心规律
		sum += a[i];
	}//r + 1后面的人依次打水
	cout << sum << endl;
		return 0;
}
