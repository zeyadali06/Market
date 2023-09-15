#include "person.h"

person::person(int id, string name, string email) {
	this->id = id;
	this->name = name;
	this->email = email;
}

void person::setName(string name)
{
	this->name = name;
}

void person::setEmail(string email)
{
	this->email = email;
}

string person::getName() {
	return name;
}

string person::getEmail() {
	return email;
}

int person::getid() {
	return id;
}