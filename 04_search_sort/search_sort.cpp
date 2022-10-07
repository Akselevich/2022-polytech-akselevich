#include <iostream>
#include <random>
#include <chrono>

void fill_array_random(uint8_t arr[], int n, int a, int b)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dist(rng);
    }
}
void swap(uint8_t arr[], int idx_a, int idx_b)
{
    int temp = arr[idx_a];
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;
}

int partition(uint8_t arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr, pivotIndex, start);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quick_sort(uint8_t arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}
void selection_sort(uint8_t arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr, i, min_index);
        }
    }
}
int chronograph(uint8_t arr[], int start, int end, bool type) {
    if (type == 1) {
        std::chrono::high_resolution_clock::time_point p1 = std::chrono::high_resolution_clock::now();
        quick_sort(arr, start, end);
        std::chrono::high_resolution_clock::time_point p2 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(p2 - p1).count();
    }
    else {
        std::chrono::high_resolution_clock::time_point p1 = std::chrono::high_resolution_clock::now();
        selection_sort(arr, end - start);
        std::chrono::high_resolution_clock::time_point p2 = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(p2 - p1).count();
    }

}
int main() {
    int size = 1000000;
    uint8_t* arr = new uint8_t[size];
    fill_array_random(arr, size, 0, 255);
    for (int i = 10; i < size; i *= 10)
        std::cout << i * 10 << ": ss (" << chronograph(arr, 0, i * 10, 0) * 0.000001 << "), qs (" << chronograph(arr, 0, i * 10, 1) * 0.000001 << ")\n";
    delete[] arr;
}
