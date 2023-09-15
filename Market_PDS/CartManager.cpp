#include "CartManager.h"

void CartManager::cartMenu() {
	cout << "\t\t\t\t\t\tCart Functions\n";
	cout << "1- checkout" << endl
		<< "2- edit quantity product" << endl
		<< "3- remove Porduct" << endl
		<< "4- exit" << endl;
}

bool CartManager::cartProduct(customer* c) {
	system("cls");
	if (!c->getCart()->isEmpty()) {
		cout << "number of products: " << c->getCart()->getListProducts().size() << endl;
		cout << "Your product is : " << endl;
		c->getCart()->printCartInfo();
		cout << endl << "Total cost is: ";
		printf("%.3f\n", c->getCart()->getTotalPrice());
		return true;
	}
	return false;
}

void CartManager::cartOption(customer* c) {
	cout << "enter your choice\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		ratingMenu();
		rating(c);
		checkOut(c);
		break;
	}
	case 2: {
		editQuantity(c);
		break;
	}
	case 3: {
		removeProduct(c);
		break;
	}
	case 4: {
		break;
	}
	default:
		cout << "invaled choice" << endl;
		cartOption(c);
		break;
	}
}

void CartManager::ratingMenu() {
	cout << "what do you want to do?\n";
	cout << "1- rate product\n"
		<< "2- rate seller\n"
		<< "3- exit\n";
}

void CartManager::rating(customer* c) {
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		rateProduct(c);
		break;
	}
	case 2:
	{
		rateSeller(c);
		break;
	}
	case 3:
	{
		return;
	}
	default: {
		cout << "invaled choice \n";
		rating(c);
		break;
	}
	}
	ratingMenu();
	rating(c);
}

void CartManager::checkOut(customer* c) {
	for (int i = 0; i < c->getCart()->getListProducts().size(); i++)
	{
		for (int j = 0; j < product::allProducts.size(); j++)
		{
			if (product::allProducts[j].getId() == c->getCart()->getListProducts()[i].getId())
			{
				product::allProducts[j].setQuantity(product::allProducts[j].getQuantity() - c->getCart()->getListProducts()[i].getQuantityOfuser());
				product::allProducts[j].setUserQuantity(0);
				product::allProducts[j].setCountRate(c->getCart()->getListProducts()[i].getratnum());
				product::allProducts[j].setrate(c->getCart()->getListProducts()[i].getRate());
			}
		}
	}
	c->getCart()->clearAllProducts();
	cout << "operation complete" << endl;
}

void CartManager::rateProduct(customer* c) {
	cout << "enter id :" << endl;
	int id;
	cin >> id;
	product* p = c->getCart()->searchProduct(id);
	if (p != NULL)
	{
		productManager::productrate(p);
	}
	else {
		cout << "product doesnot exist" << endl;
	}
}

void CartManager::rateSeller(customer* c) {
	cout << "enter id :" << endl;
	int id;
	cin >> id;
	seller* s = c->getCart()->searchSeller(id);
	if (s != NULL)
	{
		sellerManager::sellerrate(s);
	}
	else
	{
		cout << "seller doesnot exist in your cart" << endl;
	}
}

void CartManager::editQuantity(customer* c) {
	cout << "enter id\n";
	int id;
	cin >> id;
	product* p = c->getCart()->searchProduct(id);

	if (p != NULL)
	{
		while (true)
		{
			cout << "enter the qunatity you want \n";
			int q; cin >> q;

			if (q > p->getQuantity() || q <= 0)
			{
				cout << "invaled number of Quantity \n";
				cout << "do you want " << endl
					<< "1- back to menu" << endl
					<< "2- enter new quantity" << endl;
				int ch; cin >> ch;
				switch (ch)
				{
				case 1: {

					return;
				}
				case 2: {
					continue;
				}
				default: {

					cout << "invaled choice" << endl;
					break;
				}
				}
			}
			p->setUserQuantity(q);
			break;
		}
	}
	else
	{
		cout << "invaled Id\n";
		editQuantity(c);
	}
}

void CartManager::removeProduct(customer* c) {
	cout << "enter id \n" << endl;
	bool found = false;
	int id;
	cin >> id;
	for (int i = 0; i < c->getCart()->getListProducts().size(); i++)
	{
		if (c->getCart()->getListProducts()[i].getId() == id)
		{
			c->getCart()->removeProduct(i);
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "invaled id" << endl;
		removeProduct(c);
	}
}
