// LeetCode.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
// �Ƚ������ַ��� ����ascii ���� ���ǰ�����ĸ˳������? ?
// a > B ?? 
// ���ǰһ���� ����true ���򷵻� false
bool str_compare(std::string s1, std::string s2)
{
    // ������ǰ���˱Ƚ�, ����ǰ���ַ�������һ��
    int MASK = 0xFFDF;


    for (int i = 0; i < s1.size(); i++)
    {
        // cout << (s1[i] & MASK) <<":"<< (s2[i] & MASK)<<" ";
        // �����Ϊ������ ��������Ƚ�
        if ((s1[i]) == (s2[i]))
            continue;
        else if ((s1[i]) < (s2[i]))
            return false;
        else
            return true;

    }

    return true;

}



int main() {

    int n = 0;
    string str = "";
    vector<string> vecs;

    cin >> n;

    // ������ݶ�  ���� ���� ������  ���Է�Ϊ�����
    for (int i = 0; i < n; i++)
    {
        string tmps = "";
        cin >> tmps;

        if (tmps.size() < 9)
            vecs.push_back(tmps);
        else
        {
            for (int j = 0; j < tmps.size() / 8+1; j++)
            {
                vecs.push_back(tmps.substr(8 * j, 8));
            }
        }


    }
    //cout << n << ":" << vecs.size() << endl;

    //cout << str_compare("a", "A") << endl;

    //cout << str_compare("0", "a") << endl;

    // ����ÿ�������������ĸ������
    for (int i = 0; i < vecs.size(); i++)
    {
        if (vecs[i].size() > 8)
        {
            cerr << "�������" << endl;
        }
        else if (vecs[i].size() < 8)
        {
            for (int j = vecs[i].size(); j <= 8; j++)
                vecs[i] += "0";
        }



    }

    for (int i = 0; i < vecs.size(); i++)
    {
        for (int j = i + 1; j < vecs.size(); j++)
        {
            if (str_compare(vecs[i], vecs[j]))
            {
                string tmp = vecs[i];
                vecs[i] = vecs[j];
                vecs[j] = tmp;
            }
        }
    }


    for (int i = 0; i < vecs.size(); i++)
    {
        cout << vecs[i] << " ";
    }

    return 0;

}