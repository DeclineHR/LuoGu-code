https://www.luogu.com.cn/problem/solution/P1328
#include<iostream>
using namespace std;
int arule[300];
int brule[300];
int ascore = 0;
int bscore = 0;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> arule[i];
	}
	for (int j = 0; j < b; j++) {
		cin >> brule[j];
	}
	// 0 < 4
	// 0 < 1
	// 0 > 2
	// 0 > 3
	// 1 < 2
	// 1 < 4
	// 
	// 1 > 3
	// 2 < 3
	// 2 > 4
	// 3 > 4
	for (int i = 0; i < n; i++){
			if (arule[i % (a)] == 0 && (brule[i % (b)] == 1 || brule[i % (b)] == 4)) {
				bscore++;
			}
			else if (brule[i % (b)] == 0 && (arule[i % (a)] == 1 || arule[i % (a)] == 4)) {
				ascore++;
			}
			else if (arule[i % (a)] == brule[i % (b)]) {
				continue;
			}
			else if (arule[i % (a)] == 0 && (brule[i % (b)] == 2 || brule[i % (b)] == 3)) {
				ascore++;
			}
			else if (brule[i % (b)] == 0 && (arule[i % (a)] == 2 || arule[i % (a)] == 3)) {
				bscore++;
			}
			else if (arule[i % (a)] == 1 && (brule[i % (b )] == 2 || brule[i % (b)] == 4)) {
				bscore++;
			}
			else if (brule[i % (b)] == 1 && (arule[i % (a )] == 2 || arule[i % (a)] == 4)) {
				ascore++;
			}
			else if (arule[i % (a )] == 1 && (brule[i % (b)] == 3)) {
				ascore++;
			}
			else if (brule[i % (b)] == 1 && (arule[i % (a)] == 3)) {
				bscore++;
			}
			else if (arule[i % (a )] == 2 && (brule[i % (b)] == 3)) {
				bscore++;
			}
			else if (brule[i % (b)] == 2 && (arule[i % (a)] == 3)) {
				ascore++;
			}
			else if (arule[i % (a)] == 2 && (brule[i % (b)] == 4)) {
				ascore++;
			}	
			else if (brule[i % (b)] == 2 && (arule[i % (a)] == 4)) {
				bscore++;
			}
			else if (brule[i % (b)] == 3 && (arule[i % (a)] == 4)) {
				bscore++;
			}
			else if (arule[i % (a)] == 3 && (brule[i % (b)] == 4)) {
				ascore++;
			}
	}
	cout << ascore << " " <<  bscore << endl;
	return 0;
}

优化后
#include<iostream>
using namespace std;
int arule[300];
int brule[300];
int ascore = 0;
int bscore = 0;
int vs[5][5] = { {0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0} };
得分表的处理  通过打表简化代码
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> arule[i];
	}
	for (int j = 0; j < b; j++) {
		cin >> brule[j];
	}
	
	for (int i = 0; i < n; i++){
		ascore += vs[arule[i % a]][brule[i % b]];
		bscore += vs[brule[i % b]][arule[i % a]];
	}
	cout << ascore << " " <<  bscore << endl;
	return 0;
}
