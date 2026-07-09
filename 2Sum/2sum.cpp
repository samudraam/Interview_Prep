/* -------------------------------------------------------------------------------------

* Leetcode 167. Two Sum II - Input Array Is Sorted
* ------------------------------
* Given a 1-indexed array of integers numbers that is already sorted in non-decreasing 
* order, find two numbers such that they add up to a specific target number. 
* Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
* Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array 
* [index1, index2] of length 2. is a contiguous non-empty sequence of elements within an array.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

------------------------------------------------------------------------------------- */


// include libraries 
#include <iostream>
#include <vector>

using namespace std;

// * twoSum(nums, t)
vector<int> twoSum(vector<int>& numbers, int target) {
    // Already Sorted Non-decending
    int left = 0;
    int right = numbers.size() - 1;

    //declare vector to store values
    vector<int> valid;


    while(left < right){
        int sum = numbers[left] + numbers[right];
        //! case 1: num[l] + numbers[r] = target 
        if (sum == target){
            valid.push_back(left + 1);
            valid.push_back(right + 1);
            return valid;
        }
        //! case 2: num[l] + numbers[r] > target   
        // *  sum is too small, move left up
        else if (sum < target){
            left++;
        }
        //! case 3: num[l] + numbers[r] < target  
        // *  sum is too small, move right down
        else {
            right--;
        }
    }

    return valid;
    
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int k1 = 9;

    cout << "Test 1: ";
    vector<int> result = twoSum(nums1, k1);
    if (!result.empty()) {
        printVector(result);  // Use the helper function to print the vector
    } else {
        cout << "No solution found";
    }
    cout << endl;

    return 0;
}