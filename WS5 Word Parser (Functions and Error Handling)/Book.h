#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "SpellChecker.h"

namespace sdds {

	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_description{};

	public:

		Book() {};

		const std::string& title() const;

		const std::string& country() const;

		const size_t& year() const;

		double& price();

		Book(const std::string& strBook);

		void trimStr(std::string&);

		friend std::ostream& operator<<(std::ostream&, const Book&);

		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}
	};
}
