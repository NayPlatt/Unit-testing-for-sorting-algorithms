#include <iostream>
#include <vector>
#include <cassert>  
#include <chrono>

class SelectionSort {
public:
    static void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[minIndex], arr[i]);
        }
    }
};

// Positive Case: Regular sorting of an unsorted array
void testPositiveCase() {
    std::vector<int> arr = { 5, 3, 8, 6, 2, 7, 4, 1 };
    SelectionSort::selectionSort(arr);
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8 };
    assert(arr == expected);  // Check if the result is whats expected
    std::cout << "Positive case passed!" << std::endl;
}
//Negative Case: Out of Range Numbers 
void testArrayWithLargeNegativeValues() {
    std::vector<int> arr = { -1000, -5, -200, -3, -10 };
    try {
        SelectionSort::selectionSort(arr);  // Negative values should be handled correctly
        std::cout << "Array with large negative values passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Array with large negative values failed: " << e.what() << std::endl;
    }
}

// Performance Case: Test sorting of a large array
void testPerformanceCase() {
    std::vector<int> arr(10000);
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
   
    auto start = std::chrono::high_resolution_clock::now();
    SelectionSort::selectionSort(arr);
    auto end = std::chrono::high_resolution_clock::now();
   
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting time for 10,000 elements: " << duration.count() << "ms\n";
   
    // Check that sorting is reasonably fast
    assert(duration.count() < 2000);
    std::cout << "Performance case passed!" << std::endl;
}

// Boundary Case: Empty array
void testEmptyArray() {
    std::vector<int> arr = {};
    SelectionSort::selectionSort(arr);
    std::vector<int> expected = {};
    assert(arr == expected);  // Empty array should remain empty
    std::cout << "Empty array test passed!" << std::endl;
}

// Boundary Case: Single-element array
void testSingleElementArray() {
    std::vector<int> arr = {5};
    SelectionSort::selectionSort(arr);
    std::vector<int> expected = {5};
    assert(arr == expected);  // Single element array should remain unchanged
    std::cout << "Single element array test passed!" << std::endl;
}

// Boundary Case: Already sorted array
void testAlreadySortedArray() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    SelectionSort::selectionSort(arr);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(arr == expected);  // Sorted array should remain the same
    std::cout << "Already sorted array test passed!" << std::endl;
}

// Boundary Case: Reverse sorted array
void testReverseSortedArray() {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    SelectionSort::selectionSort(arr);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(arr == expected);  // Reverse sorted array should be sorted
    std::cout << "Reverse sorted array test passed!" << std::endl;
}

// Idempotency Case: Sorting twice should give the same result
// this ones long to figure out why it was failing 
void testIdempotencyCase() {
    std::vector<int> arr = {1, 5, 3, 2, 4};
    std::vector<int> arr2 = arr;  // Make a deep copy of arr

    std::cout << "Before sorting:\n";
    std::cout << "arr: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\narr2: ";
    for (int num : arr2) std::cout << num << " ";
    std::cout << std::endl;

    // First sort
    SelectionSort::selectionSort(arr);

    std::cout << "After first sort:\n";
    std::cout << "arr: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\narr2: ";
    for (int num : arr2) std::cout << num << " ";
    std::cout << std::endl;

    // After the first sort, arr is sorted, so arr2 must also match arr
    arr2 = arr;  // Update arr2 to reflect the sorted state

    // Second sort (arr should remain the same after sorting twice)
    SelectionSort::selectionSort(arr);

    std::cout << "After second sort:\n";
    std::cout << "arr: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\narr2: ";
    for (int num : arr2) std::cout << num << " ";
    std::cout << std::endl;

    // Assert that arr and arr2 are the same after the second sort
    assert(arr == arr2);  // Sorting the same array twice should not change the result
    std::cout << "Idempotency case passed!" << std::endl;
}


int main() {
    // Running all test
    testPositiveCase();
    testArrayWithLargeNegativeValues();
    testEmptyArray();
    testSingleElementArray();
    testAlreadySortedArray();
    testReverseSortedArray();
    testIdempotencyCase();
    testPerformanceCase();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
