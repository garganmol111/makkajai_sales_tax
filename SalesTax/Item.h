#pragma once
#include <string>

//Item class, which includes all the details about the items.
class Item {

private:
	std::string itemName;
	double itemPrice;
	int itemQuantity;
	bool isImported = false;
	std::string itemCategory = "none";
	double taxRate;
	double taxAmount;
	double finalPrice;

	//Private Methods
	void calculateTaxRate();
	void calculateTaxAmount();
	void calculateFinalPrice();
	void findItemCategory(std::string);
	double round(double);

public:

	//Constructors
	Item();
	Item(std::string, std::string, double, int, bool);
	Item(std::string);
	~Item();

	//Getters
	double getTaxRate();
	double getTaxAmount();
	double getFinalPrice();
	double getItemPrice();

	//Public Methods
	std::string toString();
};

