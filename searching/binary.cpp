#include <iostream>

using namespace std;

int bsearch(int array[], int left, int right, int value) {
    int middle = (right + left) / 2;

    if (left > right) {
        return -1;
    }
    if (array[middle] == value) {
        return middle;
    }
    else if (array[middle] > value) {
        bsearch(array, left, middle - 1, value);
    }
    else {
        bsearch(array, middle + 1, right, value);
    }
}

int main() {
    int array[] = {-3432, -1043, -20,-1 , 1, 3, 5, 6, 7, 9, 15, 200, 4053, 100000};
    int left = 0, right = (sizeof array / sizeof array[0]);
    int value = 7;

    while (left <= right) {
        int middle = (right + left) / 2;
        if (array[middle] == value) {
            cout << middle << endl;
            break;
        }
        else if (array[middle] > value) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }

    cout << bsearch(array, left, right, value) << endl;

    return 0;
}
