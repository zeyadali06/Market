#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class product
{
	string name, catg;
	int id, quan_product, selId, quan_user, ratcount = 0;
	double  price;
	float rate = 0;

public:
	product(int id, string name, double price, string catg, int quan, int selId);
	static vector<product> allProducts;
	void setrate(float rate);
	void IncrementCountRate();
	void setCountRate(int ratcount);
	void setId(int id);
	void setName(string name);
	void setPrice(double price);
	void setCategory(string catg);
	void setQuantity(int quan);
	void setUserQuantity(int quan_user);
	int getId();
	string getName();
	double getPrice();
	string getCategory();
	int getQuantity();
	float getRate();
	int getQuantityOfuser();
	int getSellerId();
	int getratnum();
};

