#include "registration.h"

int registration::sellerLastId = 0;
int registration::customerLastId = 0;

void  registration::RegistrationMenu() {
	Sleep(1250);
	system("cls");
	cout << "Registration options\n 1-Seller\n 2-Customer\n ";
}

bool  registration::RegistratioOption() {
	cout << "Enter your choice";
	int choice;
	cin >> choice;
	if (choice == 1) {
		SellerRegistration();
	}
	else if (choice == 2) {
		CustomerRegistration();
	}
	else
		cout << "invaled Choice\n";
	return true;
}

void registration::SellerRegistration() {
	system("cls");
	int id;
	string name, email;
	cout << "Enter your information \n";
	cout << "Name: ";
	cin >> name;
	cout << "Email: ";
	cin >> email;

	if (seller::allseller.empty()) {
		id = 0;
	}
	else {
		seller s = (--seller::allseller.end())->second;
		id = sellerLastId;
	}

	if (seller::allseller.find(email) == seller::allseller.end()) {
		seller s(id, name, email);
		seller::allseller.insert({ email,s });
		sellerLastId++;
		cout << "your registration has been confirmed\n";
	}
	else {
		cout << "Email already exist\n";
	}
}

void  registration::CustomerRegistration() {
	system("cls");
	int id = 0;
	string name, email, address, phoneNumber;
	cout << "Enter your information \n";
	cout << "Name: ";
	cin >> name;
	cout << "Email: ";
	cin >> email;
	cout << "Address: ";
	cin >> address;
	cout << "Phone number: ";
	cin >> phoneNumber;
	if (customer::allcustomers.empty()) {
		id = 0;
	}
	else
	{
		customer c = (--customer::allcustomers.end())->second;
		id = customerLastId;
	}
	if (customer::allcustomers.find(email) == customer::allcustomers.end()) {
		customer c(id, name, email, address, phoneNumber);
		customer::allcustomers.insert({ email,c });
		customerLastId++;
		cout << "your registration has been confirmed\n";
	}
	else {
		cout << "Email already exist\n";
	}
}

void  registration::setSellerLastid(int id) {
	sellerLastId = id;
}

int  registration::getSellerLastid() {
	return sellerLastId;
}

void  registration::setCustomerLastid(int id) {
	customerLastId = id;
}

int registration::getCustomerLastid() {
	return customerLastId;
}
