/******************************************************/
/* Gleison Vieira Dutra                               */
/* gvieira-dutra@myseneca.ca                          */
/* 119237220                                          */
/* Completed by June 4, 2023                          */
/* I have done all the coding by myself and only      */
/* copied the code that my professor provided to      */
/* complete my workshops and assignments.             */
/******************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include "Dictionary.h"
#include <iostream>

namespace sdds {
	template <typename T, int num>
	class Queue {
		T arrOfData[num]{}; //static array to hold elements in the queue
		unsigned CAPACITY = num; //array capacity
		int currentSize{}; //current num of elements in the array
		static T emptyObj; //empty obj to be returned in case obj requested does not exist

	public:
		//default constructor
		Queue() {
			for (int i = 0; i < num; i++)
				arrOfData[i] = T{};
		}

		//Empty body destructor
		virtual ~Queue() {};

		//checks if we can an item to the queue
		virtual bool push(const T& item) {
			bool flag = false;

			if (currentSize < int(CAPACITY))
			{
				addItems(item);
				flag = true;
			}
			return flag;
		};

		//removes 1st item from queue, return a copy of the removed obj
		T pop() {
			T objCopy = arrOfData[0];
			if (currentSize > 0)
			{
				for (int i = 1; i < currentSize; i++)
				{
					arrOfData[i - 1] = arrOfData[i];
				}
				currentSize--;
			}
			return objCopy;
		};

		//returns current number of elements in queue
		int size() const {
			return currentSize;
		};

		//returns the element in the array at given index
		T getElement(int idx) {
			return arrOfData[idx];
		};

		//returns how many items the array can hold
		int capacity() const {
			return static_cast<int>(CAPACITY);
		};

		// adds an item to the array
		void addItems(const T& item) {
			arrOfData[currentSize++] = item;
		}

		//inserts all items to output stream
		std::ostream& display(std::ostream& os = std::cout) const {
			std::cout << "----------------------" << std::endl;
			std::cout << "| Dictionary Content |" << std::endl;
			std::cout << "----------------------" << std::endl;

			for (int i = 0; i < currentSize; i++)
			{
				os << arrOfData[i] << std::endl;
			}
			os << "----------------------" << std::endl;
			return os;
		}

		//returns a copy of the element in the index received
		T operator[](int idx) const {
			return idx < currentSize ? arrOfData[idx] : emptyObj;
		};
	};

	//Initializes our static variable 'currentSize' to empty every time a new instance type of the class is created

	//Initializes our static empty object to its appropriate type every time a new instance type of the class is created
	template<typename T, int num>
	T Queue<T, num>::emptyObj{};

	//Specialization for when type is T = Dictionary and int = 100u so we initialize empty object to its appropriate terms
	template<>
	Dictionary Queue<Dictionary, 100u>::emptyObj = Dictionary("Empty Term", "Empty Substitute");

	//Helper << operator overload to display our objects in the screen
	template <typename T, int num>
	std::ostream& operator<<(std::ostream& os, const Queue <T, num>& src) {
		return src.display(os);
	};
}

#endif