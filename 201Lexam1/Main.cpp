#include "Lab08Utility.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	string category;
	double item;
	vector < double> dvd, music, tv;

	//Reading from file
	ifstream inputFile("input.txt"); //Open the input file
	if (!inputFile.is_open()) {
		cout << "Cannot open the input file" << endl;
		exit(1);
	}

	while (inputFile >> category >> item) {
		if (category.compare("DVD") == 0)
			dvd.push_back(item);
		else if (category.compare("TV") == 0)
			tv.push_back(item);
		else if (category.compare("MUSIC") == 0)
			music.push_back(item);
	}

	inputFile.close(); //Close the input file

	ofstream outputFile("output.txt"); // Open output file
	if (!outputFile.is_open()) {
		cout << "Cannot open the output file" << endl;
		exit(1);
	}


	outputFile << "\tTotal\tMean\tMedian\n";

	outputFile << "DVD\t";
	outputFile << calcTotal(dvd) << "\t";

	try {
		outputFile << calcMean(dvd) << endl;
	}
	catch (...) {
		outputFile << "nan" << endl;
	}

	try {
		outputFile << calcMedian(dvd) << "\t";
	}
	catch (...) {
		outputFile << "nan\t";
	}

	outputFile << "TV\t";
	outputFile << calcTotal(tv) << "\t";
	try {
		outputFile << calcMean(tv) << endl;
	}
	catch (...) {
		outputFile << "nan" << endl;
	}
	try {
		outputFile << calcMedian(tv) << "\t";
	}
	catch (...) {
		outputFile << "nan\t";
	}

	outputFile << "MUSIC\t";
	outputFile << calcTotal(music) << "\t";
	try {
		outputFile << calcMean(music) << endl;
	}
	catch (...) {
		outputFile << "nan" << endl;
	}
	try {
		outputFile << calcMedian(music) << "\t";
	}
	catch (...) {
		outputFile << "nan\t";
	}

	outputFile.close();

	return 0;

}