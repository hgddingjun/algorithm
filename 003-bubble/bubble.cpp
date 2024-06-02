#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

const int MAX_ITEM = 3000;

void bubbleSort(vector<int> &a) {
    int len_a = (int) a.size();
    for (int j = 0; j < len_a - 1; ++j) {
        for (int i = 0; i < len_a - 1 - j; ++i) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

int main() {
    auto arr = vector<int>{};

    // 放入样例
    for (int i = 0; i < MAX_ITEM; ++i) {
        arr.push_back(MAX_ITEM - i);
    }

    // 测试部分
    auto start = system_clock::now();
    bubbleSort(arr); // 冒泡部分
    auto finish = system_clock::now();
    auto duration = duration_cast<microseconds>(finish - start);
    auto cost = double(duration.count()); // * microseconds::period::num / microseconds::period::den;

    // 打印测试结果(可选)
    for (const auto &item : arr) {
         cout << item << " ";
     }
     cout << endl;
    cout << "cost: " << cost << "us" << endl;
}
