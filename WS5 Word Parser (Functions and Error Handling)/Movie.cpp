#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Movie.h"

using namespace std;

namespace sdds {
	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		string movieStr = strMovie, temp;
		int num{};
		

		num = movieStr.find(',');

		temp = movieStr.substr(0, num);

		movieStr.erase(0, ++num);
		
		trimStr(temp);

		m_title = temp;

		num = movieStr.find(',');

		temp = movieStr.substr(0, num);

		movieStr.erase(0, ++num);

		m_year = stoi(temp);

		num = movieStr.find('\n');

		temp = movieStr.substr(0, num);

		movieStr.erase(0, ++num);

		trimStr(temp);
		 
		m_description = temp;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& src)
	{
		os << fixed << right << setw(40) << src.m_title << " | ";
		os << fixed << right << setw(4) << src.m_year << " | ";
		os << src.m_description << endl;

		return os;
	}

	void Movie::trimStr(string& src)
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

}