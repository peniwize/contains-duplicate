/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/contains-duplicate/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

/*
    Given an integer array nums, return true if any value appears at least 
    twice in the array, and return false if every element is distinct.

    Constraints:

        * 1 <= nums.length <= 105
        * -109 <= nums[i] <= 109

    Example 1:

        Input: nums = [1,2,3,1]
        Output: true

    Example 2:

        Input: nums = [1,2,3,4]
        Output: false

    Example 3:

        Input: nums = [1,1,1,3,3,4,3,2,4,2]
        Output: true
*/
class Solution {
public:
    /*
        Time = O(n)
        Space = O(n)
    */
    bool containsDuplicate_hashTable(vector<int>& nums) {
        unordered_map<int, int> frequencies{};
        for (auto const num : nums) {
            if (1 < ++frequencies[num]) {
                return true;
            }
        }
        return false;
    }

    /*
        Time = O(n)
        Space = O(n)
    */
    bool containsDuplicate_hashSet(vector<int>& nums) {
        unordered_set<int> frequencies{};
        for (auto const num : nums) {
            if (frequencies.contains(num)) {
                return true;
            }
            frequencies.insert(num);
        }
        return false;
    }

    /*
        Time = O(n*log2(n))
        Space = O(1)
    */
    bool containsDuplicate_sort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int lastNum = ~nums[0];
        for (auto const num : nums) {
            if (num == lastNum) {
                return true;
            }
            lastNum = num;
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        //return containsDuplicate_hashTable(nums);
        return containsDuplicate_hashSet(nums);
        //return containsDuplicate_sort(nums);
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    { // New scope.
        auto nums = vector<int>{1,2,3,1};
        CHECK(Solution{}.containsDuplicate(nums));
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 2")
{
    cerr << "Case 2" << '\n';
    { // New scope.
        auto nums = vector<int>{1,2,3,4};
        CHECK(!Solution{}.containsDuplicate(nums));
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

TEST_CASE("Case 3")
{
    cerr << "Case 3" << '\n';
    { // New scope.
        auto nums = vector<int>{1,1,1,3,3,4,3,2,4,2};
        CHECK(Solution{}.containsDuplicate(nums));
        auto const start = std::chrono::steady_clock::now();
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
