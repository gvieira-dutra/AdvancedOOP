/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by 05/20/2023                            */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/
#pragma once
#ifndef CARADS_H
#define CARADS_H
#include <string>


	extern double g_taxrate;
	extern double g_discount;

namespace sdds {
	
	void listArgs(int argc, char* argv[]);

	class Cars {
		char* brand {};
		char model[15] {};
		unsigned short int year {};
		double price {};
		char status {};
		bool isPromotion {};


	public:
		Cars() {};
		Cars(const char* brand);
		Cars(const Cars& right);
		Cars& operator=(const Cars& myCar);
		~Cars();
		void read(std::istream& is);
		void display(bool reset) const;
		char getStatus() const;
		operator bool() const;
	};

	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);

}

#endif