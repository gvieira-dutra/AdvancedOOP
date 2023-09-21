/*
gleison vieira  dutra
gvieira-dutra@myseneca.ca
119237220
July 23, 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {

	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, 
										  const GeneratingList<Salary>& sal) 
	{
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		string msg = "Invalid SIN";
		size_t ctn{1};

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if(emp[i].id == sal[j].id)
				{

					EmployeeWage* newEmp = new EmployeeWage(emp[i].name, sal[j].salary);

					try 
					{ 
						newEmp->rangeValidator();

						if (!activeEmp.checkSin(emp[i].id))
						{
							delete newEmp;
							throw msg;
						}

						activeEmp += newEmp; 
						ctn++;
					}
					catch (const string& msg)
					{
						delete newEmp;
						throw msg;
					}
					
					if (newEmp) delete newEmp;
				}

			}
		}	
		return activeEmp;
	}


	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		string msg = "Invalid SIN";
		size_t ctn{ 1 };

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{

					unique_ptr <EmployeeWage> newEmp(new EmployeeWage(emp[i].name, sal[j].salary));

					try
					{
						newEmp->rangeValidator();

						if (!activeEmp.checkSin(emp[i].id))
						{
							throw msg;
						}

						activeEmp += move(newEmp);
						ctn++;
					}
					catch (const string& msg)
					{
						throw msg;
					}

				}

			}

		}
		
		
		
		return activeEmp;
	}
}