/**********************************************************************************************//**
 * @file    solition.
 *
 * @brief   ����һ��solution  �ύOJ ����, ֻ��Ҫ �����Ӧ�ĳ��򼴿�, һ���ļ����������������
 * @changelog   2019/2/11    IRIS_Chen  Created.
 *************************************************************************************************/

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////
class Solution
{
    public:

    /**********************************************************************************************
     * @fn  int bulbSwitch(int n)
     *
     * @brief   LeetCode 319 Bulb Switcher  ��������״̬ͳ��
     *
     * As we know that there are n bulbs, let's name them as 1, 2, 3, 4, ..., n.
            You first turn on all the bulbs.
            Then, you turn off every second bulb.(2, 4, 6, ...)
            On the third round, you toggle every third bulb.(3, 6, 9, ...)
            For the ith round, you toggle every i bulb.(i, 2i, 3i, ...)
            For the nth round, you only toggle the last bulb.(n)
     *
     * @author  IRIS_Chen
     * @date    2019/3/11
     *
     * @param   n   An int to process
     *
     * @return  An int
     *********************************************************************************************/

    int bulbSwitch(int n) {

        // ���������n �����ж� ��1-n��ÿһ�����ݵ�����, ��ʼ״̬��0  ����1 ֮��ȫ����Ϊ1 
        // ��ʼ״̬��0 ���������β����Ż������� , ����һ����, �ᾭ��ÿ�� �����ı���, ������Ϊż��ʱ�ض������  ,
        // ֻ����������������������  ��ô ֻ��ƽ������������ , ���Լ���1-n ���� ����ȡ�� 
        

        return sqrt(n);

    }

    /**********************************************************************************************
     * @fn  int flipLights(int n, int m)
     *
     * @brief   Flip lights LeetCode 672 
     *     * There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

            Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

            Flip all the lights.
            Flip lights with even numbers.
            Flip lights with odd numbers.
            Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
     *
     * @author  IRIS_Chen
     * @date    2019/3/11
     *
     * @param   n   An int to process
     * @param   m   An int to process
     *
     * @return  An int
     *********************************************************************************************/

    int flipLights(int n, int m) {

    }











};


#endif //SOLUTION_H
