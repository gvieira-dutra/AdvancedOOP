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

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds
{

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
        this->operator=(src);
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] m_conf;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
        
        if (this != &src) {
           
            csSize = src.csSize;
            
            delete[] m_conf;

            m_conf = new const Reservation * [csSize];
            for (size_t i = 0; i < csSize; i++) {
                m_conf[i] = src.m_conf[i];
            }
        }
      
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
    {
        *this = std::move(src);
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept
    {
        if (this != &src) {
          
            csSize = src.csSize;
            delete[] m_conf;

            m_conf = src.m_conf;
            src.csSize = 0;
            src.m_conf = nullptr;
       
        }
       
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& resa)
    {
        if (search(resa) < 0) {

            const Reservation** temp{};
            
            temp = new const Reservation * [++csSize];
            
            for (size_t i = 0 ; i < csSize - 1; i++) {
                temp[i] = m_conf[i];
                m_conf[i] = nullptr;
            }
          
            temp[csSize - 1] = &resa;

            delete[] m_conf;
            m_conf = temp;

            
        }
   
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& resa)
    {
        int idx = search(resa);
   
        if (idx >= 0) {
 
            m_conf[idx] = nullptr;
            
            for (size_t i = idx + 1; i < csSize; i++) {
                m_conf[i - 1] = m_conf[i];
            }
       
            const Reservation** temp{ nullptr };

            temp = new const Reservation * [--csSize];

            for (size_t i = 0; i < csSize; i++) {
                temp[i] = m_conf[i];
                m_conf[i] = nullptr;
            }
   
            delete[]m_conf;
            m_conf = temp;
        }
   
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res)
    {

        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (!res.csSize) {
            os << "There are no confirmations to send!" << std::endl;
        }
        else {
            for (size_t i = 0; i < res.csSize; i++) {
                os << *res.m_conf[i];
            }
        }
        os << "--------------------------" << std::endl;
        return os;
    }
 
    int ConfirmationSender::search(const Reservation& resa) const
    {
        int idx { -1 };

        if (csSize) {

            for (size_t i = 0 ; i < csSize; i++) {
                if (m_conf[i] == &resa) {
                    idx = i;
                    i = csSize;
                }
            }
        }

        return idx;
    }

}


