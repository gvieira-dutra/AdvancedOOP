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
#include "Vehicle.h"

namespace sdds {

		//This function will dynamically create an instance of Car
		Vehicle* createInstance(std::istream& in);	
}