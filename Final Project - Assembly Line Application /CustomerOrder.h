// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <string>
#include "Station.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};
		static size_t m_widthField;

	public:

		//Default constructor
		CustomerOrder() {};

		//One argument constructor
		CustomerOrder(const std::string&);

		//Deleting copy assignment operator
		CustomerOrder& operator=(const CustomerOrder&) = delete;

		//Copy Constructor should throw an exception if called
		CustomerOrder(CustomerOrder&) { throw "Should not be called"; };

		//Move Constructor
		CustomerOrder(CustomerOrder&&) noexcept;

		//Move Assignment Operator
		CustomerOrder& operator=(CustomerOrder&&) noexcept;

		//Destructor
		~CustomerOrder();

		//returns true if all the items in the order have been filled; false otherwise
		bool isOrderFilled() const;

		//returns true if all items specified by itemName have been filled.
		//If the item doesn't exist in the order, this query returns true
		bool isItemFilled(const std::string&) const;

		//this query displays the state of the current object in the format(see the sample output for details)
		void display(std::ostream&) const;

		//fills one item in the current order that the Station specified in the first parameter handles.
		void fillItem(Station& station, std::ostream& os);
	};

	//
}
