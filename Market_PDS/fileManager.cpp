#include "fileManager.h"

void fileManager::saveCustomers() {
	fstream file("Customers.txt", ios::app);
	for (customer::itCustomer = customer::allcustomers.begin(); customer::itCustomer != customer::allcustomers.end(); customer::itCustomer++)
	{
		file << customer::itCustomer->second.getid() << "|" << customer::itCustomer->second.getName() << "|"
			<< customer::itCustomer->second.getEmail() << "|" << customer::itCustomer->second.getAddress()
			<< "|" << customer::itCustomer->second.getPhoneNumber() << "\n";
	}
	file.close();
}
void fileManager::getCustomers() {
	fstream file("Customers.txt", ios::in);
	string data;
	while (getline(file, data, '\n'))
	{
		customer c = parser::parserToCustomer(data);
		customer::allcustomers.insert({ c.getEmail(),c });
	}
	file.close();
}
void fileManager::saveSellers() {
	fstream file("Sellers.txt", ios::app);
	for (seller::itSeller = seller::allseller.begin(); seller::itSeller != seller::allseller.end(); seller::itSeller++)
	{
		file << seller::itSeller->second.getid() << "|" << seller::itSeller->second.getName()
			<< "|" << seller::itSeller->second.getEmail() <<
			"|" << seller::itSeller->second.getRate() <<
			"|" << seller::itSeller->second.getratnum() << "\n";
	}
	file.close();
}

void fileManager::getSellers() {
	fstream file("Sellers.txt", ios::in);
	string data;
	while (getline(file, data, '\n'))
	{
		seller s = parser::parserToSeller(data);
		seller::allseller.insert({ s.getEmail(),s });
	}
	file.close();
}

void fileManager::saveProducts() {
	fstream file("Products.txt", ios::app);
	for (int i = 0; i < product::allProducts.size(); i++)
	{
		file << product::allProducts[i].getId() << "|" << product::allProducts[i].getName() << "|"
			<< product::allProducts[i].getPrice() << "|" << product::allProducts[i].getCategory() << "|"
			<< product::allProducts[i].getQuantity() << "|" << product::allProducts[i].getSellerId() << "|" <<
			product::allProducts[i].getRate() << "|" << product::allProducts[i].getratnum() << "\n";
	}
	file.close();
}

void fileManager::getProducts() {
	fstream file("Products.txt", ios::in);
	string data;
	while (getline(file, data, '\n'))
	{
		product p = parser::parserToProduct(data);
		product::allProducts.push_back(p);
	}
	file.close();
}

void fileManager::get_SellerLastid() {
	fstream file("SellerLastId.txt", ios::in);
	string data;
	while (getline(file, data, '\n')) {
		registration::setSellerLastid(stoi(data));
	}
	file.close();
}

void fileManager::save_SellerLastid() {
	fstream file("SellerLastId.txt", ios::out);
	file << registration::getSellerLastid();
	file.close();
}

void fileManager::get_CustomerLastid() {
	fstream file("CustomerLastId.txt", ios::in);
	string data;
	while (getline(file, data, '\n')) {
		registration::setCustomerLastid(stoi(data));
	}
	file.close();
}

void fileManager::save_CustomerLastid() {
	fstream file("CustomerLastId.txt", ios::out);
	file << registration::getCustomerLastid();
	file.close();
}

void fileManager::clearAllCustomers() {
	fstream file("Customers.txt", ios::out);
}

void fileManager::clearAllProducts() {
	fstream file("Sellers.txt", ios::out);
}

void fileManager::clearAllSellers() {
	fstream file("Products.txt", ios::out);
}

void fileManager::clearAllFiles() {
	clearAllCustomers();
	clearAllProducts();
	clearAllSellers();
}