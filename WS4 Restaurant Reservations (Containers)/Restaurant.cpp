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

#include "Restaurant.h"
#include <iostream>

using namespace std;

namespace sdds {

	Restaurant::Restaurant(const Restaurant& src)
	{
		this->operator=(src);
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_resa = new Reservation * [cnt];
		for (size_t i = 0; i < cnt; i++) 
		{
			m_resa[i] = new Reservation;
			*m_resa[i] = *reservations[i];
		}
		resCtn = cnt;
	}
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < resCtn; i++)
		{
			delete m_resa[i];
		}
		
		delete[] m_resa; 
	}
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			if (src.m_resa != nullptr)
			{
				while (resCtn)
				{
					delete m_resa[--resCtn];
				}

				delete[] m_resa;
				resCtn = src.size();
				m_resa = new Reservation * [resCtn];

				for (size_t i = 0; i < resCtn; i++)
				{
					m_resa[i] = new Reservation;
					*m_resa[i] = *src.m_resa[i];
				}
			}
		}

		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src)
	{
		*this = std::move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src)
		{
			while (resCtn)
			{
				delete m_resa[--resCtn];
			}
			delete[] m_resa; 
			resCtn = src.size();
			m_resa = src.m_resa;
			src.resCtn = 0;
			src.m_resa = nullptr;
		}
		return *this;

	}
	size_t Restaurant::size() const
	{
		return resCtn;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant src)
	{
		static size_t CALL_CNT = 1;

		cout << "--------------------------" << endl;
		cout << "Fancy Restaurant (" << CALL_CNT <<  ')' << endl;
		cout << "--------------------------" << endl;
		if (src.resCtn > 0) {
			for (size_t i = 0; i < src.resCtn; i++) {
				os << *src.m_resa[i]; 
			}
		}
		else {
			os << "This restaurant is empty!" << std::endl;
		}
		cout << "--------------------------" << endl;
	
		CALL_CNT++;
		return os;
	}
}