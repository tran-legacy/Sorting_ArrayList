/*************************
 * Tran Le
 * CSS342 - Project 5
 * 10 hours
 * Vim on Cygwin
**************************/
////////////////////////////
// sortStatistics.cpp is the main 
// It reads in a file of ints and sort them 
////////////////////////////
#include "arrayList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std; 

// Global Variables 
const int ACCESS = 0, SWAP = 1, REMOVE = 2, INSERT = 3, APPEND = 4;
const int WIDTH = 13, WIDTH2 = 9;
/// Inserts stats of a sort into given array, then clearStat of the list//// 
void putStatsInArray(ArrayList<int>& list, int (&array)[5]) {
	array[ACCESS] = list.getNumAccess(); 
	array[SWAP] = list.getNumSwap(); 
	array[REMOVE] = list.getNumRemove(); 
	array[INSERT] = list.getNumInsertAt(); 
	array[APPEND] = list.getNumAppends(); 
	list.clearStatistics(); 
}

void stats(int (&sList)[5], int (&mList)[5], int (&qList)[5]) {
	// NumAcess
	cout << setw(WIDTH) << left << "NumAccess: " 
		 << setw(WIDTH) << "Selection= " << setw(WIDTH2) << sList[ACCESS] 
		 << setw(WIDTH) << "Merge= " << setw(WIDTH2) << mList[ACCESS] 
		 << setw(WIDTH) << "Quick= " << setw(WIDTH2) << qList[ACCESS] << endl; 
	// NumSwap 
	cout << setw(WIDTH) << left << "NumSwap: " 
		 << setw(WIDTH) << "Selection= " << setw(WIDTH2) << sList[SWAP] 
		 << setw(WIDTH) << "Merge= " << setw(WIDTH2) << mList[SWAP] 
		 << setw(WIDTH) << "Quick= " << setw(WIDTH2) << qList[SWAP] << endl; 
	// NumRemove 
	cout << setw(WIDTH) << left << "NumRemove: " 
		 << setw(WIDTH) << "Selection= " << setw(WIDTH2) << sList[REMOVE] 
		 << setw(WIDTH) << "Merge= " << setw(WIDTH2) << mList[REMOVE] 
		 << setw(WIDTH) << "Quick= " << setw(WIDTH2) << qList[REMOVE] << endl; 
	// NumInsertAt 
	cout << setw(WIDTH) << left << "NumInsertAt: " 
		 << setw(WIDTH) << "Selection= " << setw(WIDTH2) << sList[INSERT] 
		 << setw(WIDTH) << "Merge= " << setw(WIDTH2) << mList[INSERT]
		 << setw(WIDTH) << "Quick= " << setw(WIDTH2) << qList[INSERT] << endl; 
	// NumAppend 
	cout << setw(WIDTH) << left << "NumAppend: " 
		 << setw(WIDTH) << "Selection= " << setw(WIDTH2) << sList[APPEND] 
		 << setw(WIDTH) << "Merge= " << setw(WIDTH2) << mList[APPEND] 
		 << setw(WIDTH) << "Quick= " << setw(WIDTH2) << qList[APPEND] << endl; 
}

/**********************SELECTION SORT***********************/ 
//// Finds the min and swap it to the "current" index //// 
void selectionSort(ArrayList<int>& list) {
	int startIndex, minIndex, minValue; 

	for (startIndex = 0; startIndex < list.getSize() - 1; ++startIndex) {
		minIndex = startIndex; 
		minValue = list[startIndex]; 
		for (int index = startIndex + 1; index < list.getSize(); ++index) {
			if (list[index] < minValue) {
				minValue = list[index]; 
				minIndex = index; 
			}
		}
		list.swap(minIndex, startIndex);
	}	
}


/****************MERGE SORT*********************/
//// Helper method for mergeSort ////
void merge(ArrayList<int>& list, int first, int mid, int last) {
	ArrayList<int> tempList;	// Create temp array  

	// Init the indeces of subarrays
	int first1 = first; 
	int last1 = mid; 
	int first2 = mid + 1; 
	int last2 = last; 
	
	// while there are still values in both subarrays
	while (first1 <= last1 && first2 <= last2) {
		// if the current value in first subarray is smaller than the second
		// subarray, append the value to the tempList
		if (list[first1] <= list[first2]) { 
			tempList.append(list[first1]); 
			++first1;  // "remove value" from subarray 
		} else { 				
			// Else first value in second subarray is smaller than the first
			// append the value to the tempList
			tempList.append(list[first2]);
			++first2; // "remove value" from subarray
		}

	}
	// If first subarray values aren't all "removed"
	// "remove" and append to tempList
	while (first1 <= last1) {
		tempList.append(list[first1]); 
		++first1; 
	}
	// Do same for second subarray 
	while (first2 <= last2) {
		tempList.append(list[first2]); 
		++first2; 
	}

	// Move result back into original array 
	for (int i = 0; i < tempList.getSize(); ++i) {
		list[first++] = tempList[i]; 
	}
}

/// Recursively divide array in half, and sorting them, then finally merging ////
void mergeSort(ArrayList<int>& list, int first, int last) {
	
	if (first < last) {
		// Find midpoint index 
		int mid = first + (last - first) / 2; 
		// Sort left half
		mergeSort(list, first, mid); 
		// Sort right half
		mergeSort(list, mid + 1, last); 
		// Then, merge the two halves 
		merge(list, first, mid, last); 
	}
}
/****************QUICK SORT********************/
void quickSort(ArrayList<int>& list, int first, int last) {
	int left = first; 
	int right = last; 
	int pivot = list[(left + right) / 2]; 

	// Paritioning
	// while left index is less than right
	while (left <= right) {
		// while value of left is less pivot value, keep incrementing left index
		while (list[left] < pivot) 
			++left;
		// while value of right is more than pivot value, keep decrementing
		while (list[right] > pivot)
			--right; 
		// check if left index is on left and right is on right
		if (left <= right) {
			// Swap the two values
			// now they're on the correct side of the pivot
			list.swap(left, right); 
			++left; 
			--right; 
		}
	}; 
	// Recursive
	if (first < right)
		quickSort(list, first, right); 
	if (left < last) 
		quickSort(list, left, last); 
}

//// Output when command line as "-d" ////
void outputD(char* fileName, ArrayList<int>& list) {
	// 3 copies of the list passed in 
	// Copies because you don't want to sort the same sorted list
	ArrayList<int> selectionList = list; 
	ArrayList<int> mergeList = list; 
	ArrayList<int> quickList = list; 
	// Arrays to hold stats of each merge
	int selectionStats[5], mergeStats[5], quickStats[5]; 

	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize() << endl;

	cout <<	"Selection Sort Results:" << endl; 
	selectionSort(selectionList); 
	putStatsInArray(selectionList, selectionStats); 
	selectionList.print(); 

	cout << "Merge Sort Results: " << endl; 
	mergeSort(mergeList, 0, mergeList.getSize() - 1); 
	putStatsInArray(mergeList, mergeStats); 
	mergeList.print(); 

    cout << "Quick Sort Results:" << endl;
	quickSort(quickList, 0, quickList.getSize() - 1); 
	putStatsInArray(quickList, quickStats);
	quickList.print(); 

	stats(selectionStats, mergeStats, quickStats); 
}

//// Same as output with "-d", but without printing out the sorted list ////
void output(char* fileName, ArrayList<int>& list) {
	ArrayList<int> selectionList = list; 
	ArrayList<int> mergeList = list; 
	ArrayList<int> quickList = list; 
	// Arrays to hold stats of each merge
	int selectionStats[5], mergeStats[5], quickStats[5]; 

	cout << "Filename: " << fileName << endl; 
	cout << "Number of items: " << list.getSize() << endl;

	selectionSort(selectionList); 
	putStatsInArray(selectionList, selectionStats); 

	mergeSort(mergeList, 0, mergeList.getSize() - 1); 
	putStatsInArray(mergeList, mergeStats); 

	quickSort(quickList, 0, quickList.getSize() - 1); 
	putStatsInArray(quickList, quickStats);

	stats(selectionStats, mergeStats, quickStats); 
	
}


int main(int argc, char* *argv) {
	ArrayList<int> originalArray; 	
	int num;
	// If there are 3 argc
	if (argc == 3) {
		if (strcmp(argv[1], "-d") == 0 ) { // If the second word is -d
	        ifstream infile(argv[2]); 
			if (infile.is_open() && infile.good()) {
				// Get numbers from list to the array
				while (infile >> num) {
					originalArray.append(num); 
				}
			}
			outputD(argv[2], originalArray); 
		} else {
			cout << "Invalid argument" << endl;
		}
	} else if (argc == 2) {
		ifstream file(argv[1]); 
		if (file.is_open() && file.good()) {
			while (file >> num) {
				originalArray.append(num); 
			}
			output(argv[1], originalArray); 
		} else {
			cout << "Invalid argument" << endl;
		}
	} else {
		cout << "Invalid argument" << endl;
	}	

	return 0; 
}


