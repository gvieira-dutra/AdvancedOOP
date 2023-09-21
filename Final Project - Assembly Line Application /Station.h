// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
#include <string>

namespace sdds {
	class Station {
		int m_id{};
		std::string m_name{};
		std::string m_descrip{};
		size_t m_serialNumber{};
		size_t m_inStock{};
		static size_t m_widthField;
		static size_t id_generator;

	public:
		//Empty body default constructor
		Station() {};

		//Custom 1 argument Constructor
		Station(const std::string);

		//Returns obj name
		const std::string& getItemName() const;

		//Returns next serial number
		size_t getNextSerialNumber();

		//Returns qty of items in stock
		size_t getQuantity() const;

		//Subtracts 1 from quantity
		void updateQuantity();

		//Inserts current obj to os
		void display(std::ostream& os, bool full) const;
	};
}