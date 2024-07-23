/*
Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
思想：
1. 两个有序数组的中位数，可以转化为求两个有序数组中第k小的数的问题。
2. 假设两个有序数组的长度分别为m和n，求第k小的数，可以分别在两个数组中找到第k/2小的数，比较这两个数的大小，较小的那个数左边的数都不可能是第k小的数，可以直接排除掉。
3. 如果某个数组的第k/2小的数比另一个数组的第k/2小的数小，那么这个数组的前k/2个数都不可能是第k小的数，可以直接排除掉。
4. 递归求解，直到k=1或者其中一个数组为空。
5. 如果其中一个数组为空，直接返回另一个数组的第k小的数。
6. 如果k=1，返回两个数组的第一个数中较小的那个。

时间复杂度：O(log(min(m, n)))
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
        int m = nums1.size(), n = nums2.size();
        if (m > n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i])
            {
                iMin = i + 1;
            }
            else if (i > iMin && nums1[i - 1] > nums2[j])
            {
                iMax = i - 1;
            }
            else
            {
                int maxLeft = 0;
                if (i == 0)
                {
                    maxLeft = nums2[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = nums1[i - 1];
                }
                else
                {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                if ((m + n) % 2 == 1)
                {
                    return maxLeft;
                }
                int minRight = 0;
                if (i == m)
                {
                    minRight = nums2[j];
                }
                else if (j == n)
                {
                    minRight = nums1[i];
                }
                else
                {
                    minRight = min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
