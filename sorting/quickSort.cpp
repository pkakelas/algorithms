#include <iostream>

using namespace std;

void sort(int arr[], int begin, int end) {
        for (int i = 0; i < 11; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl << "=====================================" << endl;

		if (end > begin + 1) {
			int piv = arr[begin];
            cout << "Pivot = " << piv << endl;
			int l = begin + 1;
			int r = end;
            cout << "Going to if from " << begin << " to " << end << endl;

			while (l < r) {
				if (arr[l] <= piv) {
					l++;
				}
				else {
                    --r;
					swap(arr[l], arr[r]);
				}
			}

            --l;
			swap(arr[l], arr[begin]);
			sort(arr, begin, l);
			sort(arr, r, end);
		}
}
int main() {
    int a[] = {95, 1430, 52, 12, 71, 56, 5, 10, 19, 90, 45};
    int count = sizeof(a)/sizeof(int);

	sort(a, 0, count);

    for (int i = 0; i < count; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
