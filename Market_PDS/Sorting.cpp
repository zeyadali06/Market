#include "Sorting.h"

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
void Sorting::print_row(T0 t0, T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6)
{
	cout << left << std::setw(15) << t0
		<< left << std::setw(15) << t1
		<< left << std::setw(15) << t2
		<< left << std::setw(15) << t3
		<< left << std::setw(15) << t4
		<< left << std::setw(15) << t5
		<< left << std::setw(15);
	if (typeid(const char*) == typeid(t6))
		printf("%s\n", t6);
	else
		printf("%.2f\n", t6);
}

bool Sorting::SortingWay(vector<product> allprod) {
	int type;
	while (true)
	{
		cout << "Sorting by:\n1- Name\n2- Category\n3- Rating\n4- Exit\n";
		cin >> type;
		if (type == 1)
		{
			vector<product>products = toSort(allprod, "name");
			print_data(products);
			return true;
		}
		else if (type == 2)
		{
			string cat = Sorting::setGetCategory(allprod);
			vector<product> sortedProducts = toSort(allprod, "category", cat);
			vector<product> products = Sorting::names_sorting(sortedProducts);
			Sorting::print_data(products);
			return true;
		}
		else if (type == 3)
		{
			vector<product> products = Sorting::toSort(allprod, "rating");
			Sorting::print_data(products);
			return true;
		}
		else if (type == 4)
		{
			return false;
		}
		else
		{
			cout << "Invaled Choise\n";
			continue;
		}
	}
}

vector<product> Sorting::toSort(vector<product>products, string way, string catg) {
	if (way == "name")
	{
		return Sorting::names_sorting(products);
	}
	else if (way == "category")
	{
		vector<product>::iterator it;
		vector<product> ProdOfSelectedCat;
		for (it = products.begin(); it != products.end(); it++)
		{
			if (it->getCategory() == catg)
			{
				ProdOfSelectedCat.push_back(*it);
			}
		}
		return ProdOfSelectedCat;
	}
	else if (way == "rating")
	{
		return Sorting::rate_sorting(products);
	}
}

void Sorting::print_data(vector<product> p) {
	cout << setprecision(2);
	vector<product>::iterator it = p.begin();
	system("cls");
	print_row("Name", "ID", "Category", "Quantity", "Seller_Id", "Product_Rating", "Price");
	for (it = p.begin(); it != p.end(); it++)
	{
		float rateProduct;
		if (it->getratnum() == 0)
		{
			rateProduct = 0;
		}
		else rateProduct = it->getRate() / it->getratnum();
		print_row(it->getName(), it->getId(), it->getCategory(), it->getQuantity(),
			it->getSellerId(), rateProduct,
			it->getPrice());
	}
}

void Sorting::setGetProduct(vector<product> p) {
	cout << "Choose Product:\n";
	int NoProduct;
	cin >> NoProduct;
	vector<product>::iterator it = p.begin();
	for (int i = 1; it != p.end(); i++)
	{
		if (NoProduct == i)
		{
			cout << it->getName() << ":\nPrice: " << it->getPrice() << "EGP\n"
				<< ((it->getQuantity() == 0) ? "Out of Stock\n" : "In Stock\n") << it->getQuantity() << "\n";
			return;
		}
		it++;
	}
}


set<string> Sorting::getAllCategories(vector<product> p) {
	set<string> categories;
	vector<product>::iterator it;
	for (it = p.begin(); it != p.end(); it++)
	{
		categories.insert(it->getCategory());
	}
	return categories;
}

string Sorting::setGetCategory(vector<product> p) {
	set<string> categories = getAllCategories(p);
	set<string>::iterator it = categories.begin();
	int NoCategory;
	while (true)
	{
		cout << "Choose Category:\n";
		for (int i = 1; it != categories.end(); i++)
		{
			cout << i << "- " << *it << "\n";
			it++;
		}
		cin >> NoCategory;
		it = categories.begin();
		for (int i = 1; it != categories.end(); i++)
		{
			if (i == NoCategory)
				return *it;
			it++;
		}
		cout << "invalid category number" << endl;
	}
}

vector<product> Sorting::names_sorting(vector<product> prod) {
	sort(prod.begin(), prod.end(), s);
	return prod;
}

bool Sorting::s(product p1, product p2) {
	return (p1.getName() < p2.getName());
}

bool Sorting::r(product p1, product p2) {
	return (p1.getRate() / p1.getratnum() > p2.getRate() / p2.getratnum());
}

vector<product> Sorting::rate_sorting(vector<product> p) {
	sort(p.begin(), p.end(), r);
	return p;
}
