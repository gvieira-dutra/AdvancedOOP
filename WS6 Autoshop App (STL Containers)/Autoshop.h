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
#include <vector> 
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop 
	{
		std::vector<Vehicle*> m_vehicles;

	public:

		//Add the parameter received to m_vehicles.
		Autoshop& operator +=(Vehicle*);

		//Iterate over m_vehicles and print them out
		void display(std::ostream&) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (Vehicle* myVehicle : this->m_vehicles)
				if (test(myVehicle))
					vehicles.push_back(myVehicle);
		}

		//Destructor
		~Autoshop();


	};
}