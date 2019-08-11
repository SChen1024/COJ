

class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        // 将所有的1 交换过去
        
        int cnt_1 = 0;
        
        // 计数 1
        for(int i=0;i<data.size();i++)
            if(data[i])
                cnt_1 ++;
        
        int max_1 = 0,cnt = 0;
        
        // 先计算第一个窗口的 1 的值
        for(int i=0;i<cnt_1;i++)
        {
            if(data[i] ==1)
                cnt ++;
        }
        
        // 找到 区间含有最多1的 窗口内的1 值

        // 找到后续 窗口内最多的 1 的区间
        for(int i=1;i<=data.size() - cnt_1;i++)
        {
            // 一次判断 加入的和去除的位置 进行 加减计算
            if(data[i-1])
                cnt --;
            if(data[i+cnt_1-1])
                cnt ++;
            
            // 记录最大值
            max_1 = max(max_1,cnt);
                
        }
        
        return cnt_1 - max_1;
        
        

		
int cnt_1 = 0; 

// find total number of all 1's in the dataay 
for (int i = 0; i < data.size(); i++) { 
	if (data[i] == 1) 
	cnt_1++; 
} 

int count_ones = 0, maxOnes; 

// Find 1's for first subdataay of length cnt_1 
for(int i = 0; i < cnt_1; i++){ 
	if(data[i] == 1) 
	count_ones++; 
} 
	
maxOnes = count_ones; 

for (int i = 1; i <= data.size()-cnt_1; i++) { 

	if (data[i-1] == 1) 
		count_ones--; 

	if(data[i+cnt_1-1] == 1) 
		count_ones++; 
	
	if (maxOnes < count_ones) 
	maxOnes = count_ones; 
} 



return  cnt_1 - maxOnes; ; 




    }
};