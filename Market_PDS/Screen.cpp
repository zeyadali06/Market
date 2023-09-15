#include "Screen.h"

void Screen::loginAsMenu() {
	Sleep(1250);
	system("cls");
	cout << "Login As?" << endl
		<< "1- Seller" << endl
		<< "2- Customer" << endl
		<< "3- register" << endl
		<< "4- Exit" << endl;
}

int Screen::loginAsOption() {
	cout << "enter your choice: ";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		return 1;
	}
	case 2:
	{
		return 2;
	}
	case 3: {
		return 3;

	}
	case 4: {
		return 4;
	}
	default:
	{
		cout << "Invaled Choise\n";
		loginAsMenu();
		loginAsOption();
	}
	break;
	}
}

void Screen::loginOption(int choice) {

	switch (choice)
	{
	case 1: {
		loginSeller();
		break;
	}
	case 2: {
		loginCustomer();
		break;
	}
	case 3: {
		loginRegister();
		break;
	}
	case 4: {
		break;
	}
	}
}

void Screen::loginSeller() {
	bool validate = false;
	cout << "enter Your Email:" << endl;
	string email;
	cin >> email;

	if (seller::allseller.find(email) != seller::allseller.end())
	{
		sellerManager::sellerMenu();
		if (sellerManager::sellerOption(&seller::allseller.find(email)->second))
		{
			loginAsMenu();
			loginOption(loginAsOption());
		}
		validate = true;
	}
	if (validate == false)
	{
		cout << "Email doesnt exist\n";
		loginAsMenu();
		loginOption(loginAsOption());
	}
}

void Screen::loginCustomer() {
	bool validate = false;
	cout << "enter Your Email:" << endl;
	string email;
	cin >> email;

	if (customer::allcustomers.find(email) != customer::allcustomers.end())
	{
		CustomerManager::customerMenu();
		if (CustomerManager::customerOption(&(customer::allcustomers.find(email)->second)))
		{
			loginAsMenu();
			loginOption(loginAsOption());
		}
		validate = true;
	}

	if (validate == false)
	{
		cout << "Email doesnt exist\n";
		loginAsMenu();
		loginOption(loginAsOption());
	}
}

void Screen::loginRegister() {
	system("cls");
	registration::RegistrationMenu();
	if (registration::RegistratioOption()) {
		loginAsMenu();
		loginOption(loginAsOption());
	}
}

void Screen::Welcome()
{
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t##       ##   ######    ##      #######  ########   ##     ##   ######\n";
	cout << "\t\t\t##   #   ##   ##        ##      ##       ##    ##   ###   ###   ##\n";
	cout << "\t\t\t##  # #  ##   ######    ##      ##       ##    ##   ## # # ##   ######\n";
	cout << "\t\t\t## #   # ##   ##        ##      ##       ##    ##   ##  #  ##   ##\n";
	cout << "\t\t\t###     ###   ######    ######  #######  ########   ##     ##   ######\n";
	Sleep(2000);
	system("cls");
}

void Screen::runApp() {
	system("Color f4");
	fileManager::getSellers();
	fileManager::getCustomers();
	fileManager::getProducts();
	fileManager::get_SellerLastid();
	fileManager::get_CustomerLastid();
	Welcome();
	loginAsMenu();
	loginOption(loginAsOption());
	fileManager::clearAllFiles();
	fileManager::saveCustomers();
	fileManager::saveProducts();
	fileManager::saveSellers();
	fileManager::save_SellerLastid();
	fileManager::save_CustomerLastid();
}