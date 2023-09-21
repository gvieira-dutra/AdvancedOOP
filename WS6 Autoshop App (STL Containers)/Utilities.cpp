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
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {

    //This function will dynamically create an instance of Car
    Vehicle* createInstance(std::istream& in)
    {
        std::string temp{};
        Car* myCar{};

        if (in.peek() == EOF)
        {
            return nullptr;
        }
        
        while (in.peek() == ' ')
            in.ignore();

        if(in.peek() == 'c' || in.peek() == 'C')
        {
            myCar = new Car(in);
        }
        else if (in.peek() == 'r' || in.peek() == 'R')
        {
            myCar = new Racecar(in);
        }
        else
        {
            std::string ret = "Unrecognized record type: [";
            std::getline(in, temp, '\n');
            temp = ret + temp[0] + ']';
            throw temp;
        }
       
        return myCar;
    }

}