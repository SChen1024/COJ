/*****************************************************************/
// 包含必须的头文件

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

/*****************************************************************/

// CPP 过程中 简单测试



class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> aux;
        int len = s.size();

        int mult = 0;
        string res = "";
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            if (c == '[')
            {
                aux.push(make_pair(mult, res));
                mult = 0;
                res = "";
            }
            else if (c == ']')
            {
                auto t = aux.top();
                aux.pop();
                string tmp = t.second;
                for (int i = 0; i < t.first; i++)
                    tmp += res;

                res = tmp;
            }
            else if (c >= '0' && c <='9')
                mult = 10 * mult + c - '0';
            else 
                res.push_back(c);
        }

        return res;
    }
};

class Solution2 {
public:
    
    // 判断字母
    bool isAlpha(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    
    // 计算I 位置 处的字符串反转
    string reverseStrI(string &s)
    {
        string res = "";
        int N = s.size();
        
        
        // 遇到左括号 标记开始, 遇到右括号之后弹出直到左括号为止
        stack<char> St;
        int level = 0;
        for(int i=0;i<N;i++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                St.push(')');
                level ++;   // 升级层
            }
            else if (ch == ')')
            {
                // 依次取出数据
                char tmpCh = St.top(); St.pop();
                string tmpStr = "";
                while(ch != tmpCh)  // 直到取出 ) 括号为止
                {
                    tmpStr += tmpCh;

                    tmpCh = St.top();
                    St.pop();
                }
                
                // 奇数层 逆转 // 值为偶数才逆转
                if(!(level&1))
                {
                    // reverse(tmpStr.begin(),tmpStr.end());
                }

                cout<<tmpStr<<endl;
                
                // 将数据重新压入栈中 调整过了顺序
                for(int j=0;j<tmpStr.size();j++)   
                {
                    St.push(tmpStr[j]);
                }
                
                // 减少 层
                level --;
            }
            else
            {
                St.push(ch);
            }
                
        }
        
        // 将st 中的数据 按照 逆序 取出 重组数据
        while(!St.empty())
        {
            char c = St.top();
            St.pop();
            res = c + res;
        }
        
        return res;

    }
    
    string reverseParentheses(string s) {
        
        // 将字符串 按照括号内部反转
        return reverseStrI(s);

        
    }
};

const int MOD = 1e9 + 7;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long best = 0;
        long long full_sum = accumulate(arr.begin(), arr.end(), 0LL);
        long long sum = 0;

        // 计算最大子区间和值
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum < 0)
                sum = 0;
            else if (sum > best)
                best = sum;
        }

        // 计算正向最大累加和
        long long max_prefix = 0, max_suffix = 0;
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            max_prefix = max(max_prefix, sum);
        }

        // 计算逆向最大累加和
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            max_suffix = max(max_suffix, sum);
        }

        // 计算最大子区间和 或者前后区间和的最大值
        if (k > 1) {
            best = max(best, max_suffix + max_prefix);
            best = max(best, max_suffix + max_prefix + (k - 2) * full_sum);
        }

        return best % MOD;
    }
};

int main(void )
{


    Solution2 s2;

    string test1 = "(abcd)",test2 = "(u(love)i)";

    cout<<s2.reverseParentheses(test2)<<endl;

    return 0;

}

