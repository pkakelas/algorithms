#include <iostream>

using namespace std;

int main() {
    int a[] = {95, 1430, 52, 12, 71, 56, 5, 10, 19, 90, 45};
    int count = sizeof(a)/sizeof(int);

    cout << endl;

    for (int i = 1; i < count; ++i) {
        int j = i;

        while (j > 0 && a[j] < a[j-1]) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << a[i] << " ";
    }

    return 0;
}
