#include <stdafx.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    string  str = "", out_str = "";

    cin >> str;

    stack<char> st;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        // 循环将数据 压如 stack  当遇到左括号  判断
        string tmp_str="";
        int k_r = -1, k_l = -2;
        if (str[i] == ')')
        {
            k_r = i;
            continue;
        }
        else if (str[i] == '(')
        {
            k_l = i;

            int n = str[--i] - '0';

            for (int j = 0; j < n-1; j++)
            {
                tmp_str += str.substr(i + 2, k_r - i - 2);
            }

        }
        else
            out_str += str[i];

        out_str += tmp_str;


    }

    cout << out_str << endl;

        return 0;

}