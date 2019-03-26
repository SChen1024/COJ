#pragma once

/**********************************************************************************************//**
 * @class   Solution 03_LongestSubString.cc Code\LeetCode\03_LongestSubString.cc
 *
 * @brief   A solution. ��ַ�������˼·
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

        // ���� �����ֵΪmax , ʹ��˫ָ�����
        int longl = -1, l = 0, r = 0;

        // ��ʹ��hash ����һ�����ұ�, �����ַ�����ΪASCII, ��������λ��ΪASCIIֵ
        int table[128] = { 0 };

        if (s.length() <= 1)
            return s.length();

        //std::cout<<s.length()<<std::endl;



        // ȡ������, ����Ѿ����� ����Ӧλ�õ�ֵȡ�������Ǹ��ַ���λ��
        // ���³���ֵ, ��ԭ����������ȥ, ����ֵ����һ��ƫ��ֵ, ��һ��������ɴ������0 ���ִ���
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





