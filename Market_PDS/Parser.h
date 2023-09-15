#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "seller.h"
#include "customer.h"
#include "product.h"
using namespace std;

class parser
{

public:
	static vector<string> split(string line);
	static seller parserToSeller(string line);
	static customer parserToCustomer(string line);
	static product parserToProduct(string line);
};

