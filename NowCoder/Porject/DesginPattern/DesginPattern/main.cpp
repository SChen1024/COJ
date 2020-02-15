/**
 * @file    main.cpp.
 *
 * @brief   Implements the main class
 * @copyright SChen00 2019
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using std::cout;
using std::endl;

/*****************************************************************/

/**
 * @fn  int main(void)
 *
 * @brief   CPP 过程中 简单测试
 *
 * @author  IRIS_Chen
 * @date    2019/8/26
 *
 * @return  Exit-code for the process - 0 for success, else an error code.
 */
int main(void) {

    int n = 0, i = 40;
    int *p = &n, *q = &i;
    *p = 423;
    p = q;



    return 0;
}

