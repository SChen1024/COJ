// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����ÿһ������

//  ���ֲ��ҵ�����һ��λ���������ֵ
// ������ֵ���������� ������
// �Ҳ෵���Ҳ��ֵ
int binarySearch(std::vector<int> &vec, int l, int r, int data, int flg)
{
    int mid = l + (r - l) / 2;
    // ��ʾ��Ѱ����ֵ�����
    if (flg)
    {
        while (r > l)
        {
            if (vec[mid] >= data)
                r = mid;
            else
                l = mid + 1;

            mid = l + (r - l) / 2;
        }
    }
    else
    {
        while (r > l)
        {
            if (vec[mid] > data)
                r = mid;
            else
                l = mid + 1;

            mid = l + (r - l) / 2;
        }
    }

    return mid;

}


#define LOCAL 1



int main() {
    int T = 0;
#if LOCAL 
    T = 2;
#else
    cin >> T;
#endif
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ":" << endl;

        // ���� n m
        int n = 0, m = 0;
#if LOCAL 
        n = 10, m = 5;
#else
        cin >> n >> m;
#endif


#if LOCAL

        std::vector<int> vecN = { 0,1,2,3,4,5,6,7,8,9 };
        std::vector<int> vecL = { 0,10,-5,7,100 };
        std::vector<int> vecR = { 5,20,-3,7,105 };

#else
        // ��ȡ����
        std::vector<int> vecN(n);
        for (int j = 0; j < n; j++)
            cin >> vecN[i];
#endif
        // ����
        sort(vecN.begin(), vecN.end());


        // ���� m������
        int left = 0, right = 0;
        for (int j = 0; j < m; j++)
        {
#if LOCAL
            left = vecL[j];
            right = vecR[j];
#else
            cin >> left >> right;

#endif
            // �ж�����ֵ�Ĵ�С �������䲻����
            if (left > right)
            {
                swap(left, right);
            }

            // �ֱ��������������в����ʺϵĲ���λ��, �����ֵ���� ��Ŀ

            int tmp_l = binarySearch(vecN, 0, vecN.size() - 1, left, 1);
            int tmp_r = binarySearch(vecN, 0, vecN.size() - 1, right, 0);

            cout << "L:" << left << ":" << tmp_l << "r:" << right << ":" << tmp_r << "//" << vecN.size() << endl;
            cout << tmp_r - tmp_l << endl;

        }


    }
}