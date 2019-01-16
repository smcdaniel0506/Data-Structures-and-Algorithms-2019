//============================================================================
// Name        : Lab1-3.cpp
// Author      : Steven McDaniel
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Define a structure BidData to hold bid information together as a single unit of storage.
struct BidData {
	string title;
	string fund;
	string vID;
	double bid;
};

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}

// Displays the bid values passed in BidData structure
void displayBid(BidData bid) {
	cout << "Title: " << bid.title << endl;
	cout << "Fund: " << bid.fund << endl;
	cout << "Vehicle: " << bid.vID << endl;
	cout << "Bid Amount: " << bid.bid << endl;

	return;
}

// Store user input values in BidData structure
BidData getBid() {
	BidData bid;

	cout << "Enter title: ";
	cin.ignore();
	getline(cin, bid.title);

	cout << "Enter fund: ";
	cin >> bid.fund;

	cout << "Enter vehicle: ";
	cin.ignore();
	getline(cin, bid.vID);
	cout << "Enter amount:\n"
			"*************************************\n"
			"NOTE: Bids must begin with \"$\" and \n"
			"contain no commas to ensure your bid \n"
			"is accurately logged into the system.\n"
			"*************************************\n";
	cin.ignore();
	string strAmount;
	getline(cin, strAmount);
	bid.bid = strToDouble(strAmount, '$');

	return bid;
}

/**
 * The one and only main() method
 */
int main() {

	// Declare instance of data structure to hold bid information
	BidData newBid;

	// loop to display menu until exit chosen
	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << "  1. Enter Bid" << endl;
		cout << "  2. Display Bid" << endl;
		cout << "  9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		// Calls a method depending on user choice
		switch (choice) {
		case 1:
			newBid = getBid();
			break;
		case 2:
			displayBid(newBid);
			break;
		}
	}

	cout << "Good bye." << endl;

	return 0;
}
