/* -------------------------------------------------------------------------------------

* Leetcode 560. Subarray Sum = k
* ------------------------------
* Given an array of integers nums and an integer k, return the total number of subarrays 
* whose sum equals to k.
* A subarray is a contiguous non-empty sequence of elements within an array.

Ex. 
    Input: nums = [1,1,1], k = 2
    Output: 2

------------------------------------------------------------------------------------- */


// include libraries 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k){
    // HASH MAP: x the number : how many times (y) x has appeared in prefix sum 
    unordered_map<int, int> map;
    map[0]=1;

    // running prefix sum
    int prefix = 0; 
    // count of valid subarrays
    int count = 0;

    for (int x : nums){
        prefix += x;
        int need = prefix - k; //compute what we need

        cout << "x=" << x
             << " | prefix=" << prefix
             << " | need=prefix-k=" << need
             << " | map[need]=" << (map.count(need) ? map[need] : 0);

        if (map.count(need)){
            count += map[need];
            cout << " -> MATCH, count=" << count;
        }
        cout << endl;

        map[prefix]++;
        cout << "  map[" << prefix << "] now = " << map[prefix] << endl;
    }

    return count;
}

int main() {
    // Test case 1 — your array
    vector<int> nums1 = {2, 1, 4, 3, 1};
    int k1 = 3;
    cout << "Test 1: \n" << subarraySum(nums1, k1) << endl;  // expect 2

    // Test case 2 — from the problem
    vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    cout << "Test 2: \n" << subarraySum(nums2, k2) << endl;  // expect 2

    // Test case 3 — single element match
    vector<int> nums3 = {3};
    int k3 = 3;
    cout << "Test 3: \n" << subarraySum(nums3, k3) << endl;  // expect 1

    // Test case 4 — no valid subarrays
    vector<int> nums4 = {1, 2, 3};
    int k4 = 7;
    cout << "Test 4:\n " << subarraySum(nums4, k4) << endl;  // expect 0

    return 0;
}