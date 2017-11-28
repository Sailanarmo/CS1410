#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

template <typename T, typename V, typename F>
T timedSort(std::vector<V>& v, F f){
    auto start = std::chrono::high_resolution_clock::now();
    f(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "End, took: ";
    auto duration = end - start;
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    std::cout << milli.count() << " Milliseconds of size: ";
    return std::chrono::duration_cast<T>(end - start);
}

int makeRandom(int n){
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, n);
    return dist(mt);

}

std::vector<int> makeVector(int n){

    std::vector<int> v;
    for(int i = 0; i < n; ++i){
        v.push_back(makeRandom(n));
    }
    return v;
}


void merge(std::vector<int>& v, int start, int mid, int end){
    std::vector<int> merged;
    auto i = start;
    auto j = mid;

    for (int g = start; g < end; ++g)

        while (i < mid && j < end){
            if(v[i] < v[j]){
                merged.push_back(v[i]);
                ++i;
            } else {
                merged.push_back(v[j]);
                ++j;
            }
        }
    while (i < mid) {
        merged.push_back(v[i]);
        ++i;
    }
    while (j < end){
        merged.push_back(v[j]);
        ++j;
    }
    for (int i = start, j = 0; j < merged.size(); ++i, ++j){
        v[i] = merged[j];
    }
}

void mergeSort(std::vector<int>& v, int start, int end){
    if (end - start < 2) return;
    auto mid = ((start + end) / 2);
    mergeSort(v, start, mid);
    mergeSort(v, mid, end);
    merge(v, start, mid, end);
}

void initMergeSort(std::vector<int>& v){
    mergeSort(v, 0, v.size());
}

void bubbleSort(std::vector<int>& n){
    auto done = false;
    while(!done){
        done = true;
        for(auto i = 0u; i < n.size()-1; ++i){
            if(n[i] > n[i + 1]){
                std::swap(n[i], n[i + 1]);
                done = false;
            }
        }
    }
}

void insertionSort(std::vector<int>& n){
    for(int i = 1; i < n.size(); ++i){
        for(int j = 0; j < i; ++j){
            if(n[j] > n[i]) {
                std::swap(n[j], n[i]);
            }
        }
    }
}

int min(std::vector<int>& n, int start){
    auto min = std::numeric_limits<int>::max();
    auto cur = -1;

    for (int i = start; i < n.size(); ++i){
        if (min > n[i]){
            min = n[i];
            cur = i;
        }
    }
    return cur;
}

void selectionSort(std::vector<int>& n){
    for (int i = 0; i < n.size(); ++i){
        int smallest = min(n,i);
        std::swap(n[i], n[smallest]);
    }
}

int partition(std::vector<int>& v, int start, int end, int pivot){
   // std::cout << "something";
    std::swap(v[pivot], v[end - 1]);
    //std::cout << "Something2";
    int less = start;
    for (int i = start; i < end - 1; ++i){

        if(v[i] <= v[end - 1]){
            std::swap(v[i], v[less]);
            ++less;
        }
    }
    std::swap(v[end - 1], v[less]);
    return less;
}

int findPivot(std::vector<int> & v, int start, int end){
    auto first = v[start];
    auto last = v[end - 1];
    auto mid = v[(start + end) / 2];

    if ((first <= last && last <= mid) || (mid <= last && last <= first)) return end - 1;
    else if ((last <= first && first <= mid) || (mid <= first && first <= last)) return start;
    else if ((first <= mid && mid <= last) || (last <= mid && mid <= first)) return (start + end) / 2;
    else return mid;
}


void quickSort(std::vector<int> & v, int start, int end){

    if(end - start <= 1) return;
    auto pivot = findPivot(v, start, end);
    pivot = partition(v, start, end, pivot);

    quickSort(v, start, pivot);
    quickSort(v, pivot + 1, end);
}

void initQSort(std::vector<int>& v){

    quickSort(v, 0, v.size());
}

void stdSort(std::vector<int>& v){
	std::sort(v.begin(), v.end());
}

void display(std::vector<int>& n){
    for(auto&& e : n){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void runN2Algo() {
	for (int i = 1; i <= 100000; i *= 10) {
	std::vector<int> a = makeVector(i);

	std::cout << "Start Bubble Sort: " << std::endl;
	auto bSortTime = timedSort<std::chrono::milliseconds>(a, bubbleSort);
	std::cout << i << std::endl;

	std::vector<int> b = makeVector(i);

	std::cout << "Start Insertion Sort: " << std::endl;
	auto iSortTime = timedSort<std::chrono::milliseconds>(b, insertionSort);
	std::cout << i << std::endl;
	}
}

void runNAlgo(){
	for(int i = 1; i <= 100000; i*=10) {
		std::vector<int> c = makeVector(i);

		std::cout << "Start Selection Sort: " << std::endl;
		auto sSortTime = timedSort<std::chrono::milliseconds>(c, selectionSort);
		std::cout << i << std::endl;
	}
}

void runLogNAlgo(){
	for(int i = 1; i <= 10000000; i*=10) {
		std::vector<int> d = makeVector(i);

		std::cout << "Start Merge Sort: " << std::endl;
		auto mSortTime = timedSort<std::chrono::milliseconds>(d, initMergeSort);
		std::cout << i << std::endl;

		std::vector<int> e = makeVector(i);

		std::cout << "Start Quick Sort: " << std::endl;
		auto qSortTime = timedSort<std::chrono::milliseconds>(e, initQSort);
		std::cout << i << std::endl;

		std::vector<int> f = makeVector(i);

		std::cout << "Start Standard Sort: " << std::endl;
		auto stdSortTime = timedSort<std::chrono::milliseconds>(f, stdSort);
		std::cout << i << std::endl;
	}
}

int main(){

	runN2Algo();
	runNAlgo();
	runLogNAlgo();

}

