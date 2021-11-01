#include "Lab08Utility.h"
#include <vector>
#include <iostream>

using namespace std;

double calcTotal(vector<double> category) {
	double total = 0;
	for (int i = 0; i < category.size(); i++)  //For loop with vector and calculate the total
		total += category[i];
	return total;
}


//Bubble Sort
vector<double> sort(vector<double> values) {
	int i, j, size = values.size();
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (values[j] > values[j + 1]) {
				double temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}

	return values;
}

// Calculate the mean of the values
double calcMean(vector<double> category) {
	int size = category.size();

	if (size == 0)
		throw "Empty Vector";

	return calcTotal(category) / (double)size;
}

//Calculate the meadian by sorting the vector
double calcMedian(vector<double> category) {
	double median = 0;
	int size = category.size();

	if (size == 0) //Throw an exception if there are no times
		throw "Empty Vector";

	vector <double> sorted = sort(category); //Sort vector to find median value

	if (size % 2 == 1) {
		median = sorted[size / 2];
	}
	else {
		median = (sorted[size / 2] + sorted[(size / 2) - 1]) / 2.0;
	}

	return median;
}