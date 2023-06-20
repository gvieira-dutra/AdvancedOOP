/******************************************************************************
					Workshop - #4
Full Name  : Gleison Vieira Dutra
Student ID#: 129237220
Email      : gvieira-dutra@myseneca.
Date       : June 6, 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#pragma once
#include <iostream>
#include <string>

namespace sdds {

	class Reservation {
		std::string m_reservationID{};
		std::string m_name{};
		std::string m_email{};
		size_t m_numPeople{}; 
		size_t m_day{}; 
		size_t m_time{}; 

	public:

		Reservation() {};

		void update(int day, int time);

		Reservation(const std::string& res);

		friend std::ostream& operator<<(std::ostream&, const Reservation);
	
		void trimStr(std::string& src);
	};
 
}