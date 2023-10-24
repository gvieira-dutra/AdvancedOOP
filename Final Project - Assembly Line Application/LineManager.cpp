// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: August 2, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

using namespace std;

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		//Extract workstations in order received.
		Utilities mptUtil{};
		Station* mptStation{};

		if (file.empty()) {
			throw string("ERROR: No filename provided.");
		}

		ifstream myFile(file);
		if (!myFile)
			throw string("Unable to open [") + file + "] file.";

		string line, temp;
		while (!myFile.eof())
		{
			size_t startAt{}, ctn{};
			bool keepSearch{ true };

			getline(myFile, line);

			// Define a lambda function to handle the loop body
			auto loopBody = [&](const char& ) {
				temp = mptUtil.extractToken(line, startAt, keepSearch);

				// Find the first station with a matching item name
				auto it = std::find_if(stations.begin(), stations.end(), [&](const Station* station) {
					return ctn == 0 && station->getItemName() == temp;
					});

				if (it != stations.end())
				{
					m_activeLine.push_back(*it);

					if (keepSearch)
					{
						temp = mptUtil.extractToken(line, startAt, keepSearch);

						// Find the station with the matching item name and set it as the next station
						auto nextStation = std::find_if(stations.begin(), stations.end(), [&](const Station* station) {
							return station->getItemName() == temp;
							});

						if (nextStation != stations.end())
						{
							m_activeLine[m_activeLine.size() - 1]->setNextStation(*nextStation);
						}
					}
				}

				ctn++;
			};

			// Replace the while loop with std::for_each
			std::for_each(line.begin(), line.end(), loopBody);
		}

		myFile.close();

		//logic to determine 1st item of the list

		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {

			bool anyMatch = any_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* otherStation) {
			
				mptStation = otherStation->getNextStation();
				if (mptStation)
				{
					string jName = mptStation->getItemName();
					return station->getItemName() == jName;
				}
					return false;
				});

		if (!anyMatch)
		{
			m_firstStation = station;
			}
		});	
	}

	void LineManager::reorderStations()
	{
		for (size_t i = 0; i < m_activeLine.size(); i++)
		{
			Workstation* mptWorkStation{};
			if (m_firstStation->getItemName() == m_activeLine[i]->getItemName())
			{
				mptWorkStation = m_activeLine[0];
				m_activeLine[0] = m_firstStation;
				m_activeLine[i] = mptWorkStation;
			}
		}

		for (size_t i = 0; i < m_activeLine.size() - 1; i++)
		{
			Workstation* mptWorkStation{};
			mptWorkStation = m_activeLine[i]->getNextStation();

			for (size_t j = 0; j < m_activeLine.size(); j++)
			{
				if (mptWorkStation)
				{
					if (mptWorkStation->getItemName() == m_activeLine[j]->getItemName())
					{
						mptWorkStation = m_activeLine[i + 1];
						m_activeLine[i + 1] = m_activeLine[j];
						m_activeLine[j] = mptWorkStation;
					}
				}
			}
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t calls{};

		cout << "Line Manager Iteration: " << ++calls << endl;

		if (g_pending.size() > 0)
		{
			*m_firstStation += std::move(g_pending[0]);
			g_pending.pop_front();
			m_cntCustomerOrder++;
		}

		for (size_t i = 0; i < m_activeLine.size(); i++)
		{
			m_activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < m_activeLine.size(); i++)
		{
			m_activeLine[i]->attemptToMoveOrder();
		}

		return (g_incomplete.size() + g_completed.size() == m_cntCustomerOrder ? true : false);
	}

	void LineManager::display(std::ostream& os) const
	{
		Station* mptStation{};

		for (size_t i = 0; i < m_activeLine.size(); i++)
		{
			cout << m_activeLine[i]->getItemName() << " --> ";

			mptStation = m_activeLine[i]->getNextStation();
			if (mptStation)
			{
				cout << mptStation->getItemName();
			}
			else
				cout << "End of Line";
			cout << endl;
		}
	}
}