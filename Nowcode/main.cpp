
// #include "Offer/findArray/Solution.h"

//���ڲ�ͬ�� ��Ŀʹ�ò�ͬ��ͷ�ļ���ʼ������, ��������Ҫ������ʹ��
#include "Code/offer/02_replaceSpace/replaceSpace.h"

using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;

    vector<vector<int> > array= {{1,2,8,9},
                                 {2,4,9,12},
                                 {4,7,10,13},
                                 {6,8,11,15}};


    char * str1 = "We Are Happy";

    Solution s1;
    //s1.Find(7,array);

    cout<<str1<<endl;

    s1.replaceSpace(str1,10);

    cout<<str1<<endl;



    return 1;
}