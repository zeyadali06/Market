#include "Validation.h"
 bool Validation::checkName(string n)
{

	if ((n.size() >= 5 && n.size() <= 20)) return true;

	return true;
}

 bool Validation::checkPassword(string p)
{

	if ((p.size() >= 8 && p.size() <= 20))
	{
		return true;
	}

	return false;
}

 bool Validation::checkEmail(string e)
{
	/*if((e.size() >= 8 && e.size() <= 20))
	{
		return true;
	}

	return false; */
	return true;
}

 bool Validation::checkPrice(int price) {
	if (price <= 0)
	{
		return false;
	}
	return true;
}