/******************************************************************************
					Workshop - #6
Full Name  : Gleison Vieira Dutra
Student ID#: 129237220
Email      : gvieira-dutra@myseneca.
Date       : July 9, 2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/
#include "Car.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
	//Constructor to read information from file.
	Car::Car(std::istream& is)
	{
		std::string temp{};
		char type{};
		std::string errMsg = "Invalid record!";


		std::getline(is, temp, ',');
		type = temp[0];

		std::getline(is, m_maker, ',');
		trimStr(m_maker);

		std::getline(is, m_condition, ',');
		trimStr(m_condition);

		if (m_condition[0] == 'n' || m_condition[0] == ' ' || m_condition.empty())
			m_condition = "new";
		else if (m_condition[0] == 'b')
			m_condition = "broken";
		else if (m_condition[0] == 'u')
			m_condition = "used";
		else
		{
			std::getline(is, temp, '\n');
			throw errMsg;
		}

		if (type == 'c' || type == 'C')
		{
			std::getline(is, temp, '\n');
			m_topSpeed = stoi(temp);
		}
		else
		{
			std::getline(is, temp, ',');
			trimStr(temp);
			bool flag = false;
			for (size_t i = 0; i < temp.length(); i++)
			{
				if (!isdigit(temp[i]))
					flag = true;
			}

			if (flag)
			{
				std::getline(is, temp, '\n');
				throw errMsg;
			}
			else {
				m_topSpeed = stoi(temp);
			}
		}
	}

	//Will return car's condition.
	std::string Car::condition() const
	{
		return m_condition;
	}

	//Will return car's top speed.
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	//Insert to output stream car's obj content;
	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out << fixed << right << setw(10) << m_maker;
		out << " | ";
		out << fixed << left << setw(6) << condition();
		out << " | ";
		out << fixed << setprecision(2) << topSpeed();
		out << " |";
	}

	void Car::trimStr(string& src)
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