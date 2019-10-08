class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // 计算对应位置的字符串 ASCII差值, 
        // 然后转换为背包问题
        
        int N = s.size();
        vector<int> vec(N,0);
        for(int i=0;i<N;i++) {
            vec[i] = abs(s[i]-t[i]);     // 计算 单独值           
            // vec[i] = vec[i-1] + abs(s[i]-t[i]);     // 计算前缀和数组

        }
        
        cout<<CoutVec(vec)<<endl;

        // 使用双指针处理最大子区间长度
        int l=0, r=0;
        int max_len = 0;
        int cur_sum = vec[0];

        // 小于 左侧累加, // 等于 返回长度 // 大于计算长度减1 
        while (r < N) {
             if(maxCost < vec[r]) {
                max_len = max(max_len,r-l);
                l = r++;
                continue;
            }
            if(cur_sum < maxCost) {
                r ++;
                if(r == N)  break;
                cur_sum  += vec[r];
            } else {
                if(cur_sum == maxCost) {
                    max_len = max(max_len,r-l+1);
                } else {
                    max_len = max(max_len,r-l);
                }
                cur_sum -= vec[l++];
            }

        }
        return max_len;
        
    }
};