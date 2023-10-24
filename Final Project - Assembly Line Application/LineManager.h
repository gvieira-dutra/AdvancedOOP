// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include<vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Workstation.h"
#include "Utilities.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation;
	public:

		//receives the name of the file that identifies the active stations on the assembly line (example: AssemblyLine.txt) and the collection of workstations available for configuring the assembly line.
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		//reorders the workstations present in the instance variable m_activeLine (loaded by the constructor) and stores the reordered collection in the same instance variable
		void reorderStations();

		//this modifier performs one iteration of operations on all of the workstations in the current assembly line
		bool run(std::ostream& os);

		//displays all active stations on the assembly line in their current order
		void display(std::ostream& os) const;
	};
}