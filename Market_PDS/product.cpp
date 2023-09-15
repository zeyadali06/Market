#include "product.h"

product::product(int id, string name, double price, string catg, int quan, int selId) {
	this->id = id;
	this->name = name;
	this->price = price;
	this->catg = catg;
	this->quan_product = quan;
	this->selId = selId;
	quan_user = 0;
} vector<product> product::allProducts;

void product::setrate(float rate) {
	this->rate = rate;
}

void product::IncrementCountRate() {
	ratcount++;
}

void product::setCountRate(int ratcount) {
	this->ratcount = ratcount;
}

void product::setId(int id) {
	this->id = id;
}

void product::setName(string name) {
	this->name = name;
}

void product::setPrice(double price) {
	this->price = price;
}

void product::setCategory(string catg) {
	this->catg = catg;
}

void product::setQuantity(int quan) {
	this->quan_product = quan;
}

void product::setUserQuantity(int quan_user) {
	this->quan_user = quan_user;
}

int product::getId() {
	return id;
}

string product::getName() {
	return name;
}

double product::getPrice() {
	return price;
}

string product::getCategory() {
	return catg;
}

int product::getQuantity() {
	return quan_product;
}

float product::getRate() {
	cout << setprecision(2);
	return rate;
}

int product::getQuantityOfuser() {
	return quan_user;
}

int product::getSellerId() {
	return selId;
}

int product::getratnum() {
	return ratcount;
}