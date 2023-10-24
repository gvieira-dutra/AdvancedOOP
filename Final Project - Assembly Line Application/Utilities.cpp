// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"
#include <iostream>
using namespace std;

namespace sdds {
	char Utilities::m_delimiter = '\0';

	//Will set the width of the current obj based on received value
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	//Return field width
	size_t Utilities::getFieldWidth() const { return m_widthField; }

	//Extracts token from str
	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		std::string token;
		size_t idx{};

		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw "Error, next_pos is same as delimiter";
		}
		idx = str.find(m_delimiter, next_pos);

		token = str.substr(next_pos, idx - next_pos);
		trimStr(token);
		if (m_widthField < token.length())
		{
			setFieldWidth(token.length());
		}
		if (idx >= str.length())
			more = false;
		else
			next_pos = ++idx;

		return token;
	}

	//Sets the delimiter for given class
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	//Returns delimiter for given class
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

	//Removes white space from string
	void Utilities::trimStr(std::string& src)
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

	size_t Utilities::itemsCounter(const std::string& src)
	{
		size_t num{};
		char delim = getDelimiter();

		for (size_t i = 0; i < src.length(); i++)
		{
			if (src[i] == delim)
			{
				num++;
			}
		}
		return num - 1;
	}
}