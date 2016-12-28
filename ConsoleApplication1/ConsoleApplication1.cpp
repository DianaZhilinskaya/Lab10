// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map> 
#include <forward_list>
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "1 part:" << endl;
	map<long, long> container1 =
	{
		{ 0, 23 },
		{ 1, 47 },
		{ 2, 50 },
		{ 3, 98 },
		{ 4, 54 }

	};

	auto kony = container1.begin();
	std::cout << "Container 1 contains:\n";
	for (auto it = container1.begin(); it != container1.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	cout << "Delete with key 1" << endl;
	kony = container1.find(1);
	container1.erase(kony);

	cout << "Delete from key 3" << endl;
	kony = container1.find(3);
	container1.erase(kony, container1.end());

	for (auto it = container1.begin(); it != container1.end(); ++it)
	{
		cout << it->first << " - " << it->second << endl;
	}

	cout << "2 part:" << endl;

	forward_list<pair<long, long>> container2;

	container2.push_front(pair<long, long>(5, 20));
	container2.push_front(pair<long, long>(6, 4));
	container2.push_front(pair<long, long>(7, 144));
	container2.push_front(pair<long, long>(8, 34));

	container1.insert(container2.begin(), container2.end());

	std::cout << "Container 1 contains:\n";
	for (std::map<long, long>::iterator it = container1.begin(); it != container1.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << '\n';
	}

	std::cout << "Container 2 contains:\n";
	for (std::forward_list<pair<long, long>>::iterator it = container2.begin(); it != container2.end(); ++it)
	{
		std::cout << it->first << " - " << it->second << '\n';
	}

	string delay;
	cin >> delay;

	return 0;
}

