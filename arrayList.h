/***************************
 * Tran Le
 * CSS342 - Project #5 
 * 10 hours 
 * Vim on Cygwin 
****************************/

/////////////////////////////
// ArrayList class 
// A smart array that can remove and insert with ease
// like a vector
/////////////////////////////
#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "listInterface.h" 


template<class T>
class ArrayList: public ListInterface<T> {
public: 
	// CONSTRUCTOR (can override default)
	ArrayList(int capacity = DEFAULT_CAPACITY);
	ArrayList(const ArrayList<T>& obj); 

	// DESTRUCTOR 
	virtual ~ArrayList() {
		delete [] array; 
		array = NULL;
	}	

	// FUNCTIONS
	bool isEmpty() const override; 
	int getSize() const override; 
	void insertAt(int index, const T& newEntry) throw(std::out_of_range) override; 
	void removeAt(int index) throw(std::out_of_range) override; 
	void append(const T& value) override; 
    void swap( int from, int to) throw( std::out_of_range) override; 
    T& getAt( int index) const throw ( std::out_of_range) override; 
	void clearAll() override; 
	void print() const; 
	// STATS 
	// Clear out any instrumentation 
	void clearStatistics() override; 
	 // Provide statistics on number of times method was performed
    int getNumAccess() const override;    // operator [] OR getAt
    int getNumSwap() const override;
    int getNumRemove() const override;
    int getNumInsertAt() const override;
    int getNumAppends() const override;

	// OPERATOR OVERLOAD
	virtual T& operator[] (int index) const throw(std::out_of_range) override; 
	ArrayList<T>& operator= ( const ArrayList<T>& rhs);
	
private: 
	T* array; 
	int capacity; 
	int size; 
	static const int DEFAULT_CAPACITY = 10; 
	static int numAccess; 
	static int numSwap; 
	static int numRemove; 
	static int numInsertAt; 
	static int numAppends; 
	void growArray(); 
};
#include "arrayList.cpp"
#endif //!ARRAY_LIST
