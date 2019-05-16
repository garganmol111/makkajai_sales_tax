// SalesTax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>s
#include <cstring>
#include <boost/tokenizer.hpp>
#include "ShoppingBasket.h"
#include "Item.h"


int main() {
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"; 
	std::cout << "|                            SALES TAX CALCULATOR                           |\n";
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	std::cout << "\nPlease enter the contents of the shopping basket. Enter \"Submit\" when done:\n";

	std::vector<std::string> input;

	std::string temp;

	while (true) {
		getline(std::cin, temp);
		
		if (temp == "submit" || temp == "Submit" || temp == "SUBMIT")	break;

		input.push_back(temp);
	}

	ShoppingBasket shoppingBasket(input);

	std::cout << "\n" << shoppingBasket.toString();
	
	
	
	return 0;
}
