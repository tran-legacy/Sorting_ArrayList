/*************************
 * Tran Le
 * CSS342 - Project 5
 * [INSERT TIME HERE]
 * Vim on Cygwin
**************************/
////////////////////////////
// sortStatistics.cpp is the main 
// It reads in a file of ints and sort them 
////////////////////////////
#include "arrayList.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std; 
void outputD(ArrayList<int>& list) {
	ArrayList<int> selectionList = list; 
	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize(); 
	cout <<	"Selection Sort Results:" << endl; 
	list.
}

void output(char* fileName, ArrayList<int>& list) {
	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize(); 
	
}

void stats() {

}

void selectionSort(ArrayList<int>& list) {

}

void mergeSort(ArrayList<int>& list) {

}

void quickSort(ArrayList<int>& list) {

}

int main(int argc, char* *argv) {
	if (strcmp[argv[1], "-d"] == 0 ) { // If the second word is -d
		ArrayList<int> originalArray; 	
		std::ifstream infile(argv[2]); 
		if (infile.is_open() && infile.good()) {
			// Get numbers from list to the array
			int num; 
			while (infile >> num) {
				originalArray.append(num); 
			}
		}
		//IMPLEMENT THE THING
	} else if (
	

	return 0; 
}

