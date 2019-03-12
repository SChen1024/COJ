/**********************************************************************************************//**
 * @file    solition.
 *
 * @brief   定义一个solution  提交OJ 程序, 只需要 添加相应的程序即可, 一个文件解决环境配置问题
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
     * @brief   LeetCode 319 Bulb Switcher  灯泡亮灭状态统计
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

        // 对于输入的n 首先判断 从1-n的每一个灯泡的亮灭, 初始状态是0  经过1 之后全部变为1 
        // 初始状态是0 经过奇数次操作才会变成亮的 , 对于一个数, 会经历每个 因数的遍历, 当因数为偶数时必定是灭的  ,
        // 只有奇数因数的数才是亮的  那么 只有平方数才是亮的 , 所以计算1-n 则是 开方取整 
        

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
