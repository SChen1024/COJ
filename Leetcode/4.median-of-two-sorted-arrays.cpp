/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    // 找到 两个数组的第K个数字
    int findKth(vector<int> &nums1,int i,vector<int> &nums2, int j, int k)
    {
        // 如果k 超过其中一个的区间 则使用另一个数组
        if(i>=nums1.size())
            return nums2[j+k-1];
        if(j>= nums2.size()) 
            return nums1[i+k-1];
        
        if(k==1) 
            return min(nums1[i],nums2[j]);
        
        int mid1 = (i+k/2-1 < nums1.size() ) ? nums1[i+k/2-1]:INT_MAX;
        int mid2 = (j+k/2-1 < nums2.size() ) ? nums1[j+k/2-1]:INT_MAX;

        if(mid1<mid2)
            return findKth(nums1,i+k/2,nums2,j,k-k/2);
        else {
            return findKth(nums1,i,nums2,j+k/2,k-k/2);
        }
        


    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int left = (nums1.size()+nums2.size()+1)/2, right = (nums1.size()+nums2.size()+2)/2;

        return (findKth(nums1,0,nums2,0,left)+findKth(nums1,0,nums2,0,right))/2.0;

    }
};

