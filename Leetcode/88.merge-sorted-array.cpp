/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // 正向开始每次都要移动很多, 逆向相当于从头开始

        int N = m+n-1;

        int i=m-1,j=n-1;
        while(j>=0)
            if(i>=0 && nums1[i] > nums2[j] )
                nums1[N--] = nums1[i--];
            else
                nums1[N--] = nums2[j--];
    }
};

