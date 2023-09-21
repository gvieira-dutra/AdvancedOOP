#pragma once
#include <string>
#include <iostream>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		inline static int m_counter[6]{};

	public:
		SpellChecker() {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
		void trimStr(std::string&);

	};
}