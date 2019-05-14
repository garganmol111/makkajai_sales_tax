#pragma once
#include "pch.h"
#include "ShoppingBasket.h"
#include <typeinfo>
#include <iostream>
#include <string>
#include "Item.h"
#include <boost/format.hpp>

#pragma region Constructors

ShoppingBasket::ShoppingBasket() {
	this->salesTax = 0.0;
	this->totalAmount = 0.0;
}

ShoppingBasket::ShoppingBasket(std::vector<std::string> &input) {	

	for (auto i : input) {
		Item newItem(i);
		items.push_back(newItem);
	}

	calculateAmountBeforeTax();
	calculateSalesTax();
	calculateTotalAmount();
}

ShoppingBasket::~ShoppingBasket() {
}

#pragma endregion


#pragma region Private Methods

//Calculates total amount before tax
void ShoppingBasket::calculateAmountBeforeTax() {
	double temp = 0;

	for (Item i : items) {
		temp += i.getItemPrice();
	}

	amountBeforeTax = temp;
}

//Calculates total tax amount applicable to the bill.
void ShoppingBasket::calculateSalesTax() {
	double temp = 0.0;
	for (Item i : this->items) {
		temp += i.getTaxAmount();
	}
	salesTax = temp;
}

//Calculates the final amount to be paid.
void ShoppingBasket::calculateTotalAmount() {
	totalAmount = amountBeforeTax + salesTax;
}

#pragma endregion


#pragma region Getters

double ShoppingBasket::getAmountBeforeTax() {
	return amountBeforeTax;
}

double ShoppingBasket::getSalesTax() {
	return salesTax;
}

double ShoppingBasket::getTotalAmount() {
	return totalAmount;
}

#pragma endregion


#pragma region Public Methods

std::string ShoppingBasket::toString() {

	std::string temp = "";
	
	for (Item i : items) {
		temp += i.toString();
	}

	temp += "Sales Taxes: " + boost::str(boost::format("%.2f") % salesTax) + "\n";
	temp += "Total: " + boost::str(boost::format("%.2f") % totalAmount) + "\n";

	return temp;
}

#pragma endregion

