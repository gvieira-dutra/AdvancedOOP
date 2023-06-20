/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                     */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Dictionary.h"
using namespace std;

namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Dictionary& dict)
	{
		return dict.display(os);
	}

	bool Dictionary::operator==(const Dictionary& src)
	{
		return (!strcmp(src.m_term.c_str(), m_term.c_str()));
	}
	std::ostream& Dictionary::display(std::ostream& os) const
	{
		std::cout << std::fixed << std::right << std::setw(20) << getTerm() << ": "
			<< getDefinition();
		return os;
	}
}