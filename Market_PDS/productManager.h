#pragma once
#include "product.h"

class productManager
{

public:
	static product* search(int id);
	static void productrate(product* p);
	static bool ProductSellerExist(int id);
};

