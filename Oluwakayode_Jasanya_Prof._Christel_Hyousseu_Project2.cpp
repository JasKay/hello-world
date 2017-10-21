/*
Name: Oluwakayode A. Jasanya
Professor: Prof. Christel Hyousseu
Class: EEGR 161
Project: Project 2. Managing a store Inventory and displaying it on a 'txt' file.
Date: 20/November/ 2016
*/

#include "stdafx.h"  //only works in visual studio
#include <iostream>  // to access cin and cout
#include <string>    // to access string and array
#include <sstream>
#include <stdlib.h>
#include <fstream>   // for if stream and ofstream and working on the file
#include <cmath>     // for Mathematical purposes.  N. B I implemented my advanced calculator to the code
using namespace std;

//This is the class for the advanced calculator
class Mycalculator
{
public:
	int var1, var2, var3, result;
	int Addition()  //addition
	{
		cout << "\n";
		cout << "Addition Operation\n";
		cout << "Enter the first number: ";
		cin >> var1;
		cout << "Enter the second number: ";
		cin >> var2;
		result = var1 + var2;
		cout << "The result of the sum is: " << result;
		cout << "\n";
		return result;
	}
	int Subtraction()  // subtraction
	{
		cout << "\n";
		cout << "Subtraction Operation\n";
		cout << "Enter the first number: ";
		cin >> var1;
		cout << "Enter the second number: ";
		cin >> var2;
		result = var1 - var2;
		cout << "The result of the difference is: " << result;
		cout << "\n";
		return result;
	}
	int Multiplication()  // for Multiplication
	{
		cout << "\n";
		cout << "Multiplication Operation\n";
		cout << "Enter the first number: ";
		cin >> var1;
		cout << "Enter the second number: ";
		cin >> var2;
		result = var1 * var2;
		cout << "The result of the product is: " << result;
		cout << "\n";
		return result;
	}
	int Division()   // for division
	{
		cout << "\n";
		cout << "Division Operation\n";
		cout << "Enter the first number: ";
		cin >> var1;
		cout << "Enter the second number: ";
		cin >> var2;
		result = var1 / var2;
		cout << "The result of the division is: " << result;
		cout << "\n";
		return result;
	}
	int Power()   // for Power
	{
		cout << "\n";
		cout << "Power Operation\n";
		cout << "Enter the first number: ";
		cin >> var1;
		cout << "Enter the second number: ";
		cin >> var2;
		result = pow(var1, var2);
		cout << "The result of the division is: " << result;
		cout << "\n";
		return 0;
	}
};

// this is the class of the project 2. This class works and helps a merchant manage his goods
class Kayodes
{
public:
	//data members for managing the code
	int Choice;
	string var1;
	//FoodBasket is the array for all the good we sell.; price is the price of each; quantities is the amount we have in the stock
	string FoodBasket[16] = { "Banana", "Oranges", "Apple", "Milk", "Bread", "Cake", "LightBulb", "ExtensionCords","Cap", "Iphone", "Saxophone", "Laptop", "Shirt", "Trouser", "Plate", "Tie" };
	double Prices[16] = { 2.50, 1.95, 2.85, 3.89, 1.25, 5.20, 1.30, 3.99, 2.4, 3.67, 4.6, 8.0, 7.0, 2.1, 6.8, 5.6 };
	double Quantities[16] = { 20, 30, 16, 5, 500, 2, 8, 20,4, 20, 40, 45, 23, 67, 79,12 };
	double Quant;
	double Price;
	int Users, Users2, Users3;

	//good user interface
	void Greeting_Message()
	{
		cout << "\n\t\t\t           ========================================\n";
		cout << "\t\t\t\tEEGR 161 SHOPPING COMPLEX, BALTIMORE MD 21251\n\n";
		cout << "\t\t Good day. Welcome to the store attending Machine at EEGR 161 Shopping Complex." << "\n";
		cout << "\t\t\t My name is OluwakayodeBot, and I will be assisting you to check out." << "\n";
		cout << "\t\t\t\t I am sure you had an awesome time shopping here.\n";
		cout << "\n";
	}
	// this displays the price, quantity, goods Id and uses a for loop to get it  to display everything
	double Display_Inventry()
	{
		cout << "|ID |Food Items |Prices |";
		cout << "\n";
		for (int i = 0; i < 16; i++)
		{
			cout << "|" << i + 1 << " |" << FoodBasket[i] << " |" << "$" << Prices[i] << " |\n";
		}
		return 0;
	}
	// this displays the total report of grand total, the quantity, the goods id and also does so in an array
	double Display_Report()
	{
		cout << "|ID      |Food Items         |Prices |      Quantity      |Grand Total |";
		cout << "\n";
		for (int i = 0; i < 16; i++)
		{
			cout << "|" << i + 1 << "      |" << FoodBasket[i] << " |" << "$" << Prices[i] << "    |" << Quantities[i] << "    |" << float(Prices[i] * Quantities[i]) <<  "|\n";
		}
		return 0;
	}
	// this do while loop ask the user what he wants to get and takes the user ID from him/her
	double Selection()
	{
		do
		{
			cout << "What do want to buy?\n";
			cout << "Enter Food Item ID\n";
			cout << "Choice: ";
			cin >> Choice;
			//control statement
			if (Choice >= 1 && Choice < 17)
			{
				Choice = Choice - 1;
				cout << "\n";
				cout << "Enter the Quantity of the item you want\n";
				cout << "Enter Quantity: ";
				cin >> Quant;
				//using control statement
				if (Quant >= 1 && Quant <= Quantities[Choice])
				{
					cout << "\n";
					cout << "Total Price for that purchase is: $" << float(Prices[Choice] * Quant);
					cout << "\n";
				}
				else
				{
					cout << "\n";
					cout << "Error 404!\n";
					cout << "Re-enter your Quantity!!!\n";
				}
			}
			else
			{
				cout << "\n";
				cout << "Error 404!\n";
				cout << "Re-enter your choice!!!\n";
			}
			cout << "Do you want to continue?\n";
			cout << "Enter 1-Continue | 0-Exit\n";
			cout << "Choice: ";
			cin >> Users2;
			cout << "\n";
		} while (Users2 != 0);
		return Price;
	}

	//This prompts the user what to be done.  1 signifies Inventory; 2 - Point of sale and 3 for report.
	//The function were called
	double UserSerlection()
	{
		do   //control statement
		{
			cout << "Select a value for what you want to do:" << "\n";
			cout << "Enter 1 for Inventory| 2 for Point of Sale| 3 for Report.\n";
			cout << "Enter Selection:";
			cin >> Users;
			if (Users == 1)
			{
				Display_Inventry(); //function call
			}
			else if (Users == 2) // control statement
			{
				Selection(); // function call
			}
			else if (Users == 3)
			{
				Display_Inventry(); // function call
			}
			else
			{
				cout << "Error 404!\n";
				cout << "Please Enter a new Choice\n";
				cout << "Enter Choice: ";
				cin >> Users;
				cout << "\n";
			}
			cout << "Do you want to continue?\n";
			cout << "Enter 1-Continue | 0-Exit\n";
			cout << "Choice: ";
			cin >> Users3;
			cout << "\n";
		} while (Users3 != 0);  //control statement
		return 0;
	}
	//function to manage the file
	double File_Report()
	{
		ofstream KayodeFile ("Project2.txt");
		if (KayodeFile.is_open())
		{
			//UserSerlection();
			//int Display_Inventry()
			//{
			do // control statement
				//the KayodeFile is like cin, it takes everything that has been done on the program, and display it on the txt file I have created.
			{
				cout << "\n\t\t\t           ========================================\n";
				KayodeFile << "\n\t\t\t           ========================================\n";
				cout << "\t\t\t\tEEGR 161 SHOPPING COMPLEX, BALTIMORE MD 21251\n\n";
				KayodeFile << "\t\t\t\tEEGR 161 SHOPPING COMPLEX, BALTIMORE MD 21251\n\n";
				cout << "\t\t Good day. Welcome to the store attending Machine at EEGR 161 Shopping Complex." << "\n";
				KayodeFile << "\t\t Good day. Welcome to the store attending Machine at EEGR 161 Shopping Complex." << "\n";
				cout << "\t\t\t My name is OluwakayodeBot, and I will be assisting you to check out." << "\n";
				KayodeFile << "\t\t\t My name is OluwakayodeBot, and I will be assisting you to check out." << "\n";
				cout << "\t\t\t\t I am sure you had an awesome time shopping here.\n";
				KayodeFile << "\t\t\t\t I am sure you had an awesome time shopping here.\n";
				cout << "\n";
				KayodeFile << "\n";
				cout << "Select a value for what you want to do:" << "\n";
				KayodeFile << "Select a value for what you want to do:" << "\n";
				cout << "Enter 1 for Inventory| 2 for Point of Sale| 3 for Report.\n";
				KayodeFile << "Enter 1 for Inventory| 2 for Point of Sale| 3 for Report.\n";
				cout << "Enter Selection:";
				KayodeFile << "Enter Selection:";
				cin >> Users;
				KayodeFile << Users;
				if (Users == 1)
				{
					cout << "|ID |Food Items |Prices ";
					KayodeFile << "|ID |Food Items |Prices ";
					cout << "\n";
					KayodeFile << "\n";
					for (int i = 0; i < 16; i++)
					{
						cout << "|" << i + 1 << " |" << FoodBasket[i] << " |" << "$" << Prices[i] << " |\n";
						KayodeFile << "|" << i + 1 << " |" << FoodBasket[i] << " |" << "$" << Prices[i] << " |\n";
					}
					cout << "\n";
					KayodeFile << "\n";
					cout << "\n";
					KayodeFile << "\n";
				}
				else if (Users == 2)
				{
					do
					{
						cout << "What do want to buy?\n";
						KayodeFile << "What do want to buy?\n";
						cout << "Enter Food Item ID\n";
						KayodeFile << "Enter Food Item ID\n";
						cout << "Choice: ";
						KayodeFile << "Choice: ";
						cin >> Choice;
						KayodeFile << Choice;
						if (Choice >= 1 && Choice < 17)
						{
							Choice = Choice - 1;
							cout << "\n";
							KayodeFile << "\n";
							cout << "Enter the Quantity of the item you want\n";
							KayodeFile << "Enter the Quantity of the item you want\n";
							cout << "Enter Quantity: ";
							KayodeFile << "Enter Quantity: ";
							cin >> Quant;
							KayodeFile << Quant;
							if (Quant >= 1 && Quant <= Quantities[Choice])
							{
								cout << "\n";
								KayodeFile << "\n";
								cout << "Total Price for that purchase is: $" << float(Prices[Choice] * Quant);
								KayodeFile << "Total Price for that purchase is: $" << float(Prices[Choice] * Quant);
								cout << "\n";
								KayodeFile << "\n";
							}
							else
							{
								cout << "\n";
								KayodeFile << "\n";
								cout << "Error 404!\n";
								KayodeFile << "Error 404!\n";
								cout << "Re-enter your Quantity!!!\n";
								KayodeFile << "Re-enter your Quantity!!!\n";
							}
						}
						else
						{
							cout << "\n";
							KayodeFile << "\n";
							cout << "Error 404!\n";
							KayodeFile << "Error 404!\n";
							cout << "Re-enter your choice!!!\n";
							KayodeFile << "Re-enter your choice!!!\n";
						}
						cout << "Do you want to continue?\n";
						KayodeFile << "Do you want to continue?\n";
						cout << "Enter 1-Continue | 0-Exit\n";
						KayodeFile << "Enter 1-Continue | 0-Exit\n";
						cout << "Choice: ";
						KayodeFile << "Choice: ";
						cin >> Users2;
						KayodeFile << Users2;
						cout << "\n";
						KayodeFile << "\n";
					} while (Users2 != 0);
				}
				else if (Users == 3)
				{
					cout << "|ID      |Food Items         |Prices |      Quantity      |Grand Total |";
					KayodeFile << "|ID      |Food Items         |Prices |      Quantity      |Grand Total |";
					cout << "\n";
					KayodeFile << "\n";
					for (int i = 0; i < 16; i++)
					{
						cout << "|" << i + 1 << "      |" << FoodBasket[i] << " |" << "$" << Prices[i] << "    |" << Quantities[i] << "    |" << float(Prices[i] * Quantities[i]) << "|\n";
						KayodeFile << "|" << i + 1 << "      |" << FoodBasket[i] << " |" << "$" << Prices[i] << "    |" << Quantities[i] << "    |" << float(Prices[i] * Quantities[i]) << "|\n";
					}
				}
				cout << "Do you want to continue?\n";
				KayodeFile << "Do you want to continue?\n";
				cout << "Enter 1-Continue | 0-Exit\n";
				KayodeFile << "Enter 1-Continue | 0-Exit\n";
				cout << "Choice: ";
				KayodeFile << "Choice: ";
				cin >> Users3;
				KayodeFile << Users3;
				cout << "\n";
				KayodeFile << "\n";
				KayodeFile << "\n";
			} while (Users3 != 0);
				//return Price;

			// I just closed the file
			KayodeFile.close();
		}
		//if the above code does not run, print out unable to open file
		else
		{
			cout << "Unable to open file";
		}
		return 0;
	}
};
int main(int choice, int exit)
{	
	Kayodes Kayode;
	//Kayode.Greeting_Message();
	//Kayode.Selection();
	//Kayode.UserSerlection();
	Kayode.File_Report();

	//this is for the calculator
	Mycalculator Calculator;
	do
	{
		cout << "Hello What Mathematical Operation do you want to perform\n";
		cout << "Enter 1-Addition | 2=Subtraction | 3-Multiplication | 4-Diivision | 5-Power \n";
		cout << "Operation: ";
		cin >> choice;
		cout << "\n";
		if (choice == 1)
		{
			Calculator.Addition();
		}
		if (choice == 2)
		{
			Calculator.Subtraction();
		}
		if (choice == 3)
		{
			Calculator.Multiplication();
		}
		if (choice == 4)
		{
			Calculator.Division();
		}
		if (choice == 5)
		{
			Calculator.Power();
		}
		cout << "\n";
		cout << "\n";
		cout << "Do you want to continue?\n";
		cout << "Enter 1-Continue | 0-Exit\n";
		cout << "Choice: ";
		cin >> exit;
		cout << "\n";
	} while (exit != 0);

	//to make the computer stay put on the screen
	system("pause");

	//it must return a value of the same data type
	return 0;
}