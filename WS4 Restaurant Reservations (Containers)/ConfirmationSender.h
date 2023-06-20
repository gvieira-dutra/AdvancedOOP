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

#pragma once
#include "Reservation.h"
namespace sdds {

	class ConfirmationSender {

		const Reservation** m_conf{};
		size_t csSize{};

	public:

		ConfirmationSender() {};
		ConfirmationSender(const ConfirmationSender&);
		~ConfirmationSender();
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& res);
		int search(const Reservation& res) const;

	};
}
