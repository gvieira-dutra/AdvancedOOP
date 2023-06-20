/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by 05/20/2023                            */
/* I have done all the coding by myself and only      */  
/* copied the code that my professor provided to      */    
/* complete my workshops and assignments.             */
/******************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "carads.h"
using namespace std;

double g_taxrate = 0;
double g_discount = 0;


namespace sdds {

	Cars::Cars(const char* r_brand) {

		if(r_brand != nullptr && r_brand[0] != '\0')
		{
			if (brand)
			{
				delete[] brand;
				brand = nullptr;
			}

			brand = new char[strlen(r_brand) + 1];
			strcpy(brand, r_brand);
		}
	}

	Cars::Cars(const Cars& right) {
		
		if (right.brand != nullptr )
		{
			brand = new char[strlen(right.brand) + 1];
			strcpy(brand, right.brand);

			strcpy(model, right.model);
			year = right.year;
			 price = right.price;
			status = right.status;
			isPromotion = right.isPromotion;
		}
		else
			brand = nullptr;
	}

	Cars& Cars::operator=(const Cars& myCar)
	{
		if (this != &myCar)
		{

			if (brand)
			{
				delete[] brand;
				brand = nullptr;
			}

			if (myCar.brand != nullptr)
			{
				brand = new char[strlen(myCar.brand) + 1];
				strcpy(brand, myCar.brand);

				strcpy(model, myCar.model);
				year = myCar.year;
				price = myCar.price;
				status = myCar.status;
				isPromotion = myCar.isPromotion;
			}
		}
		
		return *this;
	}

	Cars::~Cars() {
		delete[] brand;
		brand = nullptr;
	}

	void listArgs(int argc, char* argv[])
	{
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;

		for (int i = 0; i < argc; i++)
		{
			cout << "  " << i + 1 << ": ";
			cout << argv[i] << endl;
		}

		cout << "--------------------------" << endl << endl;
	}

	void Cars::read(istream& is)
	{
		if (is)
		{
			string l_brand{};
			
			is >> status;
			is.ignore();
			getline(is, l_brand, ',');

			if (l_brand[0] != '\0')
			{
				if (brand)
				{
					delete[] brand;
					brand = nullptr;
				}

				brand = new char[l_brand.length() + 1];
				strcpy(brand, l_brand.c_str());
			}


			is.getline(model, 15, ',');
			
			is >> year;
			is.ignore();
			is >> price;
			is.ignore();
			
			char promo;
			is >> promo;
			is.ignore();
		
			if (promo == 'Y')
			{
				isPromotion = true;
			}
			else
				isPromotion = false;

		}
	}

	void Cars::display(bool reset)
	{
		static int COUNTER = 0;
		if (reset == true)
			COUNTER = 0;

		if (brand != nullptr && brand[0] != '\0')
		{
			COUNTER++;
			cout << left << setw(2) << COUNTER << ". ";
			cout << left << setw(10) << brand;
			cout << "| ";
			cout << left << setw(15) << model;
			cout << "| " << year << " |";
			cout << setw(12) << right << fixed << setprecision(2) << price + (price * g_taxrate) << "|";

			if (isPromotion == true)
			{
				cout << setw(12) << right << fixed << setprecision(2) << (price + (price * g_taxrate)) - ((price + (price * g_taxrate)) * g_discount);
			}
			cout << endl;

		}
		else
			cout << "COUNTER. No Car";
	}

	char Cars::getStatus() 
	{

		return status;
	}

	Cars::operator bool() const {

		return (year >= 2021 ? true : false);
	}

	istream& operator>>(istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2) 
	{
		car2 = car1;
	}

}
