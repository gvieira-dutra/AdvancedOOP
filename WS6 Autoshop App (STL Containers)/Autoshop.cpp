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
#include "Autoshop.h"
#include "Car.h"

using namespace std;

namespace sdds {

    //Add the parameter received to m_vehicles.
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);

        return *this;
    }

    //Iterate over m_vehicles and print them out
    void Autoshop::display(std::ostream& out) const
    {
       // std::vector<Vehicle*>::const_iterator iter;
        Vehicle* myVehicle{};

        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;

        for (auto iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++)
        {
            myVehicle = *iter;
           myVehicle->display(out);
           std::cout << endl;
        }
        out << "--------------------------------" << std::endl;

    }

    //Destructor
    Autoshop::~Autoshop()
    {
        for (auto vehicle : m_vehicles)
        {
            delete vehicle;
        }
    }

}