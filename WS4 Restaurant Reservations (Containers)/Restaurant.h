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
#include "Reservation.h"

namespace sdds {

	class Restaurant {

		Reservation** m_resa{};
		size_t resCtn{};
	public:

		Restaurant() {}; 
		Restaurant(const Restaurant&);
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		Restaurant& operator=(const Restaurant&);
		Restaurant (Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		 
		size_t size() const;

		friend std::ostream& operator<<(std::ostream&, const Restaurant);

	};	
}