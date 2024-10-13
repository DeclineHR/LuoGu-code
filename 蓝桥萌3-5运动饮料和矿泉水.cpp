#include <iostream>
using namespace std;
int main()
{
  //案例分析：1.只要是偶数 先手就只能拿到一半瓶
  //         2.只要是奇数 先手就只能拿到1瓶
    int N;
    cin >> N;
     if (N % 2 == 0) {//偶数
        cout << N / 2;
        return 0;
    }
    else {//奇数
        cout <<1;
    }
    return 0;
}
