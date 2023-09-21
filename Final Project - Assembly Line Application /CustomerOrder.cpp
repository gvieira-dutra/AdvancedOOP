// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const string& src)
	{
		Utilities emptyObj{};
		size_t startAt{};
		bool keepSearch = true;
		string temp{};
		size_t itemCtn{};

		m_name = emptyObj.extractToken(src, startAt, keepSearch);
		emptyObj.trimStr(m_name);

		m_product = emptyObj.extractToken(src, startAt, keepSearch);
		emptyObj.trimStr(m_product);

		itemCtn = emptyObj.itemsCounter(src);

		m_lstItem = new Item * [itemCtn];

		while (keepSearch)
		{
			temp = emptyObj.extractToken(src, startAt, keepSearch);
			emptyObj.trimStr(temp);

			m_lstItem[m_cntItem] = new Item(temp);
			m_cntItem++;
		}

		if (m_widthField < emptyObj.getFieldWidth())
			m_widthField = emptyObj.getFieldWidth();
	};

	//Move Constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			while (m_cntItem)
			{
				delete m_lstItem[--m_cntItem];
			}
			delete[] m_lstItem;

			m_lstItem = src.m_lstItem;
			src.m_lstItem = nullptr;
			m_cntItem = src.m_cntItem;
			src.m_cntItem = 0;
			m_product = src.m_product;
			//src.m_product = nullptr;
			m_name = src.m_name;
			//	m_name = nullptr;
			m_widthField = src.m_widthField;
		}

		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool flag = true;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled == false)
			{
				flag = false;
			}
		}
		return flag;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool flag = true;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
			{
				//cout << m_lstItem[i]->m_itemName << " " << m_lstItem[i]->m_isFilled << endl;
				flag = false;
			}
		}
		return flag;
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[";

			if ((*this->m_lstItem[i]).m_serialNumber == 0)
			{
				os << setw(6) << setfill('0') << (*this->m_lstItem[i]).m_serialNumber;
			}
			else
			{
				os << right << setw(6) << setfill('0') << (*this->m_lstItem[i]).m_serialNumber;
				// os << std::fixed << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << " | ";
			}

			os << "] ";

			os << left << setw(m_widthField) << setfill(' ') << (*this->m_lstItem[i]).m_itemName;

			if ((*this->m_lstItem[i]).m_isFilled == false)
			{
				os << " - TO BE FILLED";
			}
			else
			{
				os << " - FILLED";
			}

			os << endl;
		}
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < this->m_cntItem; i++)
		{
			if (station.getItemName() == (*this->m_lstItem[i]).m_itemName && station.getQuantity() > 0 && (*this->m_lstItem[i]).m_isFilled == false)
			{
				(*this->m_lstItem[i]).m_isFilled = true;
				station.updateQuantity();
				(*this->m_lstItem[i]).m_serialNumber = station.getNextSerialNumber();

				os << "    Filled " << this->m_name << ", " << this->m_product;
				os << " [" << station.getItemName() << ']' << endl;

				i = this->m_cntItem;
			}
		}

		for (size_t i = 0; i < this->m_cntItem; i++)
		{
			if (station.getItemName() == (*this->m_lstItem[i]).m_itemName && station.getQuantity() <= 0 && (*this->m_lstItem[i]).m_isFilled == false)
			{
				(*this->m_lstItem[i]).m_isFilled = false;

				os << "    Unable to fill " << this->m_name << ", " << this->m_product;
				os << " [" << station.getItemName() << ']' << endl;
			}
		}
	}
}