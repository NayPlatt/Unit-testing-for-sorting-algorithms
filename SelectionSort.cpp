#include <iostream>
#include <vector>

class SelectionSort {
    public:
        static void selectionSort(std::vector<int>& arr){
            int n = arr.size()
            for(int i =0; i < n - 1; i++){ 
                int minIndex = i; 
                for(int j = i + 1; j < n; j++){   // find min in unsorted 
                    if(arr[j] < arr[minIndex]){
                        minIndex = j; 
                    }
                }
                std::swap(Arr[minIndex], arr[i]);  //swap min with first element 
            }
        }
};