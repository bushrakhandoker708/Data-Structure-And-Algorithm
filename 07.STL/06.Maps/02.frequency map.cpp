// LEETCODE: Count Smaller Numbers Than Current (136-style frequency idea)

/*
    Problem:
    Given an array nums, for each nums[i], find how many numbers in the array are smaller than it.

    Key Idea:
    Instead of comparing each pair (O(n^2)), we use a frequency map + prefix sum.

    ------------------------------------------------------------
    WHY FREQUENCY MAP WORKS
    ------------------------------------------------------------

    We only care about VALUES, not positions.

    Step 1: Build frequency map
        freq[x] = how many times x appears in nums

    Example:
        nums = [8,1,2,2,3]

        freq:
            1 → 1
            2 → 2
            3 → 1
            8 → 1

    ------------------------------------------------------------
    Step 2: Sort unique values
        sorted unique values = [1, 2, 3, 8]

    ------------------------------------------------------------
    Step 3: Build prefix count
        prefix[x] = number of elements strictly smaller than x

    Compute cumulatively:

        value : freq : prefix result
        ----------------------------
        1     : 1    : 0
        2     : 2    : 1
        3     : 1    : 3
        8     : 1    : 4

    ------------------------------------------------------------
    STEP 4: Answer queries
        For each nums[i], answer = prefix[nums[i]]

    ------------------------------------------------------------
    TIME COMPLEXITY:
        - Building freq: O(n)
        - Sorting unique values: O(k log k), k ≤ 101
        - Prefix computation: O(k)
        - Query: O(1) each

    Overall: O(n + k log k)

    ------------------------------------------------------------
    KEY INSIGHT:
        We convert:
            "pairwise comparison problem"
        into:
            "value compression + prefix sum problem"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: frequency count
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: extract and sort unique values
        vector<int> values;
        for (auto &p : freq) {
            values.push_back(p.first);
        }
        sort(values.begin(), values.end());

        // Step 3: build prefix map
        unordered_map<int, int> prefix;
        int runningSum = 0;

        for (int v : values) {
            prefix[v] = runningSum;
            runningSum += freq[v];
        }

        // Step 4: build answer
        vector<int> ans;
        for (int x : nums) {
            ans.push_back(prefix[x]);
        }

        return ans;
    }
};