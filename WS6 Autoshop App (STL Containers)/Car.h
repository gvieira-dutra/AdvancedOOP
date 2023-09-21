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
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed{};
		 
	public:

		//Default empty constructor.
		Car() {};

		//Constructor to read information from file.
		Car(std::istream&);

		//Will return car's condition.
		std::string condition() const;

		//Will return car's top speed.
		double topSpeed() const;

		//Insert to output stream car's obj content;
		void display(std::ostream&) const;

		//Remove empty spaces from string
		void trimStr(std::string&);

	};
}