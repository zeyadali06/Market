#include "CustomerManager.h"

void CustomerManager::customerMenu() {
	Sleep(1250);
	system("cls");
	cout << "\t\t\t\t\t\tCustomer Functions\n";
	cout << "1- browse Product" << endl
		<< "2- show Cart list" << endl
		<< "3- modify your info" << endl
		<< "4- back" << endl;
}

bool CustomerManager::customerOption(customer* c) {
	cout << "Enter you choice\n";
	int choice;
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1: {
		customerBrowseProduct(c);
		break;
	}
	case 2: {
		if (CartManager::cartProduct(c))
		{
			CartManager::cartMenu();
			CartManager::cartOption(c);
		}
		else
		{
			cout << "Its empty\n" << endl;
		}
		break;
	}
	case 3: {
		ModifyCustomerInfo(c);
		break;
	}
	case 4: {
		return true;
	}
	default:
	{
		cout << "Invaled choice" << endl;
		break;
	}
	}
	customerMenu();
	customerOption(c);
}

void CustomerManager::customerBrowseProduct(customer* c) {

	if (Sorting::SortingWay(product::allProducts) == false)
	{
		return;
	}
	else {
		cout << "Enter the id of product you want purchase" << endl;
		int id;
		cin >> id;
		product* p = productManager::search(id);
		product* pCart = c->getCart()->searchProduct(id);

		if (pCart == NULL)
		{
			if (p != NULL)
			{
				while (true)
				{
					cout << "enter the qunatity you want \n";
					int q;
					cin >> q;
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
				c->getCart()->fillCart(*p);
				cout << "product Add to your cart successfuly" << endl;
			}
			else {
				cout << "invaled Id\n";
				customerBrowseProduct(c);
				return;
			}
		}
		else
		{
			cout << "The poduct exist in your Cart " << endl;
		}
		cout << "do you want purchase another product(y/n)?";
		while (true)
		{
			char ch; cin >> ch;
			if (ch == 'y')
			{
				customerBrowseProduct(c);
				break;
			}
			else if (ch == 'n') {
				break;
			}
			else
				cout << "invaled choice\n";
		}
	}
}

void CustomerManager::ModifyCustomerInfo(customer* s) {
	cout << "what do you want to modify?" << endl
		<< "1- Name" << endl
		<< "2- Email" << endl <<
		"3-Address" << endl << "4-PhoneNumber" << endl << "5-back" << endl;
	int c;
	cin >> c;

	switch (c)
	{
	case 1: {
		cout << "enter new name\n ";
		string name;
		cin >> name;
		s->setName(name);
		break;
	}
	case 2: {
		cout << "enter new email\n ";
		string email;
		cin >> email;
		s->setEmail(email);
		break;
	}
	case 3: {
		cout << "enter new address\n ";
		string add;
		cin >> add;
		s->setAddress(add);
		break;
	}
	case 4: {
		cout << "enter new phoneNumber\n ";
		string num;
		cin >> num;
		s->setPhoneNumber(num);
		break;
	}
	case 5: {
		break;
	}
	default:
		cout << "Invalid input" << endl;
		ModifyCustomerInfo(s);
		break;
	}
}

