#include <iostream>
#include <vector>
using namespace std;

int countPairsWithAbsoluteSum(const vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];
        int absSum = abs(sum);

        if (absSum == x) {
            count++;
            left++;
            right--;
            // Skip duplicates
            while (left < right && arr[left] == arr[left - 1])
                left++;
            while (left < right && arr[right] == arr[right + 1])
                right--;
        } else if (absSum < x) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid size. Please enter a positive integer between 1 and 100." << endl;
        return 1;
    }

    vector<int> arr(n);

    cout << "Enter " << n << " integers (sorted in increasing order): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the target absolute sum (x): ";
    cin >> x;

    int pairCount = countPairsWithAbsoluteSum(arr, x);
    cout << "Number of unique pairs with absolute sum " << x << ": " << pairCount << endl;

    return 0;
}
