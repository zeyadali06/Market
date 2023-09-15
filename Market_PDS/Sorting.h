#pragma once
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "product.h"

class Sorting
{

public:
	static bool s(product p1, product p2);
	static bool r(product p1, product p2);
	static vector<product> rate_sorting(vector<product> p);
	static bool SortingWay(vector<product> allprod);
	static vector<product> toSort(vector<product>products, string way, string catg = "");
	static void print_data(vector<product> p);
	static void setGetProduct(vector<product> p); // choose product then show it
	static set<string> getAllCategories(vector<product> p);
	static string setGetCategory(vector<product> p); // print the categories and choose one of them then return it
	static vector<product> names_sorting(vector<product> prod);
	template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static void print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6);
};


