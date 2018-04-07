// Comparator.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
//#include "stdafx.h"

using namespace std;

bool compare(char a, char b)
{
	if (a == b) { return true; }
	else		{ return false; }
}

int main(int argc, char * argv[])
{
	if (argv[1] != NULL && argv[2] != NULL)
	{
		// Sets the ifstreams to the command line arguemnts 1 & 2, in binary mode
		ifstream fileOne(argv[1], ios::in | ios::binary);
		ifstream fileTwo(argv[2], ios::in | ios::binary);
	
		// Sets both ifstreams cursor to end of file
		fileOne.seekg(0, fileOne.end);
		fileTwo.seekg(0, fileTwo.end);

		// Grabs the distance between offset 0 and EOF
		int lengthOne = fileOne.tellg();
		int lengthTwo = fileTwo.tellg();

		// Compare the sizes, exits if the sizes are mismatched
		if (lengthOne != lengthTwo)
		{
			cout << "File size mismatch!\nWill not continue." << endl;
			cout << "File One: " << lengthOne << endl;
			cout << "File Two: " << lengthTwo << endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			cout << "Preliminary size check passed." << endl;
		}

		// Reset cursor to beginning
		fileOne.seekg(0, fileOne.beg);
		fileTwo.seekg(0, fileTwo.beg);
	
		// Create both file buffers
		char * bufferOne = new char[lengthOne];
		char * bufferTwo = new char[lengthTwo];

		// Finally read both files to char buffers
		fileOne.read(bufferOne, lengthOne);
		fileTwo.read(bufferTwo, lengthTwo);

		// Creating a counter variable to log where we are in compares. Logging failures and successes in integer variables
		float step, success, failure;

		// Set all to zero, because I don't trust compilers to know it's declared as 0.
		step = success = failure = 0;

		// Begin comparing process
		
			////    PROTOTYPING IN PROGRESS

		for (int i = 0; i < lengthOne; i++)
		{
			cout << i << "/" << lengthOne << "\r";
			if (bufferOne[i] == bufferTwo[i]) { success++; }
			else							  { failure++; }
		}

		cout << "Successes: " << success << endl;
		cout << "Success rate: " << (success / lengthOne) * 100 << "%" << endl;
		cout << "Failures: " << failure << endl;
		cout << "Failure rate: " << (failure / lengthOne) * 100 << "%" << endl;
	}

	return 0;
}