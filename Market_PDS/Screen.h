#pragma once
#include "sellerManager.h"
#include "CustomerManager.h"
#include "fileManager.h"
#include "registration.h"

class Screen
{

public:
	static void loginAsMenu();
	static int loginAsOption();
	static void loginOption(int choice);
	static void loginSeller();
	static void loginCustomer();
	static void loginRegister();
	static void Welcome();
	static void runApp();
};

