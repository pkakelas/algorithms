#include <iostream>

using namespace std;

int main() {
    int a[] = {95, 1430, 52, 12, 71, 56, 5, 10, 19, 90, 45};
    int count = sizeof(a)/sizeof(int);

    for (int i = 0; i < count - 1; ++i) {
        for (int j = count; j > i; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
