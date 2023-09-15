#pragma once
#include "product.h";
#include "sellerManager.h";
#include "Cart.h"
#include "iostream"
#include <iomanip>
using namespace std;

class Cart
{
	vector<product> products;

	double totalPrice;

public :
	Cart();

	Cart(vector<product> p);

	vector<product> getListProducts();

	void clearAllProducts();

	void fillCart(product p);

	double getTotalPrice();

	bool isEmpty();

	void printCartInfo();

	void removeProduct(int postion);

	product* searchProduct(int id);

	seller* searchSeller(int id);

	template <typename T0, typename T1, typename T2, typename T3, typename T4 ,typename T5 , typename T6, typename T7>
	static void print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4 ,T5 t5,T6 t6,T7 t7);
};

