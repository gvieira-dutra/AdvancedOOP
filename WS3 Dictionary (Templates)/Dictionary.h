/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by June 4, 2023                          */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>

namespace sdds {
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
		Dictionary() {};

		//Comparison operator overload
		bool operator==(const Dictionary&);

		//Display Dictionary obj to screen
		std::ostream& display(std::ostream& os) const;
	};

	//Helper << operator overload
	std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
}
#endif