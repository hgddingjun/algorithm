#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

const int SIZE = 50000;

void SWAP(int *a, int *b);


void PrintArrayII(vector<int>& array);
void BubbleSortII(vector<int> &array);

void SelectSortII(vector<int> &array);

void ShellSortII(vector<int>& array);

void InsertSortII(vector<int>& array);

int MakePivot(vector<int>& array, int left, int right);
void QuickSortII(vector<int>& array, int left, int right);

void SiftHeap(vector<int>& array, int low, int hig);
void HeapSort(vector<int>& array);

template <typename T> void MeasureFunction(T&& func, vector<int> &array);
template <typename T> void MeasureQuickSort(T&& func, vector<int> &array, int left, int right);

void initArray(vector<int>& array);
void initArray(vector<int>& array) {
	for (int i = 0; i < SIZE; ++i) {
		int number = rand() % SIZE + 1;
		array.push_back(number);
	}
}


int main(void) {
	vector<int> b0;
	vector<int> b;

	cout << endl <<"===Initialize Array===" <<endl;
	initArray(b0);
	PrintArrayII(b0);

	cout << endl <<"===Heap Sort===" <<endl;
	b.assign(b0.begin(), b0.end());
	//PrintArrayII(b);
	MeasureFunction(HeapSort, b);
	//PrintArrayII(b);

	cout << endl <<"===Qucik Sort===" <<endl;
	b.assign(b0.begin(), b0.end());
	//PrintArrayII(b);
	MeasureQuickSort(QuickSortII, b, 0, SIZE-1);
	//PrintArrayII(b);

	cout << endl <<"===Bubble Sort===" <<endl;
	b.assign(b0.begin(), b0.end());
	//PrintArrayII(b);
	MeasureFunction(BubbleSortII, b);
	//PrintArrayII(b);

	cout << endl <<"===Select Sort===" <<endl;
	b.assign(b0.begin(), b0.end());
	//PrintArrayII(b);
	MeasureFunction(SelectSortII, b);
	//PrintArrayII(b);

	cout << endl <<"===Insert Sort===" <<endl;
	b.assign(b0.begin(), b0.end());
	//PrintArrayII(b);
	MeasureFunction(InsertSortII, b);
	//PrintArrayII(b);

	return 0;
}

void SWAP(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArrayII(vector<int>& array) {
	for(const auto &e : array)
		cout << "[" << e << "] ";
	cout << endl;
}

template <typename T>
void MeasureFunction(T&& func, vector<int> &array) {
	auto start = system_clock::now();
	func(array);
	auto finish = system_clock::now();
	auto duration = duration_cast<microseconds>(finish - start);
	auto elapsedtime = double(duration.count());
	cout << "elapsed time: [" << elapsedtime <<"] us." <<endl;
}

void BubbleSortII(vector<int> &array) {
    int length = (int) array.size();
    for (int j = 0; j < length - 1; ++j) {
        for (int i = 0; i < length - 1 - j; ++i) {
            if (array[i] > array[i + 1]) {
		    SWAP(&array[i], &array[i+1]);
            }
        }
        //PrintArrayII(array);
    }
    //PrintArrayII(array);
}

void SelectSortII(vector<int> &array) {
	int length = (int) array.size();
	for(int i=0; i<length-1; i++) {
		int min = i;
		for(int j=i+1; j<length; j++) {
			if(array[min] > array[j]) {
				min = j;
			}
		}
		SWAP(&array[min], &array[i]);
		//PrintArrayII(array);
	}
	//PrintArrayII(array);
}

void ShellSortII(vector<int>& array) {
	int length = (int)array.size();
}

void InsertSortII(vector<int>& array) {
	int length = (int)array.size();
	for(int i=1; i<length; i++) {
		int k = array[i];
		int j = i-1;
		while(j>=0 &&  array[j] > k  ) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = k;
	}
	//PrintArrayII(array);
}

template <typename T> 
void MeasureQuickSort(T&& func, vector<int> &array, int left, int right) {
	auto start = system_clock::now();
	func(array,  left, right);
	auto finish = system_clock::now();
	auto duration = duration_cast<microseconds>(finish - start);
	auto elapsedtime = double(duration.count());
	cout << "elapsed time: [" << elapsedtime <<"] us." <<endl;
}

int MakePivot(vector<int>& array, int left, int right) {
	int temp = array[left];
	while (left < right) {
		while(left < right && array[right] >= temp) {
			right--;
		}
		array[left] = array[right];
		//PrintArrayII(array);
		while(left < right && array[left] <= temp) {
			left++;
		}
		array[right] = array[left];
		//PrintArrayII(array);
	}
	array[left] = temp;
	//PrintArrayII(array);
	return left;
}

void QuickSortII(vector<int>& array, int left, int right) {
	int length = (int)array.size();
	if(left < right) {
		int pivot = MakePivot(array, left, right);
		QuickSortII(array, left, pivot-1);
		QuickSortII(array, pivot+1, right);
	}
}

//low: heap root node position
//hig: heap last node position
void SiftHeap(vector<int>& array, int low, int hig) {
	int i = low;  //root
	int j = 2 * i + 1; // i's left child
	int temp = array[low];
	while( j <= hig ) { //
		if( j+1 <= hig && array[j+1] > array[j]) { //right child exist and right child is large
			j = j + 1; // j point right child
		}
		if( array[j] > temp) {
			array[i] = array[j];
			i = j;  //walk down level
			j = 2 * i + 1; //
		} else {
			array[i] = temp;
			break;
		}
	}
	array[i] = temp; //temp put back i position
}

void HeapSort(vector<int>& array) {
	int length = (int)array.size();
	for(int i = (length-2)/2; i>=0; i--) {
		SiftHeap(array, i, length -1);
	} // construct heap complete!
	for(int i = length-1; i>=0; i--) {
		SWAP(&array[0], &array[i]);
		SiftHeap(array, 0, i-1);
	}
}




