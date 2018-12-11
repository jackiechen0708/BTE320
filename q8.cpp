#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const double TAX_RATIO = 0.065;
const double TIP_RATIO = 0.2;

struct meal {
	string name;
	double price;
};
constexpr int NUM_OF_APPETIZERS = 4;
constexpr int NUM_OF_ENTREES = 5;
constexpr int NUM_OF_DRINKS = 3;
constexpr int NUM_OF_DESERTS = 3;

meal appetizers[NUM_OF_APPETIZERS] = {
	{ "Chicken Satay",7.50 },
{ "Egyptian Spring Rolls",6.50 },
{ "Humus",5.50 },
{ "Samboosa",5.50 }
};

meal entrees[NUM_OF_ENTREES] = {
	{ "Shish Tawooq - Chicken Kabaab",13.50 },
{ "Shish Kabaab- Beef Kabaab",16.50 },
{ "Fatta Bel Mooza",17.25 },
{ "Koshary - vegetarian",10.25 },
{ "Koshary - with meat sauce",12.25 }
};

meal drinks[NUM_OF_DRINKS] = {
	{ "Tea with mint",2.25 },
{ "Turkish Coffee",2.25 },
{ "Soda",2.00 }
};

meal deserts[NUM_OF_DESERTS] = {
	{ "Rice Pudding - with rose water",6.00 },
{ "Bamboosa - 2 pieces",4.50 },
{ "Mango Pudding",6.00 }
};

int main() {

	string input_s = "";
	int input;
	stringstream convert;
	int item_count = 0;
	string item = "";
	string cur = "";
	double Subtotal = 0;
	double Tax = 0;
	double Tip = 0;
	double Total = 0;


	while (input_s != "q") {
		int idx = 1;
		cout << "\t\tWelcome to the Miami Favorites Meal Builder\t" << endl;
		cout << "\t\t===========================================\t" << endl;
		cout << endl;
		cout << "\t\tNewMean (n)\t\t\tQuit (q)\t" << endl;
		cout << "\t\t\t\tAppetizers" << endl;
		cout << endl;
		for (int i = 0; i < NUM_OF_APPETIZERS; i++) {
			std::cout << std::left << std::setw(10) << std::left << idx;
			idx++;
			std::cout << std::left << std::setw(45) << appetizers[i].name;
			std::cout << "$" << std::left << std::setw(70) << appetizers[i].price << std::endl;
		}
		cout << endl;
		cout << "\t\t\t\tEntrees" << endl;
		cout << endl;
		for (int i = 0; i < NUM_OF_ENTREES; i++) {
			std::cout << std::left << std::setw(10) << std::left << idx;
			idx++;
			std::cout << std::left << std::setw(45) << entrees[i].name;
			std::cout << "$" << std::left << std::setw(70) << entrees[i].price << std::endl;
		}
		cout << endl;
		cout << "\t\t\t\tDrinks" << endl;
		cout << endl;
		for (int i = 0; i < NUM_OF_DRINKS; i++) {
			std::cout << std::left << std::setw(10) << std::left << idx;
			idx++;
			std::cout << std::left << std::setw(45) << drinks[i].name;
			std::cout << "$" << std::left << std::setw(70) << drinks[i].price << std::endl;
		}
		cout << endl;
		cout << "\t\t\t\tDessert" << endl;
		cout << endl;
		for (int i = 0; i < NUM_OF_DESERTS; i++) {
			std::cout << std::left << std::setw(10) << std::left << idx;
			idx++;
			std::cout << std::left << std::setw(45) << deserts[i].name;
			std::cout << "$" << std::left << std::setw(70) << deserts[i].price << std::endl;
		}
		cout << endl;
		cout << endl;
		cout << "Please enter item[1-15]: ";

		cin >> input_s;
		if (input_s == "n") {
			item.clear();
			Subtotal = 0;
			Tax = 0;
			Tip = 0;
			Total = 0;
			item_count = 0;
		}
		else if (input_s == "q") {
			exit(0);
		}
		else {
			convert.str("");
			convert.clear();
			convert << input_s;
			convert >> input;
			switch (input) {
			
			case 1:
			case 2:
			case 3:
			case 4:
				convert.str("");
				convert.clear();
				convert << std::left << std::setw(10) << input
					<< std::left << std::setw(10) << "Appetizers"
					<< std::left << std::setw(40) << appetizers[input - 1].name
					<< "$" << appetizers[input - 1].price << endl;
				item = item + convert.str();
				Subtotal = Subtotal + appetizers[input - 1].price;
				Tax = Subtotal * TAX_RATIO;
				Tip = Subtotal * TIP_RATIO;
				Total = Subtotal + Tax + Tip;
				item_count = item_count + 1;
				break;
			
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				input -= 4;
				convert.str("");
				convert.clear();
				convert << std::left << std::setw(10) << input 
					<< std::left << std::setw(10) << "Entrees"
					<< std::left << std::setw(40) <<entrees[input - 1].name 
					<< "$" << entrees[input - 1].price << endl;
				convert >> cur;
				item = item + convert.str();
				Subtotal = Subtotal + entrees[input - 1].price;
				Tax = Subtotal * TAX_RATIO;
				Tip = Subtotal * TIP_RATIO;
				Total = Subtotal + Tax + Tip;
				item_count = item_count + 1;
				break;
			
			case 10:
			case 11:
			case 12:
				input -= 9;
				convert.str("");
				convert.clear();
				convert << std::left << std::setw(10) << input
					<< std::left << std::setw(10) << "Drinks"
					<< std::left << std::setw(40) << drinks[input - 1].name
					<< "$" << drinks[input - 1].price << endl;
				convert >> cur;
				item = item + convert.str();
				Subtotal = Subtotal + drinks[input - 1].price;
				Tax = Subtotal * TAX_RATIO;
				Tip = Subtotal * TIP_RATIO;
				Total = Subtotal + Tax + Tip;
				item_count = item_count + 1;
				break;
			case 13:
			case 14:
			case 15:
				input -= 12;
				convert.str("");
				convert.clear();
				convert << std::left << std::setw(10) << input
					<< std::left << std::setw(10) << "Dessert"
					<< std::left << std::setw(40) << deserts[input - 1].name
					<< "$" << deserts[input - 1].price << endl;
				convert >> cur;
				item = item + convert.str();
				Subtotal = Subtotal + deserts[input - 1].price;
				Tax = Subtotal * TAX_RATIO;
				Tip = Subtotal * TIP_RATIO;
				Total = Subtotal + Tax + Tip;
				item_count = item_count + 1;
				break;
			default:
				cout << "Invalid Input" << endl;
			}
		}

		cout << "=======================================================================\nYour current meal has ";
		cout << to_string(item_count);
		cout << " item(s).\n";
		cout << item;
		cout << "=======================================================================\n";
		cout << "\t\t\t\t\t\tSubtotal =  $";
		cout << Subtotal;
		cout << "\n\t\t\t\t\t\tTax =  $";
		cout << Tax;
		cout << "\n\t\t\t\t\t\tTip =  $";
		cout << Tip;
		cout << "\n\t\t\t\t\t\tTotal =  $";
		cout << Total;
		cout << endl;
		cout << endl;

	}
}
