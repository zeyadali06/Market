#pragma once
#include <iostream>
#include "person.h"
#include "Cart.h"
#include<map>
using namespace std;
class customer : public person
{
	string address;
	string phoneNumber;
	Cart c;

public:
	customer(int id, string name, string email, string address, string phoneNumber);
	static  map<string, customer> allcustomers;
	static  map<string, customer> ::iterator itCustomer;
	

	void setAddress(string address);
	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();
	string getAddress();
	Cart* getCart();
	
};
