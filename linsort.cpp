#include <iostream>
using namespace std;
int search(int arr[], int n, int x, int result[]) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			result[r] = i;
			r++;
		}
	}
	if (r > 0)
		return r;
	else {
		return -1;
	}
	
}
int main()
{
	int arr[] = { 1, 3 , 24 , 345, 345, 62, 697, 3546, 3, 23, 57, 36, 235, 86, 234 };
	int result[128];
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 3;
	int a = search(arr, n, x, result);
	if (a > 0)
		cout << a;
	else {
		cout << "there is no result";
	}
}
