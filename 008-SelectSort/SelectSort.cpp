#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int SIZE = 3000;

void SWAP(int *a, int *b);

void PrintArray(int *array, const int size);
void SelectSort(int* array, const int size);

void PrintArrayII(vector<int>& array);
void BubbleSortII(vector<int> &array);
void SelectSortII(vector<int> &array);

template <typename T> void MeasureFunction(T&& func, vector<int> &array);

int main() {
// 	int x[] = {1, 3, 5, 7, 2, 4, 9, 6, 8, 0};
// 	cout << "Before Select Sort: ";
// 	PrintArray(x, 10);
// 	SelectSort(x, 10);
// 	cout << "After Select Sort: ";


	vector<int> b;
	for (int i = 0; i < SIZE; ++i) {
		b.push_back(SIZE - i);
	}

	cout << endl <<"===Bubble Sort===" <<endl;
	//BubbleSortII(b);
	MeasureFunction(BubbleSortII, b);
	//PrintArrayII(b);

	cout << endl <<"===Select Sort===" <<endl;
	//SelectSortII(b);
	MeasureFunction(SelectSortII, b);
	//PrintArrayII(b);
	return 0;
}

void SWAP(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int *array, const int size) {
	for(int i=0; i<size; i++) {
		cout << "[" << array[i] << "] ";
	}
	cout << endl;
}

void SelectSort(int* array, const int size) {
	for(int i=0; i<size-1; i++) {
		int min = i;
		for(int j=i+1; j<size; j++) {
			if(array[min] > array[j]) {
				min = j;
			}
		}
		SWAP(&array[min], &array[i]);
		//PrintArray(array, size);
	}
	PrintArray(array, size);
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
	PrintArrayII(array);
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
    PrintArrayII(array);
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

