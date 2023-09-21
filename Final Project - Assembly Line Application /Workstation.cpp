// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds {
	deque<CustomerOrder> g_pending{}, g_completed{}, g_incomplete{};

	Workstation::Workstation(const std::string& src) : Station(src) {}

	void Workstation::fill(std::ostream& os)
	{
		//string name = (*((sdds::Station*)this)).m_name;
		//for (size_t i = 0; i < m_orders.size(); i++)
		if (!m_orders.empty())
		{
			m_orders[0].fillItem((*((sdds::Station*)this)), os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool isMoved = false;

		if (m_orders.size() > 0)
		{
			bool thisFilled = (this->m_orders)[0].isItemFilled((*((sdds::Station*)this)).getItemName());

			if (thisFilled || (*((sdds::Station*)this)).getQuantity() <= 0)
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders[0]);
					m_orders.pop_front();
				}
				else
				{
					if (m_orders[0].isOrderFilled())
					{
						g_completed.push_back(std::move(m_orders[0]));
						m_orders.pop_front();
					}
					else
					{
						g_incomplete.push_back(std::move(m_orders[0]));
						m_orders.pop_front();
					}
				}
				isMoved = true;
			}
		}

		return isMoved;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		if (station != nullptr)
		{
			m_pNextStation = station;
		}
		else
			m_pNextStation = nullptr;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		//m_orders.push_back(newOrder);
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}