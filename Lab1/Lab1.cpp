// Lab 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;



int main(int argc, char*argv[])
{
	// check if the number of arguments passed into the main function is correct (one in addition to the program's name) 
	// if not, call the usage message function and return the associated value
	if (argc != correctArgNum) {
		cout << "Wrong number of command line arguments" << endl;
		return usage_message(argv[programName]);
	}
	vector<string> v, v2; // declaration of the string vector for passing onto the parsing function (v), and the vector for storing non-digit strings (v2) 
	vector<int> v1;  // declaration of the int vector to store numbers from the file

	int res = parsing(v, argv[fileName]);
	if (res != success) {
		return res;   // check if the parsing function returns success; if not, return any other value it has 
	}

	// iterate through the vector of strings and use the isdigit function to see if 
	// there are only numeric digit characters 
	for (size_t s = 0; s < v.size();++s) {
		string i = v[s];
		bool number = true;
		for (size_t l = 0;l < i.size();l++) {
			if (!isdigit(i[l])) {
				number = false;
				v2.push_back(i);
				break;    // once found the non-digit character, break from the iteration 
			}
		}
		// if all characters are found to be numeric digits in the string, it is considered an integer

		if (number) {
			istringstream ss(i);
			int x;
			ss >> x;
			v1.push_back(x);  // then push the integer back into the vector of integers

		}
	}
	for (size_t s = 0;s < v2.size();s++) {
		cout << v2[s] << endl;    // print the strings with non-digit characters
	}
	for (size_t s = 0;s < v1.size();s++) {
		cout << v1[s] << endl;   // print the strings with numbers 
	}

	return success;


}

int usage_message(char* program_name) {
	cout << "usage: " << program_name << " < input_file_name >" << endl; // print usage message
	return wrongArgNum;
}

int parsing(vector<string> & v, char * file_name) {
	ifstream ifs(file_name);
	if (ifs.is_open())
	{
		string line_1, word_1;
		while (getline(ifs, line_1)) {
			istringstream iss(line_1);
			while (iss >> word_1) {
				v.push_back(word_1);  // extract the string and push it back into the vector of strings 
			}
		}
		return success;
	}
	cout << "Cannot Open File" << endl;   // print a line of message if the file cannot be opened 
	return cannotopen;
}

