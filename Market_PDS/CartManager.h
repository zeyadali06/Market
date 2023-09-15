#pragma once
#include "Cart.h"
#include "customer.h"
#include "productManager.h"
#include "sellerManager.h"

class CartManager {

public:

	static void cartMenu();

	static bool cartProduct(customer* c);

	static void cartOption(customer* c);

	static void ratingMenu();

	static void rating(customer* c);

	static void checkOut(customer* c);

	static void rateProduct(customer* c);

	static void rateSeller(customer* c);

	static void editQuantity(customer* c);

	static void removeProduct(customer* c);
};

