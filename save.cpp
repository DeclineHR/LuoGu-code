 #include<bits/stdc++.h>
using namespace std;
template<class T1,class T2>
class person {
public:
	//构造函数类内实现
	person(T1 name, T2 age);
	/*{
		this->myname = name;
		this->myage = age;
	}*/
	//成员函数类内实现
	void show();
	/*{
		cout "姓名: " << this->myname
			<< "年龄: " << this->myage << endl;
	}*/
	T1 myname;
	T2 myage;
};
//构造函数类外实现
template<class T1,class T2>
person<T1, T2>::person(T1 name, T2 age) {
	this->myname = name;
	this->myage = age;
}
//成员函数类外实现
template<class T1, class T2>
void person<T1,T2>::show()
{	
	cout << "姓名: " << this->myname <<  " 年龄: " << this->myage << endl;
}
void test1() {
	person<string, int>p("Tom", 20);
	p.show();
}
int main() {
	test1();
	system("pause");
	return 0;

}

