// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#include <string>

namespace sdds {
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;

	public:
		//Will set the width of the current obj based on received value
		void setFieldWidth(size_t newWidth);

		//Return field width
		size_t getFieldWidth() const;

		//Extracts token from str
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		//Sets the delimiter for given class
		static void setDelimiter(char newDelimiter);

		//Returns delimiter for given class
		static char getDelimiter();

		//Removes white space from string
		void trimStr(std::string& src);

		//Will count how many items there is on the string.
		size_t itemsCounter(const std::string&);
	};
}