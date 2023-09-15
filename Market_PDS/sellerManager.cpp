#include "sellerManager.h"

void sellerManager::sellerMenu() {
	Sleep(1250);
	system("cls");
	cout << "\t\t\t\t\t\tSeller Functions\n";
	cout << "SellerMenu" << endl
		<< "1- Add product" << endl
		<< "2- Modify product" << endl
		<< "3- Remove Product" << endl
		<< "4-modify acount info" << endl
		<< "5- Back" << endl;
}

void sellerManager::addProduct(seller s) {
	cout << "Enter product information" << endl
		<< "ID: ";
	int   qunt, id;
	double price;
	string name, catg;
	cin >> id;
	cout << endl << "Name: ";
	cin >> name;
	cout << endl << "Price: ";
	cin >> price;
	cout << endl << "Quantaty: ";
	cin >> qunt;
	catg = chooseCategory();
	if (!ifExist(id)) {
		product p(id, name, price, catg, qunt, s.getid());
		product::allProducts.push_back(p);
		cout << "product Add successfuly\n" << endl;
	}
	else {
		cout << "product id already exist\n";
	}
}

bool sellerManager::sellerOption(seller* s) {
	cout << "enter your choice" << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1: {
		addProduct(*s);
		break;
	}
	case 2: {
		modifyProduct(*s);
		break;
	}
	case 3: {
		RemoveProduct(*s);
		break;
	}
	case 4: {
		ModifySeller(s);
		break;
	}
	case 5: {
		return true;
	}
	default: {
		cout << "invalid choice\n";
		break;
	}
	}
	sellerMenu();
	sellerOption(s);
}

void sellerManager::sellerrate(seller* s) {

	int rate;
	cout << "Please rate the seller from 1 to 5 " << endl;
	cin >> rate;
	if (rate < 0 || rate > 5) {
		cout << "invalid rate" << endl;
	}
	else
	{
		if (s->getratnum() == 0)
		{
			s->setrate(rate);
			s->IncrementCountRate();
			return;
		}
		float y = s->getRate() + rate;
		s->setrate(y);
		s->IncrementCountRate();
		cout << "Thanks for your time" << endl;
	}
}

void sellerManager::sellerProducts(seller s) {
	Sleep(1250);
	system("cls");
	sellerManager::print_row("Id", "Name", "Quantity", "Category", "Price");

	for (int i = 0; i < product::allProducts.size(); i++)
	{
		if (product::allProducts[i].getSellerId() == s.getid())
		{
			sellerManager::print_row(product::allProducts[i].getId(),
				product::allProducts[i].getName(), product::allProducts[i].getQuantity(),
				product::allProducts[i].getCategory(), product::allProducts[i].getPrice());
		}
	}
}

void sellerManager::sellerModifyMenu() {
	cout << "\t\t\t\t\t\tModify Menu\n";
	cout << "what do you want to modify?" << endl
		<< "1- ID" << endl
		<< "2- name" << endl
		<< "3- Price" << endl
		<< "4- category" << endl
		<< "5- Quantity" << endl
		<< "6- exit" << endl;
}

void sellerManager::sellerModifyOption(seller s, product* p) {
	cout << "enter your choise" << endl;
	int choice; cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "enter new Id" << endl;
		int id; cin >> id;
		if (!ifExist(id)) {
			p->setId(id);
			cout << "ID modified sucessfuly\n";
		}
		else {
			cout << "id is already exist\n";
		}
		break;
	}
	case 2: {
		cout << "enter new Name" << endl;
		string name; cin >> name;
		p->setName(name);
		cout << "Name modified sucessfuly\n";
		break;
	}
	case 3: {
		cout << "enter new Price" << endl;
		int price; cin >> price;
		p->setPrice(price);
		cout << "Price modified sucessfuly\n";
		break;
	}
	case 4: {
		cout << "enter new category" << endl;
		p->setCategory(chooseCategory());
		cout << "Category modified sucessfuly\n";
		break;
	}
	case 5: {
		cout << "enter new Quantity" << endl;
		int quan; cin >> quan;
		p->setQuantity(quan);
		cout << "Quantity modified sucessfuly\n";
		break;
	}
	case 6: {
		break;
	}
	default: {
		cout << "invaled choice\n" << endl;
		sellerModifyMenu();
		sellerModifyOption(s, p);
		break;
	}
	}
}

void sellerManager::RemoveProduct(seller s) {
	if (productManager::ProductSellerExist(s.getid()))
	{
		sellerProducts(s);
		int id;
		bool found = false;
		cout << "Enter product ID: ";
		cin >> id;
		cout << endl;
		for (int i = 0; i < product::allProducts.size(); i++) {
			if (product::allProducts[i].getId() == id) {
				if (product::allProducts[i].getSellerId() == s.getid()) {
					product::allProducts.erase(product::allProducts.begin() + i);
					found = true;
					cout << "Product removed sucssefully" << endl;
					break;
				}
				else {
					cout << "seller doesen't have acsses in this product" << endl;
					break;
				}
			}
		}
		if (found == false)
			cout << "invalid ID" << endl;
	}
	else {
		system("cls");
		cout << "You Dont have Products" << endl;

	}
}

void sellerManager::modifyProduct(seller s) {
	if (productManager::ProductSellerExist(s.getid()))
	{
		sellerProducts(s);
		cout << "Enter id of product" << endl;
		int id;
		cin >> id;
		bool find = false;
		for (int i = 0; i < product::allProducts.size(); i++)
		{
			if (product::allProducts[i].getId() == id)
			{
				if (product::allProducts[i].getSellerId() == s.getid())
				{
					sellerModifyMenu();
					sellerModifyOption(s, &product::allProducts[i]);
					find = true;
					break;
				}
				else {
					cout << "you dont have permission to modify this product" << endl;
					find = true;
					break;
				}
			}
		}
		if (find == false)
		{
			cout << "the product doesnot exist \n";
			Sleep(1250);
		}
	}
	else {
		system("cls");
		cout << "You Dont have Products" << endl;
	}
}

void sellerManager::ModifySeller(seller* s) {
	Sleep(1250);
	system("cls");
	cout << "what do you want to modify?" << endl
		<< "1- Name" << endl
		<< "2- Email" << endl
		<< "3-Back" << endl;

	int c; cin >> c;
	system("cls");
	switch (c)
	{
	case 1: {
		cout << "enter new name\n";
		string name; cin >> name;
		s->setName(name);
		cout << "Name modified sucessfuly\n";
		break;
	}
	case 2: {
		cout << "enter new email\n";
		string email; cin >> email;
		s->setEmail(email);
		cout << "email modified sucessfuly\n";
		break;
	}
	case 3: {
		break;
	}
	default:
		cout << "Invalid input" << endl;
		ModifySeller(s);
		break;
	}
}

seller* sellerManager::search(int id) {
	for (seller::itSeller = seller::allseller.begin(); seller::itSeller != seller::allseller.end(); seller::itSeller++)
	{
		if (seller::itSeller->second.getid() == id)
		{
			return &seller::itSeller->second;
		}
	}
	return NULL;
}

bool sellerManager::ifExist(int id) {
	for (int i = 0; i < product::allProducts.size(); i++) {
		if (product::allProducts[i].getId() == id) {
			return true;
		}
	}
	return false;
}

string sellerManager::chooseCategory() {
	cout << endl << "Category:  1-books \n 2-gaming \n 3-electronics \n 4-food&drinks\n";
	int choose;
	cin >> choose;
	switch (choose)
	{
	case 1: {
		return "books";
		break;
	}
	case 2: {
		return "gaming ";
	}
	case 3: {
		return "electronics";
	}
	case 4: {
		return  "food&drinks";
	}
	default:
		cout << "invaled choice\n" << endl;
		return chooseCategory();
		break;
	}
}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
void sellerManager::print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4)
{
	cout << left << std::setw(15) << t0
		<< left << std::setw(15) << t1
		<< left << std::setw(15) << t2
		<< left << std::setw(15) << t3
		<< left << std::setw(15);
	if (typeid(const char*) == typeid(t4))
		printf("%s\n", t4);
	else
		printf("%.2f\n", t4);
}
