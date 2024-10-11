#include<bits/stdc++.h>
using namespace std;
int main() {
	string a;
	cin >> a;
	int r = 0;
	long b = a.size();
	for (long i = 0; i < b; i++) {
		if (a[i] == 'c') {
			if (a[i + 1 ] == 'h') {
				if (a[i + 2] == 'u') {
					if (a[i + 3] == 'a') {
						if (a[i + 4] == 'n') {
							if (a[i + 5] == 'z') {
								if (a[i + 6] == 'h') {
									if (a[i + 7] == 'i') {
										r++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << r;
	system("pause");
	return 0;
}

