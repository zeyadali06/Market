#pragma once
#include <iostream>
#include "product.h"
using namespace std;
class Validation
{
public:
	static bool checkName(string n);

	static bool checkPassword(string p);
	
	static bool checkEmail(string e);
	static bool checkPrice(int price);

};

