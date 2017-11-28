/***************************
 * Tran Le
 * CSS342 - Project #5
 * [INSERT HOW LONG HERE]
 * Vim on Cygwin
****************************/

/////////////////////////////
// This is the implementation file 
// of arrayList.h
/////////////////////////////
#include <iostream>

template<class T>
int ArrayList<T>::numAccess = 0; 
template<class T>
int ArrayList<T>::numSwap = 0; 
template<class T>
int ArrayList<T>::numRemove = 0; 
template<class T>
int ArrayList<T>::numInsertAt = 0; 
template<class T>
int ArrayList<T>::numAppends = 0; 

/*************CONSTRUCTOR*****************/
template<class T> 
ArrayList<T>::ArrayList(int capacity) {
	// Dynamically allocate the array 
	array = new T[capacity];
    this->size = 0; 	
	this->capacity = capacity; 
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& obj) {
	array = new T[obj.capacity]; 
	
	// copy data over
	for (int i = 0; i < obj.size; ++i) {
		array[i] = obj[i];
	}

	// copy private members 
	this->capacity = obj.capacity; 
	this->size = obj.size;
}
/*************DESTRUCTOR*****************/ 
//template<class T>
//ArrayList<T>::~ArrayList() {
//	std::cout << "DESTRUCTOR CALLED" << std::endl;
//	delete [] array;  
//	array = NULL;
//}

/**************FUNCTIONS***************/
template<class T> 
bool ArrayList<T>::isEmpty() const {
	return size == 0; 
}

template<class T>
int ArrayList<T>::getSize() const {
	return size; 
}

//// Inserts a value at the given index////
template<class T>
void ArrayList<T>::insertAt(int index, const T& newEntry) throw(std::out_of_range) {
	if (index > this->size || index < 0)  
		throw std::out_of_range("Invalid index on insert");
	if (size == capacity) 
		growArray(); 
	for (int i = size - 1; i >= index; --i) {
		array[i+1] = array[i]; 
	}
	array[index] = newEntry; 
	++size;
   	++ArrayList<T>::numInsertAt; 	
}

//// Remove a value at given index ////
template<class T>
void ArrayList<T>::removeAt(int index) throw(std::out_of_range) {
	if (index > this->size - 1 || index < 0)
        throw std::out_of_range("Invalid index");
	
	for (int i = index; i < size; ++i) {
		array[i] = array[i+1]; 
	}
	--size;
    ++ArrayList<T>::numRemove; 
}	

//// Add value to the end of the list ////
template<class T>
void ArrayList<T>::append(const T& value) {
	if (size == capacity) 
		growArray(); 
	// size is now the index next to the last value
	array[this->size] = value; 	
	++size; 
	++ArrayList<T>::numAppends; 
}
//// Swaps the values from the given indexes ////
template<class T>
void ArrayList<T>::swap(int from, int to) throw(std::out_of_range) {
	if (from > size - 1 || from < 0 || to > size - 1 || to < 0) 
		throw std::out_of_range("Invalid index"); 

	T temp = array[from]; 
	array[from] = array[to]; 
	array[to] = temp;
   	++ArrayList<T>::numSwap; 	
}

////returns the value at the given index //// 
template<class T>
T& ArrayList<T>::getAt(int index) const throw (std::out_of_range) {
	if (index > size - 1 || index < 0) 
		throw std::out_of_range("Invalid index");

	++ArrayList<T>::numAccess; 
	return array[index];
}

//// clear all???? ////
template<class T>
void ArrayList<T>::clearAll() {
	this->size = 0; 
}

/*******************OPERATOR OVERLOAD**********************/ 
template<class T>
T& ArrayList<T>::operator[] (int index) const throw (std::out_of_range) {
	this->getAt(index); 
}

template<class T>
ArrayList<T>& ArrayList<T>::operator= (const ArrayList<T>& rhs) {
	if (this == &rhs) return *this; 
	
	// delete whatever is in this first
	delete [] array; 
	array = new T[rhs.capacity]; 
	
	// copy data over
	for (int i = 0; i < rhs.size; ++i) {
		array[i] = rhs[i];
	}

	// copy private members 
	this->capacity = rhs.capacity; 
	this->size = rhs.size;
	
	return *this; 
}

/**************STATISTIC FUNCTIONS***************/
template <class T>
void ArrayList<T>::clearStatistics() {
    ArrayList<T>::numAccess = 0;
    ArrayList<T>::numSwap = 0;
    ArrayList<T>::numRemove = 0;
    ArrayList<T>::numInsertAt = 0;
    ArrayList<T>::numAppends = 0;
}

template <class T>
int ArrayList<T>::getNumAccess() const { return ArrayList<T>::numAccess; }

template <class T>
int ArrayList<T>::getNumSwap() const { return ArrayList<T>::numSwap;}

template <class T>
int ArrayList<T>::getNumRemove() const { return ArrayList<T>::numRemove;}

template <class T>
int ArrayList<T>::getNumInsertAt() const { return ArrayList<T>::numInsertAt; }

template <class T>
int ArrayList<T>::getNumAppends() const { return ArrayList<T>::numAppends; }


/**************PRIVATE METHOD*****************/
//// When the array needs more space, it'll double its capacity ////
template <class T>
void ArrayList<T>::growArray() {
	int newCapacity = this->capacity * 2; 

	T* tempArray = new T[newCapacity]; 

	for (int i = 0; i < size; ++i) {
		tempArray[i] = array[i];
	}
	this->capacity = newCapacity;
	delete [] array; 
	this->array = tempArray; 
}
