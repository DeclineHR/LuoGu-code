#include <iostream>
using namespace std;

int main()
{
    int c;
    cin >> c;
    long long g = c * c;
    for (int a = 1; a < c; a++)
    {
        //题目：如果有多个可能的答案，请确保 a 尽可能的小
        //则a循环必须在b循环前面，虽然题目要求a <= b
        //但是一旦有结果就输出然后结束 a一定最小
        for (int b = 1; b < c; b++)
        {
            if (a * a + b * b == g)
            {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}
