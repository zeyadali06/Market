#pragma once
#include <fstream>
#include "Parser.h"
#include "registration.h"

class fileManager
{

public:
	static void saveCustomers();
	static void getCustomers();

	static void saveSellers();
	static void getSellers();

	static void saveProducts();
	static void getProducts();

	static void get_SellerLastid();
	static void save_SellerLastid();

	static void get_CustomerLastid();
	static void save_CustomerLastid();

	static void clearAllCustomers();
	static void clearAllProducts();
	static void clearAllSellers();
	static void clearAllFiles();
};

