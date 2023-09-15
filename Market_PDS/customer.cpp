#include "customer.h"

customer::customer(int id, string name, string email, string address, string phoneNumber) : person(id, name, email) {
	this->address = address;
	this->phoneNumber = phoneNumber;
}
map<string, customer> customer::allcustomers;
map<string, customer> ::iterator customer::itCustomer;

void customer::setAddress(string address) {
	this->address = address;
}

void customer::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

string customer::getPhoneNumber() {
	return phoneNumber;
}

string customer::getAddress() {
	return address;
}

Cart* customer::getCart() {
	return &c;
}
