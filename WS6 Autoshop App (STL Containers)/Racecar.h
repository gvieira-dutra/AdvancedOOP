/******************************************************************************
					Workshop - #6
Full Name  : Gleison Vieira Dutra
Student ID#: 129237220
Email      : gvieira-dutra@myseneca.
Date       : July 9, 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
#pragma once
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{};
		std::string boster{};
	public:
		//Default empty constructor
		Racecar() {};

		//One arg constructor
		Racecar(std::istream&);

		//Prints out racecar info
		void display(std::ostream&) const;

		//Return top speed
		double topSpeed() const;
	};
}