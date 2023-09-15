#pragma once
#include <iostream>
#include <windows.h>
#include "seller.h"
#include "customer.h"
using namespace std;

class registration
{
	static int sellerLastId;
	static int customerLastId;

public:
	static void RegistrationMenu();
	static bool RegistratioOption();
	static void SellerRegistration();
	static void CustomerRegistration();
	static void setSellerLastid(int id);
	static int getSellerLastid();
	static void setCustomerLastid(int id);
	static int getCustomerLastid();
};
