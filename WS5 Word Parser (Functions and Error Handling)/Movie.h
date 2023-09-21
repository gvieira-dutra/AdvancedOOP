#pragma once
#include <string>
namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
	public:
		Movie() {};

		const std::string& title() const;
		
		Movie(const std::string& strMovie);
		void trimStr(std::string&);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}