// redlining.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#define minBanlance 100;
using namespace std;
class User {

public:
	std::string _id;
	std::string _name;
	std::string _addrss;
	size_t     _balance = 0;
	size_t     _minBalance = minBanlance;
	std::string _passworld;
public:
	User()
	{
		std::cout << "正在创建账户" << std::endl;
		std::cout << "请输入账号:  姓名:  地址:  " <<std::endl;
		std::cin >> _id;
		std::cin >> _name;
		std::cin >> _addrss;
		std::cout << "请输入创账户的密码" << std::endl;
		std::cin >>_passworld;
		std::cout << "用户创建完成" << std::endl;
	}

	string Get_id()
	{
		return _id;
	}

	string Get_Passworld()
	{
		return _passworld;
	}
};

void menu()
{
	std::cout << "请输入要选则服务" << std::endl;
	std::cout <<"1.创建新的用户" <<std::endl;
	     cout << "2.登录" << endl;
}

void menu_Bank()
{
	cout << endl;
	cout << endl;
	cout << "请选择所需要的业务" << endl;
	cout << "1 存款" << endl;
	cout << "2 取款" << endl;
	cout << "3 查询"<<  endl;
	cout << "4 退出" << endl;
}

class Bank {
	std::vector<User>  _user;
public:
	void Create_User()
	{
		User temp;
		for (int i = 0; i < _user.size(); i++)
		{
			if (temp.Get_id() == _user[i].Get_id())
			{
				cout << "id 重复请重新输入id" << endl;
				Create_User();
			}
		}
		_user.push_back(temp);
	}
	// 登录
	bool Register(int& a)
	{

		string passdworld ,id;
			cout << "请输入账号:" << endl;
			cin >> id;
			cout << "请输入密码:" << endl;
			cin >> passdworld;
			int i = 0;
			for (; i < _user.size(); i++)
			{
				if (_user[i].Get_id() == id && _user[i].Get_Passworld() == passdworld)
				{
					a = i;
					cout << endl;
					cout << endl;
					return true;
				}
		}
			cout << "登录失败, 账号或者密码错误" << endl;
			cout << endl;
			cout << endl;
		return false;
	}

	// 取款
	void withdrawal(int& a)
	{
		cout << "请输入取款金额, 您目前的总金额为：" <<_user[a]._balance<< endl;
		int balance;
		cin >> balance;
		if (balance <= (_user[a]._balance - _user[a]._minBalance))
		{
			_user[a]._balance = _user[a]._balance - balance;
			cout << "取款成功" << endl;
			cout << "您剩余余额为: " << _user[a]._balance << endl;
		}
		else
		{
			cout << "余额不足, 最少保留: " << _user[a]._minBalance<<" 您目前余额为:" <<_user[a]._balance;
		}
		return ;
	}

	// 存款
	void SaveMoney(int& a)
	{		
		cout << "请输入存款金额:" << endl;
		int money;
		cin >> money;
		if (money < 0)
		{
			cout << "输入错误" << endl;
			return;
		}
		size_t befor = _user[a]._balance;
		_user[a]._balance = _user[a]._balance + money;
		cout << "存款成功, 您以前的余额为: " << befor << "  现在的余额为: "<< _user[a]._balance;

	}

	void query(int& a)
	{
		cout << " _id :" << _user[a]._id << endl;
		cout << "_name :" << _user[a]._name << endl;
		cout << "_addrss :" << _user[a]._addrss << endl;
		cout << "_balance :" << _user[a]._balance << endl;
		cout << "_minBalance :" << _user[a]._minBalance << endl; 
	}
	void operation()
	{
		int a , put;
		if (!Register(a))
		{
			return ;
		}
		cout << "登陆成功" << endl;
		while (1)
		{
			menu_Bank();
			cin >> put;
			if (put == 1)
			{
				SaveMoney(a);
				continue;
			}
			if(put == 2)
			{
				withdrawal(a);
				continue;
			}
			if (put == 3)
			{
				query(a);
				continue;
			}
			if (put == 4)
			{
				return;
			}
			cout << "输入错误" << endl;
		}
	}
};

int main()
{
	Bank bank;
	while (1)
	{
		int a;
		menu();
		cin >> a;
		cout << a << endl;;
		if (a == 1)
		{
			bank.Create_User();
		}
		else if(a == 2)
		{
			bank.operation();
		}
		else
		{
			cout << "输入错误, 请重新输入" << endl;
			cout << endl;
			cout << endl;
		}
	}
	system("pause");
	return 0;
}
