// There are two sorted arrays A and B of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#include <vector>
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (!size1 && !size2)
        {
            return 0;
        }
        if (size1 > size2)
        {
            return findMedianSortedArraysHelper(nums1, size1, 0, size1 - 1, nums2, size2, 0, size2 - 1);
        }
        else
        {
            return findMedianSortedArraysHelper(nums2, size2, 0, size2 - 1, nums1, size1, 0, size1 - 1);
        }
    };

private:
    double findMedianSortedArraysHelper(vector<int> &nums1, int size1, int low1, int high1, vector<int> &nums2, int size2, int low2, int high2)
    {
        int mid1 = low1 + (high1 - low1) / 2;
        int numLessThanMid1 = binarySearch(nums2, low2, high2, nums1[mid1]);
        int computed = mid1 + numLessThanMid1;
        int sum = size1 + size2;
        int target = sum / 2;
        if (computed == target)
        {
            if (sum % 2)
            {
                return nums1[mid1];
            }
            int pre;
            if (mid1 > 0 && numLessThanMid1 > 0)
            {
                pre = MAX(nums1[mid1 - 1], nums2[numLessThanMid1 - 1]);
            }
            else if (mid1 > 0)
            {
                pre = nums1[mid1 - 1];
            }
            else
            {
                pre = nums2[numLessThanMid1 - 1];
            }
            return (nums1[mid1] + pre) / 2.0;
        }
        if (computed > target)
        {
            high1 = mid1 - 1;
            high2 = numLessThanMid1 - 1;
        }
        if (computed < target)
        {
            low1 = mid1 + 1;
            low2 = numLessThanMid1;
        }

        if (high1 - low1 < high2 - low2)
        {
            return findMedianSortedArraysHelper(nums2, size2, low2, high2, nums1, size1, low1, high1);
        }
        else
        {
            return findMedianSortedArraysHelper(nums1, size1, low1, high1, nums2, size2, low2, high2);
        }
    };
    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        while (low <= high)
        {
            int middle = low + (high - low) / 2;
            int n = nums[middle];
            if (n == target)
            {
                return middle;
            }
            if (n > target)
            {
                high = middle - 1;
            }
            if (n < target)
            {
                low = middle + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> v1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4};
    vector<int> v2 = {1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    double res = Solution().findMedianSortedArrays(v1, v2);

    return 0;
}
