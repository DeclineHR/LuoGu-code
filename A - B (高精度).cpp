https://www.bilibili.com/video/BV1kb4y1A7Wf?spm_id_from=333.788.videopod.sections&vd_source=02f6e5314cea9dd0571654ef8f035d6b
#include<iostream>
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
	for (int i = 0; i < s1.size(); i++) {
		a1[i] = s1[s1.size() - i - 1] - '0';
	}
	for (int j = 0; j < s1.size(); j++) {
		a2[j] = s2[s2.size() - j - 1] - '0';
	}
	for (int i = 0; i < s1.size(); i++) {
		if (a1[i] < a2[i]) {//位数不够要借位
			a1[i] += 10;
			a1[i + 1] -= 1;
		}
		r[i] = a1[i] - a2[i];
	}
	int index = 0;
	for (int i = s1.size(); i >= 0; i--) {
		if (r[i] != 0) {
			index = i;
			break;
		}
	}
	if (fuhao == '-') {
		cout << fuhao;
	}
	for (int j = index; j >= 0; j--) {
		cout << r[j];
	}
	return 0;
}
