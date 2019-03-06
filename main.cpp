#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("No arguments specified.\n");
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
		printf("File size mismatch! Will not continue.\nFile One: %d\nFile Two: %d\n", lengthOne, lengthTwo);
		return 1;
	}

   	printf("Preliminary size check passed.\n");

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
		if    (bufferOne[i] == bufferTwo[i])      { match++;    }
		else			         	  			  { mismatch++; }
	}

	printf("Matches: %d Bytes\nMatch rate: %f%%\nMismatches: %d Bytes\nMismatch rate: %f%%\n",match,((double)match    / lengthOne) * 100,mismatch,((double)mismatch / lengthOne) * 100);
	return 0;
}
