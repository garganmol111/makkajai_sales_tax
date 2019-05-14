#pragma once
#include <vector>
#include "Item.h"
class ShoppingBasket {
	
private:
	std::vector<Item> items;
	double salesTax;
	double totalAmount;
	double amountBeforeTax;

	//Private Methods
	void calculateSalesTax();
	void calculateTotalAmount();
	void calculateAmountBeforeTax();

public:

	//Constructors
	ShoppingBasket();
	ShoppingBasket(std::vector<std::string>&);
	~ShoppingBasket();

	//Getters
	double getSalesTax();
	double getAmountBeforeTax();
	double getTotalAmount();

	//Public Methods
	std::string toString();
};

