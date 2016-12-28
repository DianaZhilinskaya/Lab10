#pragma once
#include "stdafx.h"
#include <map> 
#include<forward_list>
#include <iostream>
#include <memory>
#include <string>
using namespace std;
class BankAccount
{
private:
	string fullName;
	long acctNum;
	double balance;
public:
	string FullName() { return fullName; }
	long AcctNum() const { return acctNum; }
	BankAccount(string name = "Nullbody", long an = -1, double bal = 0.0)
	{
		fullName = name;
		acctNum = an;
		balance = bal;
	};
	double Balance() const { return balance; };
	friend ostream& operator<<(ostream& os, const BankAccount& ba);
};

ostream& operator<<(ostream& os, BankAccount& ba)
{
	os << ba.FullName() << '/' << ba.AcctNum() << '/' << ba.Balance();
	return os;
}
