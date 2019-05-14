#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "pch.h"
using namespace std;

void get_input(vector<string> &input) {

	string temp;

	while (true) {
		getline(cin, temp);
		if (temp.compare("Submit") || temp.compare("SUBMIT") || temp.compare("submit")) {
			break;
		}
		input.push_back(temp);
	}

}

