// #include "stdafx.h"
#include "stdio.h"
#include <sys/stat.h>
#include <io.h>
#include <FCNTL.H>


int getfilesize()
{
    int iresult;
    struct _stat buf;
    iresult = _stat(__FILE__,&buf);
    if(iresult == 0)
    {
        return buf.st_size;
    }
    return NULL;
}

int getfilesize01()
{
    int fp;
    fp=_open(__FILE__,_O_RDONLY);
    if(fp==-1) 
        return NULL;
    return _filelength(fp);
    //return NULL;
}

int getfilesize02()
{
    int fp;
    fp=_open(__FILE__,_O_RDONLY);
    if(fp==-1) 
        return NULL;
    return _lseek(fp,0,SEEK_END);
    //return NULL;
}

int getfilesize03()
{
    int fp;
    fp=_open(__FILE__,_O_RDONLY);
    if(fp==-1) 
        return NULL;
    return _lseek(fp,0,SEEK_END);
    //return NULL;
}

int getfilesize04()
{
    FILE *fp;
    if((fp=fopen(__FILE__,"r"))==NULL)
        return 0;
    fseek(fp,0,SEEK_END);
    return ftell(fp);    //return NULL;
}

int getfilesize05()
{
    FILE *fp;
    char str[1];
    if((fp=fopen(__FILE__,"rb"))==NULL)
        return 0;
    int i=0;
    for( i = 0;!feof(fp);i++)
    {
        fread(&str,1,1,fp);
        
    }
    return i - 1;    //return NULL;
}

int main(int argc, char* argv[])
{
    
    printf("getfilesize()=%d\n",getfilesize());
    printf("getfilesize01()=%d\n",getfilesize01());
    printf("getfilesize02()=%d\n",getfilesize02());
    printf("getfilesize03()=%d\n",getfilesize03());
    printf("getfilesize04()=%d\n",getfilesize04());
    printf("getfilesize05()=%d\n",getfilesize05());
    return 0;
}



// C++ 获取文件大小 程序
#if 0

http://zergb.spaces.live.com/blog/cns!C417B6C5A59504CE!571.entry

#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
    ifstream in("file.txt");
    in.seekg(0, ios::end);      //设置文件指针到文件流的尾部
    streampos ps = in.tellg();  //读取文件指针的位置
    cout << "File size: " << ps << endl;
    in.close();                 //关闭文件流
    return 0;
}
///-------------------------------------------------------------------
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
 std::ifstream ifstr("file.txt");

 ifstr.seekg( 0 , std::ios::end );
 std::cout<<" file size:"<< ifstr.tellg()<<std::endl;
 return 0;
} 

#endif 