#include "Cart.h"

Cart::Cart() {}

Cart::Cart(vector<product> p) {
	totalPrice = getTotalPrice();
}

vector<product> Cart::getListProducts() {
	return products;
}

void Cart::clearAllProducts() {
	products.clear();
}

void Cart::fillCart(product p) {
	products.push_back(p);
}

double Cart::getTotalPrice() {
	totalPrice = 0;
	for (int i = 0; i < products.size(); i++)
	{
		totalPrice += (products[i].getQuantityOfuser() * products[i].getPrice());
	}
	return totalPrice;
}

bool Cart::isEmpty() {
	return products.empty();
}

void Cart::printCartInfo() {

	Cart::print_row("ID", "Name", "Quantity_User", "Rating", "Total_Quantity", "Seller_ID", "Seller_Rating", "Price");

	cout << setprecision(2);
	for (int i = 0; i < products.size(); i++)
	{
		float rateSeller, rateProduct;
		seller* s = sellerManager::search(products[i].getSellerId());

		if (s->getratnum() == 0)
			rateSeller = 0;
		else rateSeller = s->getRate() / s->getratnum();
		if (products[i].getratnum() == 0)
			rateProduct = 0;
		else rateProduct = products[i].getRate() / products[i].getratnum();

		Cart::print_row(products[i].getId(), products[i].getName(), products[i].getQuantityOfuser(),
			rateProduct, products[i].getQuantity(),
			products[i].getSellerId(), rateSeller, products[i].getPrice());
	}
}

void Cart::removeProduct(int postion) {
	products.erase(products.begin() + postion);
}

product* Cart::searchProduct(int id) {
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getId() == id)
		{
			return &products[i];
		}
	}
	return NULL;
}

seller* Cart::searchSeller(int id) {
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getSellerId() == id)
		{
			seller* s = sellerManager::search(id);
			return s;
		}
	}
	return NULL;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>

void Cart::print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6, T7 t7)
{
	cout << left << std::setw(15) << t0
		<< left << std::setw(15) << t1
		<< left << std::setw(15) << t2
		<< left << std::setw(15) << t3
		<< left << std::setw(15) << t4
		<< left << std::setw(15) << t5
		<< left << std::setw(15) << t6
		<< left << std::setw(15);

	if (typeid(const char*) == typeid(t7))
		printf("%s\n", t7);
	else
		printf("%.2f\n", t7);
}
