// Given a string, find the length of the longest substring without repeating characters.
// For example, the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <unordered_map>
#include <string>
#include <algorithm>
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int res = 0;
        std::unordered_map<char, int> m;
        size_t size = s.size();
        for (int i = 0, j = 0; i < size; i++)
        {
            char c = s[i];
            if (m.find(c) != m.end())
            {
                j = std::max(m[c] + 1, j);
            }
            res = std::max(res, i - j + 1);
            m[c] = i;
        }
        return res;
    }
};

int main()
{
    std::string s = "tmmzuxt";
    int res = Solution().lengthOfLongestSubstring(s);
    return 0;
}