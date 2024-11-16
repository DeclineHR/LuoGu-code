https://www.bilibili.com/video/BV1kb4y1A7Wf?spm_id_from=333.788.videopod.sections&vd_source=02f6e5314cea9dd0571654ef8f035d6b
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	int a1[210] = { 0 };
	int a2[210] = { 0 };
	int r[210] = { 0 };
	char fuhao = '+';
	if (s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2) {
		swap(s1, s2);//确保s1>s2
		fuhao = '-';
	}
	for (int i = 1; i <= s1.size(); i++) {
		a1[i] = s1[s1.size() - i] - '0';//字符串也是按照0开始排
		//si.size()输出的是元素的个数   si.size() - i代表倒序赋值
	}
	for (int j = 1; j <= s1.size(); j++) {
		a2[j] = s2[s2.size() - j] - '0';
	}
	for (int i = 1; i <= s1.size(); i++) {
		if (a1[i] < a2[i]) {//位数不够要借位
			a1[i] += 10;
			a1[i + 1] -= 1;
		}
		r[i] = a1[i] - a2[i];
	}
	int index = 0;
	for (int i = s1.size(); i > 0; i--) {
		if (r[i] != 0) {
			index = i;
			break;
		}
	}
	if (fuhao == '-') {
		cout << fuhao;
	}
	for (int j = index; j > 0; j--) {
		cout << r[j];
	}
	return 0;
}
