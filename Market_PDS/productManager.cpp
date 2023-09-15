#include "productManager.h"

product* productManager::search(int id) {
	for (int i = 0; i < product::allProducts.size(); i++)
	{
		if (product::allProducts[i].getId() == id)
		{
			return &product::allProducts[i];
		}
	}
	return NULL;
}


void productManager::productrate(product* p) {
	int rate;
	cout << "Please rate our product from 1 to 5 " << endl;
	cin >> rate;
	if (rate < 0 || rate > 5) {
		cout << "invalid rate" << endl;
	}
	else
	{
		if (p->getratnum() == 0)
		{
			p->setrate(rate);
			p->IncrementCountRate();
			cout << "Thanks for your time" << endl;
			return;
		}
		float y = p->getRate() + rate;
		p->setrate(y);
		p->IncrementCountRate();
		cout << "Thanks for your time" << endl;
	}
}

bool productManager::ProductSellerExist(int id) {
	for (size_t i = 0; i < product::allProducts.size(); i++)
	{
		if (product::allProducts[i].getSellerId() == id)
		{
			return true;
		}
	}
	return false;
}
