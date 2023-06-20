/******************************************************/
/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by 05/27/2023                            */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/

#include "TennisLog.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

namespace sdds {
	//Will print a TennisMatch object on the screen
	void TennisMatch::display() const
	{
		if (!tournamentID.empty())
		{
			cout << fixed << right << setw(20) << setfill('.') << "Tourney ID" << " : ";
			cout << fixed << left << setw(30) << setfill('.') << tournamentID << endl;
			cout << fixed << right << setw(20) << setfill('.') << "Match ID" << " : ";
			cout << fixed << left << setw(30) << setfill('.') << matchID << endl;
			cout << fixed << right << setw(20) << setfill('.') << "Tourney" << " : ";
			cout << fixed << left << setw(30) << setfill('.') << tournamentName << endl;
			cout << fixed << right << setw(20) << setfill('.') << "Winner" << " : ";
			cout << fixed << left << setw(30) << setfill('.') << winner << endl;
			cout << fixed << right << setw(20) << setfill('.') << "Loser" << " : ";
			cout << fixed << left << setw(30) << setfill('.') << loser << endl;
		}
		else
		{
			cout << "Empty Match";
		}
	}

	//One argument Constructor
	TennisLog::TennisLog(char* fname)
	{
		ifstream in(fname);
		string line;

		if (!in.is_open())
		{
			cout << "Problems reading file";
		}
		else
		{
			while (getline(in, line))
			{
				counter++;
			}
		}

		allMatches = new TennisMatch[--counter];

		in.clear();
		in.seekg(0);
		getline(in, line, '\n');
		for (size_t i = 0; i < counter; i++)
		{
			getline(in, allMatches[i].tournamentID, ',');
			getline(in, allMatches[i].tournamentName, ',');
			in >> allMatches[i].matchID;
			in.ignore();
			getline(in, allMatches[i].winner, ',');
			getline(in, allMatches[i].loser, '\n');
		}
		in.close();
	}

	//Copy Constructor
	TennisLog::TennisLog(const TennisLog& src)
	{
		*this = src;
	}
	
	//Copy assignment operator
	TennisLog& TennisLog::operator=(const TennisLog& src)
	{
		if (this != &src)
		{
			delete[] allMatches;
			allMatches = nullptr;

			if (src.allMatches != nullptr)
			{
				allMatches = new TennisMatch[src.counter];

				for (size_t i = 0; i < src.counter; i++)
				{
					allMatches[i] = src.allMatches[i];
				}

				counter = src.counter;
			}
		}

		return *this;
	}

	//Destructor
	TennisLog::~TennisLog() {
		delete[] allMatches;
	}

	//Move Constructor 
	TennisLog::TennisLog(TennisLog&& src) noexcept 
	{
		*this = std::move(src);
	}

	//Move assignment operator
	TennisLog& TennisLog::operator=(TennisLog&& src)  noexcept
	{
		if (this != &src)
		{
			delete[] allMatches;
			allMatches = nullptr;

			allMatches = src.allMatches;
			src.allMatches = nullptr;
			counter = src.counter;
			src.counter = 0;
		}
		return *this;
	}

	//Will add a match to the current object
	void TennisLog::addMatch(TennisMatch& match)
	{
		TennisMatch* temp = new TennisMatch[counter + 1];

		for (size_t i = 0; i < counter; i++)
		{
			temp[i] = allMatches[i];
		}

		delete[] allMatches;

		allMatches = temp;  // Assign the temporary array to the original pointer

		allMatches[counter++] = match;
				
	}

	//Find all Matches based on player name
	TennisLog TennisLog::findMatches(string name) const
	{
		size_t lCounter{};
		TennisLog myObj{};
		int ctr[2000]{};
		int j{};

		for (size_t i = 0; i < counter; i++)
		{
			if (name == allMatches[i].loser || name == allMatches[i].winner)
			{
				ctr[j++] = i;
				lCounter++;
			}
		}

		if (lCounter > 0)
		{
			

			myObj.allMatches = new TennisMatch[lCounter];

			for (size_t i = 0; i < lCounter; i++)
			{
				myObj.addMatch(allMatches[ctr[i]]);
			}

			myObj.counter = lCounter;
		}

		return myObj;
	}

	//Returns a specific match or an empty obj
	TennisMatch TennisLog::operator[](size_t idx) const
	{
		TennisMatch empty{};

		return (counter == 0 ? empty : allMatches[idx]); 
	}

	//Returns length of current array
	TennisLog::operator size_t() const
	{
		return counter;
	}

	//Will call display() to print obj on screen 
	ostream& operator<<(ostream& os, const TennisMatch& game)
	{
		game.display();
		return os;
	}

}