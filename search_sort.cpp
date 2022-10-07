#include <random>
#include <iostream>

void fill_array_random(int arr[], int n, int a, int b)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dist(rng);
    }
}

void print_array(int arr[], int n, bool show_index)
{
    if (show_index == 0) {
        std::cout << "{";
        for (int i = 0; i < (n - 1); i++) 
            std::cout << arr[i] << ", ";
        std::cout << arr[n - 1] << "}\n";
    }
    else {
        std::cout << "{";
        for (int i = 0; i < (n - 1); i++) 
            std::cout << i << ": " << arr[i] << ", ";
        std::cout << n-1 << ": " << arr[n - 1] << "}\n";
        
    }
 
}

int main()
{
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    fill_array_random(arr, n, 0, 100);
    print_array(arr, n, 1);
    return 0;
}
