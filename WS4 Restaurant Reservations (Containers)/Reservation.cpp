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

#include "Reservation.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <vector>

using namespace std;

namespace sdds {

    void sdds::Reservation::update(int day, int time)
    {
	    m_day = day;
	    m_time = time;
    }

    Reservation::Reservation(const string& res)
    {
       
            string myString = res;
            int n;
            string temp;

            n = myString.find(':');

            temp = myString.substr(0, n);

            trimStr(temp);

            m_reservationID = temp;

            temp = myString.erase(0, ++n);

            n = myString.find(',');

            temp = myString.substr(0, n);

            trimStr(temp);

            m_name = temp;

            temp = myString.erase(0, ++n);

            n = myString.find(',');
            temp = myString.substr(0, n);

            trimStr(temp);

            m_email = temp;

            temp = myString.erase(0, ++n);
            n = myString.find(',');

            temp = myString.substr(0, n);

            m_numPeople = stoi(temp);

            myString.erase(0, ++n);
            n = myString.find(',');
            temp = myString.substr(0, n);

            m_day = stoi(temp);

            myString.erase(0, ++n);
            n = myString.find('\n');
            temp = myString.substr(0, n);

            m_time = stoi(temp);
        
    
    }

    void Reservation::trimStr(std::string& src)
    {
        int spaceCtn{};

        for (int i = 0; i < static_cast<int>(src.length()); i++)
        {
            if (isspace(src[i]))
                spaceCtn++;

            else
                i = src.length();
        }

        src.erase(0, spaceCtn);
        spaceCtn = 0;

        for (int i = src.length() - 1; i > 0; i--)
        {
            if (isspace(src[i]))
                spaceCtn++;
            else
                i = 0;
        }

        src = src.substr(0, (src.length() - spaceCtn));

    }

    std::ostream& operator<<(std::ostream& os, const Reservation src)
    {
        os << "Reservation ";

        os << std::fixed << std::right << std::setw(10) << src.m_reservationID << ": ";
        os << std::fixed << std::right << std::setw(20) << src.m_name << "  ";
        
        string email = '<' + src.m_email + '>';

        os << std::fixed << std::left << std::setw(20) << email << "    ";
        
        if (src.m_time >= 6 && src.m_time <= 9)
        {
            os << "Breakfast ";
        }
        else if (src.m_time >= 11 && src.m_time <= 15)
        {
            os << "Lunch ";
        }
        else if (src.m_time >= 17 && src.m_time <= 21)
        {
            os << "Dinner ";
        }
        else
        {
            os << "Drinks ";
        }

        os << "on day " << src.m_day << " @ " << src.m_time << ":00" << " for " << src.m_numPeople;

        src.m_numPeople == 1 ? os << " person." : os << " people.";
        os << endl;

        return os;
    }
}