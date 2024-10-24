#include<iostream>
using namespace std;
int main() {
	char arr[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
		'P','Q','R','S','T','U','V','W','X','Y','Z' };
	int n;
	cin >> n;
	int b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = b; j <= b + i; j++) {//确保从上一行最后一个字母开始输出
			cout << arr[j % 26];
		}
		b += i + 1;
		cout << endl;
		
		
	}

	system("pause");
	return 0;
	}
