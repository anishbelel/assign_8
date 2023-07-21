#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

bool hasPairWithSum(const vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == x) {
            return true;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers (sorted in increasing order): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the target sum (x): ";
    cin >> x;

    bool foundPair = hasPairWithSum(arr, x);
    cout << (foundPair ? "Yes" : "No") << endl;

    return 0;
}
