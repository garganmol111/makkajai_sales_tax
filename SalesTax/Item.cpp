#pragma once
#include "pch.h"
#include "Item.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <boost/format.hpp>


#pragma region Constructors

Item::Item() {
	itemName = "DefaultName";
	itemCategory = "DefCat";
	itemPrice = 0.0;
	itemQuantity = 0;
	isImported = false;
}

Item::Item(std::string itemName, std::string itemCategory, double itemPrice, int itemQuantity, bool isImported) {
	this->itemName = itemName;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;
	this->isImported = isImported;
	this->itemCategory = itemCategory;
}

//Creates item object from the received input from ShoppingBasket
Item::Item(std::string itemInput) {

	std::vector<std::string> tokens;

	boost::split(tokens, itemInput, boost::is_any_of(" "));

	itemQuantity = boost::lexical_cast<int> (tokens.front());
	itemPrice = boost::lexical_cast<double> (tokens.back());

	tokens.erase(tokens.begin());
	tokens.pop_back();
	
	auto iter = std::find(tokens.begin(), tokens.end(), "imported");
	if (iter != tokens.end()) { 
		isImported = true; 
		tokens.erase(iter);
	}

	tokens.pop_back();

	itemName = std::accumulate(tokens.begin(), tokens.end(), std::string(""), [](std::string s1, std::string s2) {
		std::string x = s1 + " " + s2;
		boost::trim(x);
		return x;
	});

	findItemCategory(itemName);

	calculateTaxRate();
	calculateTaxAmount();
	calculateFinalPrice();
}


Item::~Item() {
}

#pragma endregion


#pragma region Private Methods

//Calculates the tax rate per item
void Item::calculateTaxRate() {
	double tax = 0.0;
	if (itemCategory == "book" || itemCategory == "food" || itemCategory == "med") tax = 0.0;
	else {
		tax = 10.0;
	}

	if (isImported)	tax += 5.0;

	taxRate = tax;
}

//Calculates the tax amount per item
void Item::calculateTaxAmount() {
	if (taxRate == 0.0) { taxAmount = 0.0; return; }
	else  taxAmount = itemPrice * taxRate / 100.0;
	taxAmount = round(taxAmount);
}

//Calculates the final price after sales tax per item
void Item::calculateFinalPrice() {
	finalPrice = itemPrice + taxAmount;
	//finalPrice = std::roundf(finalPrice * 100) / 100;
}

void Item::findItemCategory(std::string itemName) {
	if (itemName.find("book") != std::string::npos) {
		itemCategory = "book";
		return;
	}
	if (itemName.find("food") != std::string::npos || itemName.find("chocolate") != std::string::npos || itemName.find("chocolates") != std::string::npos) {
		itemCategory = "food";
		return;
	}
	if (itemName.find("med") != std::string::npos || itemName.find("medicine") != std::string::npos || itemName.find("pills") != std::string::npos || itemName.find("headache") != std::string::npos) {
		itemCategory = "med";
		return;
	}
}

double Item::round(double amt) {
	
	int x = (int)(amt*10);
	double temp = (amt * 10) - (x);
	if (temp < 0.25)	temp = 0.0;
	else if (temp >= 0.25 && temp <= 0.50)	temp = 0.5;
	else	temp = 1.0;

	return (temp + (double)x) / 10;

}
#pragma endregion


#pragma region Getters

double Item::getTaxRate() {
	return taxRate;
}

double Item::getTaxAmount() {
	return taxAmount;
}

double Item::getFinalPrice() {
	return finalPrice;
}

double Item::getItemPrice() {
	return itemPrice;
}

#pragma endregion

#pragma region Public Methods

std::string Item::toString() {
	std::string temp = "";
	temp += boost::lexical_cast<std::string> (itemQuantity) + " ";
	temp += isImported ? "imported " : "";
	temp += itemName + ": ";
	//temp += boost::lexical_cast<std::string> (finalPrice) + "\n";
	temp += boost::str(boost::format("%.2f") % finalPrice) + "\n";

	return temp;
}

#pragma endregion
