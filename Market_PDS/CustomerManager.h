#pragma once
#include "customer.h"
#include  "Sorting.h"
#include "productManager.h"
#include "CartManager.h"

class CustomerManager
{
public:

	static void customerMenu();

	static bool customerOption(customer* c);


	static void customerBrowseProduct(customer* c);

	static void ModifyCustomerInfo(customer* s);



};

