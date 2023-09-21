// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iomanip>
#include <iostream>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	size_t Station::id_generator = {};
	size_t Station::m_widthField = {};

	//Custom 1 argument Constructor
	Station::Station(const std::string src)
	{
		Utilities emptyObj{};
		size_t startAt{};
		bool keepSearch{ true };

		m_id = (++id_generator);

		m_name = emptyObj.extractToken(src, startAt, keepSearch);
		emptyObj.trimStr(m_name);

		m_serialNumber = stoi(emptyObj.extractToken(src, startAt, keepSearch));

		m_inStock = stoi(emptyObj.extractToken(src, startAt, keepSearch));

		if (m_widthField < m_name.length())
			m_widthField = m_name.length();

		m_descrip = emptyObj.extractToken(src, startAt, keepSearch);
		emptyObj.trimStr(m_descrip);
	}

	//Returns obj name
	const std::string& Station::getItemName() const { return m_name; }

	//Returns next serial number
	size_t Station::getNextSerialNumber() { return m_serialNumber++; }

	//Returns qty of items in stock
	size_t Station::getQuantity() const
	{
		return m_inStock;
	}

	//Subtracts 1 from quantity
	void Station::updateQuantity()
	{
		if (m_inStock > 0)
			m_inStock--;
	}

	//Inserts current obj to os
	void Station::display(std::ostream& os, bool full) const
	{
		if (m_id < 9)
			os << "00";
		else if (m_id > 9 && m_id < 100)
			os << "0";

		if (full)
		{
			os << m_id << " | ";
			os << std::fixed << std::left << std::setfill(' ') << std::setw(m_widthField) << m_name << " | ";

			os << std::fixed << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << " | ";

			os << std::fixed << std::right << std::setfill(' ') << std::setw(4) << m_inStock << " | ";
			os << m_descrip << std::endl;
		}
		else
		{
			os << m_id << " | ";
			os << std::fixed << std::left << std::setfill(' ') << std::setw(m_widthField) << m_name << " | ";
			os << std::fixed << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << " | " << std::endl;
		}
	}
}