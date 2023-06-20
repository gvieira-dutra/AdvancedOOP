/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by 05/27/2023                            */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/

#pragma once
#include <string>

namespace sdds {
	struct TennisMatch {
		std::string tournamentID{};
		std::string tournamentName{};
		size_t matchID{};
		std::string winner{};
		std::string loser{};

		void display() const; //Will print a TennisMatch object on the screen
	};

	class TennisLog {
		TennisMatch* allMatches{};
		size_t counter{};
	public:

		TennisLog() {}; //Default constructor
		TennisLog(char* fname); //One argument Constructor
		TennisLog(const TennisLog& src); //Copy Constructor
		TennisLog& operator=(const TennisLog& src); //Copy assignment operator
		~TennisLog(); //Destructor
		TennisLog(TennisLog&& src) noexcept; //Move Constructor
		TennisLog& operator=(TennisLog&& src) noexcept; //Move assignment operator
		void addMatch(TennisMatch& match); //Will add a match to the current object
		TennisLog findMatches(std::string name) const; //Find all Matches based on player name

		TennisMatch operator[](size_t) const; //Returns a specific match or an empty obj

		operator size_t() const; //Returns length of current array
	};
	std::ostream& operator<<(std::ostream& os, const TennisMatch& game); //Will call display() to print obj on screen 
}