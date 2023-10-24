// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#include <deque>
#include <vector>
#include <string>
#include "CustomerOrder.h"

namespace sdds {
	extern std::deque<CustomerOrder> g_pending, g_completed, g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder>m_orders{};
		Workstation* m_pNextStation{};

	public:

		//Deleting copy assignment operator
		Workstation& operator=(const Workstation&) = delete;

		//Deleting move Assignment Operator
		Workstation& operator=(Workstation&&) = delete;

		//Empty body default constructor
		Workstation() {};

		//1 arg constructor
		Workstation(const std::string&);

		// fills the order at the front of the queue if there are CustomerOrders in the queue; otherwise, does nothing.
		void fill(std::ostream&);

		//attempts to move the order order at the front of the queue to the next station in the assembly line:
		bool attemptToMoveOrder();

		// stores the address of the referenced Workstation object in the pointer to the m_pNextStation. Parameter defaults to nullptr.
		void setNextStation(Workstation* station);

		// query returns the address of next Workstation
		Workstation* getNextStation() const;

		// inserts the name of the Item for which the current object is responsible into stream os
		void display(std::ostream& os) const;

		//moves the CustomerOrder referenced in parameter newOrder to the back of the queue.
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
