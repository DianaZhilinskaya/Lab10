// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <map> 
#include<forward_list>
#include <iostream>
#include <memory>
#include <string>
#include"BankAccount.h"
using namespace std;

// Custom Class
//class BankAccount
//{
//private:
//	string fullName;
//	long acctNum;
//	double balance;
//public:
//	string FullName() { return fullName; }
//	long AcctNum() const { return acctNum; }
//	BankAccount(string name = "Nullbody", long an = -1, double bal = 0.0)
//	{
//		fullName = name;
//		acctNum = an;
//		balance = bal;
//	};
//	double Balance() const { return balance; };
//	friend ostream& operator<<(ostream& os, const BankAccount& ba);
//};
//
//ostream& operator<<(ostream& os, BankAccount& ba)
//{
//	os << ba.FullName() << '/' << ba.AcctNum() << '/' << ba.Balance();
//	return os;
//}


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "1 part:" << endl;

	map<long, unique_ptr<BankAccount>> *container1 = new map<long, unique_ptr<BankAccount>>();

	container1->insert(make_pair(0, unique_ptr<BankAccount>(new BankAccount("Account 1", 33345, 100.0))));
	container1->insert(make_pair(1, unique_ptr<BankAccount>(new BankAccount("Account 2", 15545, 200.0))));
	container1->insert(make_pair(2, unique_ptr<BankAccount>(new BankAccount("Account 3", 18845, 300.0))));
	container1->insert(make_pair(3, unique_ptr<BankAccount>(new BankAccount("Account 4", 19945, 400.0))));
	container1->insert(make_pair(4, unique_ptr<BankAccount>(new BankAccount("Account 5", 77345, 500.0))));

	auto kony = container1->begin();
	std::cout << "Container 1 contains:\n";
	for (auto it = container1->begin(); it != container1->end(); ++it)
	{
		cout << it->first << " : " << *it->second << endl;
	}
	
	cout << "Delete with key 1" << endl;
	kony = container1->find(1);
	container1->erase(kony);

	cout << "Delete from key 3" << endl;
	kony = container1->find(3);
	container1->erase(kony, container1->end());

	for (auto it = container1->begin(); it != container1->end(); ++it)
	{
		cout << it->first << " - " << *it->second << endl;
	}

	cout << "2 part:" << endl;

	forward_list<pair<long, shared_ptr<BankAccount>>> container2;

	container2.push_front(pair<long, shared_ptr<BankAccount>>(5, shared_ptr<BankAccount>(new BankAccount("Account 5", 31145, 700.0))));
	container2.push_front(pair<long, shared_ptr<BankAccount>>(6, shared_ptr<BankAccount>(new BankAccount("Account 6", 33445, 800.0))));
	container2.push_front(pair<long, shared_ptr<BankAccount>>(7, shared_ptr<BankAccount>(new BankAccount("Account 7", 77345, 900.0))));
	container2.push_front(pair<long, shared_ptr<BankAccount>>(8, shared_ptr<BankAccount>(new BankAccount("Account 8", 88785, 1000.0))));
	
	for (map<long, unique_ptr<BankAccount>>::iterator it = container1->begin(); it != container1->end(); ++it)
	{
		container2.push_front(pair<long, shared_ptr<BankAccount>>(it->first, make_shared<BankAccount>(*move(it->second))));
	}
	
	cout << "Container 1 contains:\n";
	for (map<long, unique_ptr<BankAccount>>::iterator it = container1->begin(); it != container1->end(); ++it)
	{
		cout << it->first << " - " << *it->second << '\n';
	}
	
	cout << "Container 2 contains:\n";
	for (forward_list<pair<long, shared_ptr<BankAccount>>>::iterator it = container2.begin(); it != container2.end(); ++it)
	{
		cout << it->first << " - " << *it->second << '\n';
	}
	

	string delay;
	cin >> delay;

	return 0;
}

