#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTripletsWithSumX(const vector<int>& nums, int x, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (left != k && right != k && sum == x) {
                count++;
                left++;
                right--;
                // Skip duplicates
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            } else if (sum < x) {
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    int n, x, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 2 || n > 100) {
        cout << "Invalid size. Please enter a positive integer between 3 and 100." << endl;
        return 1;
    }

    vector<int> nums(n);

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target sum (x): ";
    cin >> x;

    cout << "Enter the index (k) to exclude from triplets: ";
    cin >> k;

    int tripletCount = countTripletsWithSumX(nums, x, k);
    cout << "Number of triplets with sum " << x << " and excluding index " << k << ": " << tripletCount << endl;

    return 0;
}
