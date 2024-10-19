#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;

struct person {
	int page;//年龄
	string pname;//姓名
	int psex;//性别
	string pphone;//电话
	string paddr;//地址
};
//通讯录
struct Addressbooks {
	struct person personArray[MAX];//通讯录上线1000个人
	int msize;//通讯录中人员个数
};
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//1.封装添加联系人函数
//思路：添加联系人前先判断通讯录是否已满，如果满了就不再添加，未满情况将新联系人信息逐个加入到通讯录
void addperson(Addressbooks* abs) {
	//判断电话本是否满了
	if (abs->msize == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->msize].pname = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->msize].psex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->msize].page = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[abs->msize].pphone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->msize].paddr= address;

		//更新通讯录人数
		abs->msize++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
//2.封装显示联系人函数
//思路：判断如果当前通讯录中没有人员，就提示记录为空，人数大于0，显示通讯录中信息
void showperson(Addressbooks* abs) {
	if (abs->msize == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->msize; i++)
		{
			cout << "姓名：" << abs->personArray[i].pname << "\t";
			cout << "性别：" << (abs->personArray[i].psex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].page << "\t";
			cout << "电话：" << abs->personArray[i].pphone << "\t";
			cout << "住址：" << abs->personArray[i].paddr << endl;
		}
	}

	system("pause");
	system("cls");

}
//3.1删除联系人前，我们需要先判断用户输入的联系人是否存在，如果存在删除，不存在提示用户没有要删除的联系人
//因此我们可以把检测联系人是否存在封装成一个函数中，如果存在，返回联系人在通讯录中的位置，不存在返回 - 1
//检测联系人是否存在代码：
int checkperson(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->msize; i++)
	{
		if (abs->personArray[i].pname == name)
		{
			return i;
		}
	}
	return -1;
}
//3.2删除联系人函数
void deleteperson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->msize; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];//数据前移
		}
		abs->msize--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}
//4.查找联系人函数
void findperson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].pname << "\t";
		cout << "性别：" << abs->personArray[ret].psex << "\t";
		cout << "年龄：" << abs->personArray[ret].page << "\t";
		cout << "电话：" << abs->personArray[ret].pphone << "\t";
		cout << "住址：" << abs->personArray[ret].paddr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}
//5.封装修改联系人函数
//实现思路：查找用户输入的联系人，如果查找成功进行修改操作，查找失败提示查无此人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = checkperson(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].pname = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].psex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].page = age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].pphone = phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].paddr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}
//6.封装清空联系人函数
//实现思路： 将通讯录所有联系人信息清除掉，只要将通讯录记录的联系人数量置为0，做逻辑清空即可。
void clearperson(Addressbooks* abs) {
	abs->msize = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main() {
	
	Addressbooks abs;
	abs.msize = 0;
	int num;
	while (1) {//重复循环直到退出通讯录
		showMenu();
		
		cin >> num;
		switch (num)
		{
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			clearperson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
