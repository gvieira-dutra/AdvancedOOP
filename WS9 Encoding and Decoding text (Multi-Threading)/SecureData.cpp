// Workshop 9 - Multi-Threading
// SecureData.cpp

// Name: Gleison Vieira Dutra
// Seneca Student ID: 119237220
// Seneca email: gvieira-dutra@myseneca.ca
// Date of completion: July 30, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <algorithm>
#include "SecureData.h"
#include <numeric>

using namespace std;

namespace w9 {
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		thread t1(converter, text, key, 500, Cryptor());
		thread t2(converter, text + 500, key, 500, Cryptor());
		thread t3(converter, text + 1000, key, 500, Cryptor());
		thread t4(converter, text + 1500, key, nbytes - 1500, Cryptor());

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		encoded = !encoded;
	}
	for (size_t i = 0; i < length; i++)
	{

	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			 
			ofstream myFile(file, ios::out | ios::binary);
			if (!myFile) {
				cout << "Cannot open file!" << endl;
			}

			// TODO: write data into the binary file
			//         and close the file

			myFile.write(&text[0], nbytes);

			myFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		fstream myFile(file, std::ios::in);

		myFile.seekg(0, std::ios::end);
		nbytes = (int)myFile.tellg();
		// TODO: - allocate memory here for the file content

		if (text)
			delete[] text;

		text = new char[nbytes];

		// TODO: - read the content of the binary file
		myFile.seekg(ios::beg);
		int i = 0;
		myFile >> noskipws;
		while (myFile.good())
			myFile >> text[i++];
		//text[nbytes - 1] = '\0';

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}