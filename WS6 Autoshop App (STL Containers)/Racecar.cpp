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
#include <iostream>
#include "Racecar.h"


namespace sdds {

    //One arg constructor
    Racecar::Racecar(std::istream& in) :Car(in)
    {
        std::string temp;
        std::getline(in, temp, '\n');
        m_booster = stod(temp);
    }

    //Prints out racecar info
    void Racecar::display(std::ostream& out) const
    {
        Car::display(out);
        out << '*' ;
    }

    //Return Racecar top speed
    double Racecar::topSpeed() const
    {
        return (m_booster > 0 ? Car::topSpeed() + (Car::topSpeed() * m_booster ) : Car::topSpeed());
    }

}