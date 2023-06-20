/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by June 4, 2023                          */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/
#pragma once
#include <cmath>
#include "Queue.h"

namespace sdds {
	template <typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:

		bool push(const T& item) {
			bool flag = true;
			int length = Queue<T, 100>::size();

			for (int i = 0; i < length; i++)
			{
				if (Queue<T, 100>::getElement(i) == item)
				{
					flag = false;
					i = length;
				}
			}
			if (flag)
			{
				Queue<T, 100>::addItems(item);
			}

			return flag;
		};
	};

	template<>
	bool UniqueQueue<double>::push(const double& item) {
		bool flag = true;
		int length = Queue::size();

		if (length < Queue::capacity())
		{
			for (int i = 0; i < length; i++)
			{
				if (std::fabs(Queue::getElement(i) - item) <= 0.005)
				{
					flag = false;
					i = length;
				}
			}
			if (flag)
			{
				Queue::addItems(item);
			}
		}
		else { flag = false; };

		return flag;
	};
}