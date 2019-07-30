
/***
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> towSum(vector<int> &nums, int target)
{

    unordered_map<int, int> m;
    vector<int> result;
    size_t len = nums.size();

    for (int i = 0; i < len; i++)
    {
        int n = nums[i];
        int diff = target - n;

        if (m.find(n) == m.end())
        {
            m.insert({diff, i});
        }
        else
        {
            result.push_back((m[n]));
            result.push_back(i);
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> result = towSum(nums, target);

    return 0;
}