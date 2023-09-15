#pragma once
#include <iomanip>
#include <Windows.h>
#include "seller.h"
#include "productManager.h"

class sellerManager
{

public:
	static void sellerMenu();
	static void addProduct(seller s);
	static void modifyProduct(seller s);
	static bool sellerOption(seller* s);
	static void sellerrate(seller* s);
	static void sellerProducts(seller s);
	static void sellerModifyMenu();
	static void sellerModifyOption(seller s, product* p);
	static void RemoveProduct(seller s);
	static void ModifySeller(seller* s);
	static seller* search(int id);
	static bool ifExist(int id);
	static string chooseCategory();
	template <typename T0, typename T1, typename T2, typename T3, typename T4>
	static void print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4);
};

