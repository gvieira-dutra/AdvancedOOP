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

namespace sdds {
	class Timer {
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;
	public:
		void start(); //Will starts timer and store value in an attribute.
		long long stop(); //Will stop timer, calculate and return the difference. 
	};
}