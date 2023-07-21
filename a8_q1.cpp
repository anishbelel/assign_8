#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int i = 0, j = 0;

    vector<int> mergedArray;

    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    while (i < m) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    while (j < n) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    int m, n;
    cout << "Enter the size of arr1: ";
    cin >> m;
    cout << "Enter the size of arr2: ";
    cin >> n;

    vector<int> arr1(m);
    vector<int> arr2(n);

    cout << "Enter " << m << " integers for arr1 (sorted in increasing order): ";
    for (int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter " << n << " integers for arr2 (sorted in increasing order): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    cout << "Merged Sorted Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
