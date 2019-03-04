#include <iostream>
#include <cstdlib>
//#include <cstring>
//#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		cerr << "No arguments specified.\n";
		return 1;
	}

	// Sets the ifstreams to the command line arguemnts 1 and 2, in binary mode
	ifstream fileOne(argv[1], ios::in | ios::binary), fileTwo(argv[2], ios::in | ios::binary);
	
	// Sets both ifstreams cursor to end of file. Sets the beginning and end point for file scan.
	fileOne.seekg(0, fileOne.end);
	fileTwo.seekg(0, fileTwo.end);

	// Grabs the distance between offset 0 and EOF and makes them into two variables to compare.
	long lengthOne = fileOne.tellg(), lengthTwo = fileTwo.tellg();

	// Compare the sizes, exits if the sizes are mismatched
	if (lengthOne != lengthTwo)
	{
		cerr << "File size mismatch!\nWill not continue.\nFile One: " << lengthOne << "\nFile Two: " << lengthTwo << endl;
		return 1;
	}

    cout << "Preliminary size check passed." << endl;

	// Reset cursor to beginning
	fileOne.seekg(0, fileOne.beg);
	fileTwo.seekg(0, fileTwo.beg);
	
	// Create both file buffers
	char * bufferOne = new char[lengthOne], * bufferTwo = new char[lengthTwo];

	// Finally read both files to char buffers
	fileOne.read(bufferOne, lengthOne);
	fileTwo.read(bufferTwo, lengthTwo);

	// Creating a counter variable to log where we are in compares. Logging failures and successes in integer variables. Initialized to 0 to prevent any confusion.
	long match = 0, mismatch = 0;

	// Begin comparing process
	
		////    PROTOTYPING IN PROGRESS

	for (long i = 0; i < lengthOne; i++)
	{
		//cout << i << "/" << lengthOne << "\r";
		if    (bufferOne[i] == bufferTwo[i])      { match++;    }
		else			         	  			  { mismatch++; }
	}

	cout
	 << "Matches:       " <<  match                       		  << " Bytes\n"
 	 << "Match rate:    " << ((double)match    / lengthOne) * 100 << "%\n"
	 << "Mismatches:    " <<  mismatch                            << " Bytes\n" 
	 << "Mismatch rate: " << ((double)mismatch / lengthOne) * 100 << "%" << endl;

	return 0;
}
