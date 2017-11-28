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
#include <iosmanip>
#include <fstream>
#include <cstring>
using namespace std; 
void outputD(ArrayList<int>& list) {
	ArrayList<int> selectionList = list; 
	ArrayList<int> mergeList = list; 
	ArrayList<int> quickList = list; 
	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize();

	cout <<	"Selection Sort Results:" << endl; 
	selectionSort(selectionList); 
	// ADDDDD PRINT FUNCTION IN ARRAYLIST??????? OR << OVERRIDE 
	cout << selectionList << endl; 
	cout << "Merge Sort Results: " << endl; 
	mergeSort(mergeList); 
	cout << mergeList << endl;
    cout << "Quick Sort Results:" << endl;
	quickSort(quickList); 
	cout << quickList << endl; 	
	stats(selectionList, mergeList, quickList); 
}

void output(char* fileName, ArrayList<int>& list) {
	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize(); 

	
}

void stats(ArrayList<int>& sList, ArrayList<int>& mList, ArrayList<int>& qList) {
	// NumAcess
	cout << setw(15) << left << "NumAccess: " 
		 << setw(15) << "Selection= " << sList.getNumAccess() 
		 << setw(15) << "Merge= " << mList.getNumAccess() 
		 << setw(15) << "Quick= " << qList.getNumAccess() << endl; 
	// NumSwap 
	cout << setw(15) << left << "NumSwap: " 
		 << setw(15) << "Selection= " << sList.getNumSwap() 
		 << setw(15) << "Merge= " << mList.getNumSwap() 
		 << setw(15) << "Quick= " << qList.getNumSwap() << endl; 
	// NumRemove 
	cout << setw(15) << left << "NumRemove: " 
		 << setw(15) << "Selection= " << sList.getNumRemove() 
		 << setw(15) << "Merge= " << mList.getNumRemove() 
		 << setw(15) << "Quick= " << qList.getNumRemove() << endl; 
	// NumInsertAt 
	cout << setw(15) << left << "NumInsertAt: " 
		 << setw(15) << "Selection= " << sList.getNumInsertAt() 
		 << setw(15) << "Merge= " << mList.getNumInsertAt()
		 << setw(15) << "Quick= " << qList.getNumInsertAt() << endl; 
	// NumAppend 
	cout << setw(15) << left << "NumAppend: " 
		 << setw(15) << "Selection= " << sList.getNumAppend() 
		 << setw(15) << "Merge= " << mList.getNumAppend() 
		 << setw(15) << "Quick= " << qList.getNumAppend() << endl; 
}

void selectionSort(ArrayList<int>& list) {
	int startScan, minIndex, minValue; 

	for (startScan = 0; startScan < list.getSize() - 1; ++startScan
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

