#include <iostream>
using namespace std;

int binary_search(int arr[], int l, int r, int x){
int mid;
    while(r>=l){
		if (r >= l) {
			mid = l + (r - l) / 2;
			if (arr[mid] == x) {
				return mid;
				break;
			}
			if (arr[mid] > x)
				r = mid - 1;
			else {
				l = mid + 1;
			}}
		}
	 return -1;
    
}
int main()
{
	int arr[] = { 1, 2, 2, 3, 5, 6, 7, 8, 9, 10, 13, 14, 16, 17, 365, 378, 487, 4679, 37646, 358635};
	int l = 0;
	int r = sizeof(arr) / sizeof(arr[0]);
	int x = 3;
	int a = binary_search(arr, l, r, x);
	if (a > 0)
		cout << a;
	else {
		cout << "there is no result";
	}
}
