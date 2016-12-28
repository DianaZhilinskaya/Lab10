#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <algorithm>
#include<forward_list>
#include <map> 

using namespace std;

// Custom Class
class BankAccount
{
private:
	string fullName;
	long acctNum;
	double balance;
public:
	string FullName() { return fullName; }
	long AcctNum() { return acctNum; }
	BankAccount(string name = "Nullbody", long an = -1, double bal = 0.0)
	{
		fullName = name;
		acctNum = an;
		balance = bal;
	};
	double Balance() { return balance; };
	friend ostream& operator<<(ostream& os, const BankAccount& ba);
};

ostream& operator<<(ostream& os, BankAccount& ba)
{
	os << ba.FullName() << '/' << ba.AcctNum() << '/' << ba.Balance();
	return os;
}

struct Functor
{
	bool operator()(BankAccount a, BankAccount b)
	{
		return a.Balance() > b.Balance();
	}
};