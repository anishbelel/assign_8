#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(const vector<int>& arr) {
    vector<int> squares;
    for (int num : arr) {
        squares.push_back(num * num);
    }

    sort(squares.begin(), squares.end());

    return squares;
}

int main() {
    int n;
    cout << "Enter the size of the vector (1 < size < 101): ";
    cin >> n;

    if (n < 2 || n > 100) {
        cout << "Invalid size. Please enter a size between 2 and 100." << endl;
        return 1;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers in increasing order: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> squares = sortedSquares(arr);

    cout << "Array of squares sorted in increasing order: ";
    for (int num : squares) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
