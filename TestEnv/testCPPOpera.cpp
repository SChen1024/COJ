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


int a, b;
void fun()
{
    a = 100;
    b = 200;
}
main()
{
    int a = 5, b = 7;
    fun();
    printf(" % d % d / n", a, b);
}


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