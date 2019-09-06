#include <iostream>
using namespace std;

unsigned int calcHash(char * filename)
{
    unsigned int res=0,tmp=1;
    
    char* p = filename;

    while(p)
    {
        tmp *=  131;
        res = (unsigned int)(*p) *tmp;

        p++;
    }

    return res;

}

int main(void)
{

    cout<<"Hello World!"<<endl;
    cout<<"测试 World!"<<endl;

    char file[] = "testHash!";

    cout<<calcHash(file)<<endl;

    
    return 0;
}



