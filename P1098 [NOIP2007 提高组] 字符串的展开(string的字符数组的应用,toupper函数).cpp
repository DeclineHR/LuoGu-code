#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

int p1 , p2, p3;
int main() {
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	for (int i = 0; i + 1 < s.size(); i++) {
		if ((s[i] == '-' && (s[i - 1] < s[i + 1]))) {
			int len = (s[i + 1] - '0') - (s[i - 1] - '0');
			string  insertstr;
			if (s[i - 1] >= 65 && s[i + 1] >= 65) {//满足-前后都是字母 
				s.erase(i, 1);//除去-
				if (p1 == 1) {//小写字母填充
					for (int j = 1; j < len; j++) {
						for (int p = 0; p < p2; p++) {//模拟重复次数
							insertstr += char(s[i - 1] + j);
						}
					}
				}
				else if (p1 == 2) {//大写字母填充
					for (int j = 1; j < len; j++) {
						for (int p = 0; p < p2; p++) {
							insertstr += toupper(char(s[i - 1] + j));//toupper()小写字母转化为大写字母
							//tolower()大写字母转化为小写字母 头文件 cctype
						}
					}
				}
				else if (p1 == 3) {//用*填充
					for (int j = 1; j < len; j++) {
						for (int p = 0; p < p2; p++) {
							insertstr += '*';
						}
					}
				}
				if (p3 == 1) {//正序
					s.insert(i, insertstr);//i为原先-的位置
				}
				else if (p3 == 2) {//倒序
					reverse(insertstr.begin(), insertstr.end());//使用string的reverse函数 翻转字符串
					s.insert(i, insertstr);
				}
			}
			else if ((48 <= s[i - 1] && s[i - 1] <= 57) && (48 <= s[i + 1] && s[i + 1] <= 57)) {//满足-前后都是s数字
				s.erase(i, 1);//除去-
				if (p1 == 3) {//用*填充
					for (int j = 1; j < len; j++) {
						for (int p = 0; p < p2; p++) {//模拟重复次数
							insertstr += '*';
						}
					}
				}
				else {//填充数字
					for (int j = 1; j < len; j++) {
						for (int p = 0; p < p2; p++) {
							insertstr += char(s[i - 1] + j);
						}
					}
				}
				if (p3 == 1) {//正序
					s.insert(i, insertstr);
				}
				else if (p3 == 2) {//倒序
					reverse(insertstr.begin(), insertstr.end());
					s.insert(i, insertstr);
				}
			}

		}
	}
	cout << s << endl;
	return 0;
}
