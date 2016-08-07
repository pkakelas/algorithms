#include <iostream>

using namespace std;

int main() {
    int a[] = {95, 1430, 52, 12, 71, 56, 5, 10, 19, 90, 45};
    int count = sizeof(a)/sizeof(int);

    for (int i = 0; i < count - 1; ++i) {
        int minIndex = i;
        int minValue = a[i];

        for (int j = i + 1; j < count; ++j) {
            if (minValue > a[j]) {
                minValue = a[j];
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }

    for (int i = 0; i < count; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
