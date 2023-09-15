#pragma once
#include <iostream>
using namespace std;

class person
{
	int id;
	string name, email;

public:
	person(int id, string name, string email);
	void setName(string name);
	void setEmail(string email);
	string getName();
	string getEmail();
	int getid();
};

