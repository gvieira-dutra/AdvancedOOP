#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;

namespace sdds {

	ostream& operator<<(ostream& os, const Book& src)
	{
		os << fixed << right << setw(20) << src.m_author << " | ";
		os << fixed << right << setw(22)  << src.m_title << " | ";
		os << fixed << right << setw(5) << src.m_country << " | ";
		os << setw(4) << src.m_year << " | ";
		os << fixed << right << setw(6) << setprecision(2) << src.m_price << " | ";
		os << src.m_description << endl;

		return os;
	}


	const string& Book::title() const
	{
		return m_title;
	}
	
	const string& Book::country() const
	{
		return m_country;
	}
	
	const size_t& Book::year() const
	{
		return m_year;
	}
	
	double& Book::price()
	{
		return m_price;
	}
	
	Book::Book(const string& strBook)
	{

		string bookInfo = strBook, temp;
		int num{};

		num = bookInfo.find(',');

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		trimStr(temp);

		m_author = temp;

		num = bookInfo.find(',');

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		trimStr(temp);

		m_title = temp;

		num = bookInfo.find(',');

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		trimStr(temp);

		m_country = temp;

		num = bookInfo.find(',');

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		m_price = stod(temp);

		num = bookInfo.find(',');

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		m_year = stoi(temp);

		num = bookInfo.find('\n'); //at this stage can I Maybe only send the bookInfo straight to the trim function??????????????????????????????????????????????????????????????????????????????????????

		temp = bookInfo.substr(0, num);

		bookInfo.erase(0, ++num);

		trimStr(temp);

		m_description = temp;

	}

	void Book::trimStr(string& src)
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
