// ConsoleApplication3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <algorithm>
#include<forward_list>
#include <map> 
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
//	long AcctNum() { return acctNum; }
//	BankAccount(string name = "Nullbody", long an = -1, double bal = 0.0)
//	{
//		fullName = name;
//		acctNum = an;
//		balance = bal;
//	};
//	double Balance() { return balance; };
//	friend ostream& operator<<(ostream& os, const BankAccount& ba);
//};
//
//ostream& operator<<(ostream& os, BankAccount& ba)
//{
//	os << ba.FullName() << '/' << ba.AcctNum() << '/' << ba.Balance();
//	return os;
//}
//
//struct Functor
//{
//	bool operator()(BankAccount a, BankAccount b)
//	{
//		return a.Balance() > b.Balance();
//	}
//};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "1 part:" << endl;

	list<BankAccount> *container3 = new list<BankAccount>();
	container3->push_front(BankAccount("Account 1", 33345, 100.0));
	container3->push_front(BankAccount("Account 2", 33111, 400.0));
	container3->push_front(BankAccount("Account 3", 55545, 300.0));
	container3->push_front(BankAccount("Account 4", 37775, 500.0));
	container3->push_front(BankAccount("Account 5", 99945, 200.0));
	
	Functor f;
	container3->sort(f);
	
	std::cout << "Container 3 contains:" << endl;
	for (auto it = container3->begin(); it != container3->end(); ++it)
	{
		cout << *it << endl;
	}
	
	cout << "2 part: Container 3 with Balance = 300:" << endl;

	double finddBalance = 300.0;
	list<BankAccount>::reverse_iterator ListItem;
	for (ListItem = container3->rbegin(); ListItem != container3->rend(); ++ListItem)
	{
		BankAccount account = *ListItem;
		if (account.Balance() == finddBalance)
		{
			cout << account << endl;
		}
	}

	cout << "3 part:" << endl;

	forward_list<pair<long, shared_ptr<BankAccount>>> container2;
	long i = 0;
	for (ListItem = container3->rbegin(); ListItem != container3->rend(); ++ListItem)
	{
		BankAccount account = *ListItem;
		if (account.Balance() >= finddBalance)
		{
			container2.push_front(pair<long, shared_ptr<BankAccount>>(i, make_shared<BankAccount>(account)));
		}
		i++;
	}

	container2.reverse();
	cout << "Container 2 contains:\n";
	for (auto it = container2.cbegin(); it != container2.cend(); ++it)
	{
		cout << it->first << " - " << *it->second << '\n';
	}

	cout << "4 part:" << endl;

	map<long, unique_ptr<BankAccount>> *container1 = new map<long, unique_ptr<BankAccount>>();
	container1->insert(make_pair(0, unique_ptr<BankAccount>(new BankAccount("Account 1", 33345, 100.0))));
	container1->insert(make_pair(3, unique_ptr<BankAccount>(new BankAccount("Account 2", 15545, 200.0))));
	container1->insert(make_pair(5, unique_ptr<BankAccount>(new BankAccount("Account 3", 18845, 300.0))));
	container1->insert(make_pair(1, unique_ptr<BankAccount>(new BankAccount("Account 4", 19945, 400.0))));
	container1->insert(make_pair(2, unique_ptr<BankAccount>(new BankAccount("Account 5", 77345, 500.0))));

	cout << "Sorted Container 1 contains:\n";
	for (map<long, unique_ptr<BankAccount>>::iterator it = container1->begin(); it != container1->end(); ++it)
	{
		cout << it->first << " - " << *it->second << '\n';
	}

	cout << "3th element of Container 1:\n";
	long k = 3;
	cout << *(container1->find(k))->second << endl;

	struct Forward_listFunctor
	{
		bool operator()(pair<long, shared_ptr<BankAccount>> a, pair<long, shared_ptr<BankAccount>> b)
		{
			return a.second->Balance() < b.second->Balance();
		}
	};

	Forward_listFunctor ft;
	container2.sort(ft);

	cout << "Sorted Container 2 contains:\n";
	for (auto it = container2.cbegin(); it != container2.cend(); ++it)
	{
		cout << it->first << " - " << *it->second << '\n';
	}

	cout << "3th element of Container 2:\n";
	i = 1;
	for (auto it = container2.begin(); it != container2.end(); ++it)
	{
		if (i == k )
		{
			cout << it->first << " - " << *it->second << '\n';
		}
		i++;
	}

	cout << "5 part:" << endl;
	container3->clear();

	for (map<long, unique_ptr<BankAccount>>::iterator it = container1->begin(); it != container1->end(); ++it)
	{
		container3->push_front(*it->second);
	}

	for (auto it = container2.begin(); it != container2.end(); ++it)
	{
		container3->push_front(*it->second);
	}


	cout << "Container 3 contains:" << endl;
	for (auto it = container3->begin(); it != container3->end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "6 part: Container 3 with Balance = 300:" << endl;
	list<BankAccount>:: iterator item;

	for (item = container3->begin(); item != container3->end(); ++item)
	{
		BankAccount account = *item;
		if (account.Balance() == finddBalance)
		{
			cout << account << endl;
		}
	}

	cout << "7 part: Input the string value:" << endl;
	
	string str("Initial string");
	
	// copy constructor
	string strcopy(str);
	
	// move constructor
	string strmove(move(str));

	std::cout << "Length after move:" << str.length() << ",  " << strcopy << ", " << strmove << endl;

	getline(cin, str);
	cout << "Length:" << str.length() << " First 3 chars: " << str.substr(0, str.length() > 3 ? 3 : str.length()) << endl;
	
	string s = "FullName|AcctNum|Balance";
	string delimiter = "|";
	cout << "Use string \"" << s << "\" to split" << endl;

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) 
	{
		token = s.substr(0, pos);
		cout << token << endl;
		s.erase(0, pos + delimiter.length());
	}
	cout << s << endl;


	cout << "8 part:" << endl;

	struct DividedByTwo
	{
	public:
		bool operator()(const int x) const
		{
			return x % 2 == 0;
		}
	};

	const size_t N = 4;
	int A[N] = { 3, 2, 5, 8 };

	cout << "Count of DividedByTwo:" << endl;
	cout << count_if(A, A + N, DividedByTwo()) << endl;

	size_t K = count_if(A, A + N, DividedByTwo());

	int B[2] ;
	cout << "DividedByTwo elements:" << endl;
	copy_if(begin(A), end(A), B, DividedByTwo());
	for (int element : B)
	{
		cout << element << endl;
	}

	struct Greater
	{
	public:
		bool operator()(const int lhs, const int rhs) const
		{
			return lhs > rhs;
		}
	};
	
	cout << "Sorted array elements:" << endl;
	sort(A, A + N, Greater());
	for(int element : A)
	{
		cout << element << endl;
	}

	cout << "Sorted list elements:" << endl;
	list<int> *mylist = new list<int>();
	mylist->push_front(1);
	mylist->push_front(2);
	mylist->sort(Greater());
	for (int element : *mylist)
	{
		cout << element << endl;
	}

	cout << "Incremented elements:" << endl;
	// лямбда-функция: значение каждого элемента увеличивает значение на единицу и выводит на экран
	for_each(A, A + N, [](int x) {std::cout << ++x << " " << endl; });

	string delay;
	cin >> delay;

	return 0;
}

