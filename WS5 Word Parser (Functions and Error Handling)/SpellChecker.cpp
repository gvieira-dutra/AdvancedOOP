#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);

		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			string temp{};
			int num{}, ctn{};

			while (!file.eof()) {
				getline(file, temp);

				if (temp.length() > 3)
				{
					num = temp.find(' ');

					m_badWords[ctn] = temp.substr(0, num);

					temp.erase(0, ++num);

					trimStr(temp);

					m_goodWords[ctn] = temp;
					ctn++;
				}
			}
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		size_t found = 0;
		for (int i = 0; i < 6; i++) {
			do {
				found = text.find(m_badWords[i]);
				if (found != std::string::npos) {
					text.replace(found, m_badWords[i].length(), m_goodWords[i]);
					m_counter[i]++;
				}
			} while (found != std::string::npos);
		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		cout << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << fixed << right << setw(15) << m_badWords[i]  <<": ";
			out << m_counter[i] << ' ' << "replacements" << endl;
		}
	}

	void SpellChecker::trimStr(string& src)
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