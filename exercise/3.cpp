/*
Longest Substring Without Repeating Characters
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    // 思想：滑动窗口，start指向当前子串的起始位置，dict存储字符上一次出现的位置，遍历字符串，如果字符上一次出现的位置在start之后，则更新start，更新maxLen。
    int lengthOfLongestSubstring(string s) {
        // dict: 存储字符上一次出现的位置
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        // 遍历字符串
        for (int i = 0; i < s.size(); i++) {
            // 如果字符上一次出现的位置在start之后，则更新start
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};