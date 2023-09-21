#pragma once
#include <string>
#include <stdexcept>
#include<string.h>
#include <iostream>

namespace sdds {

	template <typename T>
	class Collection {
		
		std::string m_name{};
		T* myArr{};
		size_t arrSize{};

		void (*ptr)(const Collection<T>&, const T&) {};
		

	public:
		Collection() {};
		Collection(const std::string& name) : m_name(name) 
		{
			
		}

		Collection& operator=(const Collection& src) = delete;
		Collection(Collection&) = delete;
		Collection& operator=(const Collection&& src) = delete;
		Collection(Collection&&) = delete;

		~Collection() 
		{
			delete[] myArr;
		}

		const std::string& name() const
		{
			return m_name;
		}

		size_t size() const
		{
			return arrSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) 
		{
			ptr = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool flag = true;
			
			for (size_t i = 0; i < arrSize; i++)
			{
				if (!strcmp(myArr[i].title().c_str(), item.title().c_str()))
				{
					flag = false;
					i = arrSize;
				}
			}

			if (flag)
			{
/*				T* temp = new T[10];
				temp = myArr;
				temp[0] = item;
				if (myArr != nullptr)
					delete[] myArr;

				myArr = new T[arrSize + 1];
				myArr = temp;
				myArr[arrSize] = item;
				arrSize++;

				delete[] temp;
				temp = nullptr;*/

				T* temp = new T[arrSize + 1];

				for (size_t i = 0; i < arrSize; i++)
				{
					temp[i] = myArr[i];
				}

				if (myArr != nullptr) {
					delete[] myArr;
					myArr = nullptr;
				}

				myArr = new T[arrSize + 1];

				for (size_t i = 0; i < arrSize; i++)
				{
					myArr[i] = temp[i];
				}

				myArr[arrSize] = item;

				arrSize++;

				if(temp)
				{
					delete[] temp;
					temp = nullptr;
				}

			if (ptr != nullptr) {
				ptr(*this, item);
			}
			//	myArr = temp; 
			//	myArr[arrSize] = item;

			//	delete[] temp;

			}
			//*this == cur obj, colection<T>& //prof code in class to explain *this part
			return *this;
		}

		T& operator[](size_t idx) const
		{
			std::string temp = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arrSize) + "] items.";
		
			if (idx >= arrSize)
			{
				throw std::out_of_range(temp);
			}
			else
			{
				return myArr[idx];
			}

		}

		T* operator[](const std::string& title) const
		{

			for (size_t i = 0; i < arrSize; i++)
			{
				if (!strcmp(title.c_str(), myArr[i].title().c_str()))
				
					return &myArr[i];
			}
			return nullptr;
		}
	};

		template <typename T>
		std::ostream& operator<<(std::ostream& os, const Collection<T>& src) 
		{
			
			for (size_t i = 0; i < src.size(); i++)
			{
				os << src[i];
			}

			return os;
		}
}