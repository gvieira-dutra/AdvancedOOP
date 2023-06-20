/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by 05/27/2023                            */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/


#include <iostream>
#include <chrono>
#include "Timer.h"
//using namespace std;

namespace sdds {

	//Will starts timer and store value in an attribute.
	void Timer::start()
	{
		
		start_time = std::chrono::steady_clock::now();
	}

	//Will stop timer, calculate and return the difference. 
	long long Timer::stop()
	{
		end_time = std::chrono::steady_clock::now();

		end_time = std::chrono::steady_clock::now();
		auto timetook = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

		long long totaltime = timetook.count();

		return totaltime;
	}
}