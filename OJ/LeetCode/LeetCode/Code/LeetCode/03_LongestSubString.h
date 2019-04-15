#pragma once

/**********************************************************************************************//**
 * @class   Solution 03_LongestSubString.cc Code\LeetCode\03_LongestSubString.cc
 *
 * @brief   A solution. 最长字符串解体思路
 *
 * @author  IRIS_Chen
 * @date    2019/3/25
 *************************************************************************************************/
*
#include <iostream>
#include <string.h>
#include <fstream>
#include <>

using namespace std;

class Solution
{
    public:
    int lengthOfLongestSubstring(string s) {

        // 设置 最长长度值为max , 使用双指针计算
        int longl = -1, l = 0, r = 0;

        // 不使用hash 设置一个查找表, 设置字符串均为ASCII, 设置数组位置为ASCII值
        int table[128] = { 0 };

        if (s.length() <= 1)
            return s.length();

        //std::cout<<s.length()<<std::endl;



        // 取出数据, 如果已经存在 将对应位置的值取出来就是该字符的位置
        // 更新长度值, 将原本的数据消去, 计算值计算一个偏移值, 第一个数据造成错误避免0 出现错误
        while (r < s.length())
        {
            //std::cout<<s[r]<<":"<<(int)s[r]<<":"<<l<<":"<<r<<std::endl;

            //std::cout<<table[(int)s[r]]<<std::endl;

            if (table[(int)s[r]] != 0)
            {
                l = table[(int)s[r]] - 100;


                //std::cout<<l<<":"<<r-l<<":"<<longl<<std::endl;
                longl = max(longl, r - l);

                table[(int)s[r]] = 0;
            }

            table[(int)s[r]] = 100 + r;
            r++;



        }
        if (longl == -1)
            longl = s.length();


        return longl;

    }

    string stringToString(string input) {
        assert(input.length() >= 2);
        string result;
        for (int i = 1; i < input.length() - 1; i++)
        {
            char currentChar = input[i];
            if (input[i] == '\\')
            {
                char nextChar = input[i + 1];
                switch (nextChar)
                {
                    case '\"': result.push_back('\"'); break;
                    case '/': result.push_back('/'); break;
                    case '\\': result.push_back('\\'); break;
                    case 'b': result.push_back('\b'); break;
                    case 'f': result.push_back('\f'); break;
                    case 'r': result.push_back('\r'); break;
                    case 'n': result.push_back('\n'); break;
                    case 't': result.push_back('\t'); break;
                    default: break;
                }
                i++;
            }
            else
            {
                result.push_back(currentChar);
            }
        }
        return result;
    }


    int main() {
        string line;
        while (getline(cin, line))
        {
            string s = stringToString(line);

            int ret = Solution().lengthOfLongestSubstring(s);

            string out = to_string(ret);
            cout << out << endl;
        }
        return 0;
    }
};





