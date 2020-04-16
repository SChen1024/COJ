// 获取当前文件夹下 cpp 文件或者cc 文件 h . hpp 文件的行数

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define WIN32 1

#ifdef linux
    #include <unistd.h>
    #include <dirent.h>
#endif
#ifdef WIN32
    #include <direct.h>
    #include <io.h>
#endif
using namespace std;

/**
 * @function: 获取cate_dir目录下的所有文件名
 * @param: cate_dir - string类型
 * @result：vector<string>类型
*/
vector<string> getFiles(string cate_dir)
{
	vector<string> files;//存放文件名
 
#ifdef WIN32
	_finddata_t file;
	long lf;
	//输入文件夹路径
	if ((lf=_findfirst(cate_dir.c_str(), &file)) == -1) {
		cout<<cate_dir<<" not found!!!"<<endl;
	} else {
		while(_findnext(lf, &file) == 0) {
			//输出文件名
			//cout<<file.name<<endl;
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			files.push_back(file.name);
		}
	}
	_findclose(lf);
#endif
 
#ifdef linux
	DIR *dir;
	struct dirent *ptr;
	char base[1000];
 
	if ((dir=opendir(cate_dir.c_str())) == NULL)
        {
		perror("Open dir error...");
                exit(1);
        }
 
	while ((ptr=readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
		        continue;
		else if(ptr->d_type == 8)    ///file
			//printf("d_name:%s/%s\n",basePath,ptr->d_name);
			files.push_back(ptr->d_name);
		else if(ptr->d_type == 10)    ///link file
			//printf("d_name:%s/%s\n",basePath,ptr->d_name);
			continue;
		else if(ptr->d_type == 4)    ///dir
		{
			files.push_back(ptr->d_name);
			/*
		        memset(base,'\0',sizeof(base));
		        strcpy(base,basePath);
		        strcat(base,"/");
		        strcat(base,ptr->d_nSame);
		        readFileList(base);
			*/
		}
	}
	closedir(dir);
#endif
 
	//排序，按从小到大排序
	std::sort(files.begin(), files.end());
	return files;
}

// 计数行数
int CountLines(std::string &filename)
{
    ifstream ReadFile;
    int n=0;
    string tmp;
    ReadFile.open(filename,ios::in);//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail())//文件打开失败:返回0
    {
        return 0;
    }
    else//文件存在
    {
        while(getline(ReadFile,tmp,'\n'))
        {
            n++;
        }
        ReadFile.close();
        return n;
    }
}

// 判断是不是 设定的后缀名
bool isCPP(std::string &str)
{
    string suffixStr = str.substr(str.find_last_of('.') + 1);//获取文件后缀

    if(suffixStr == "cpp")

}

// 主函数 执行
int main(void)
{
#if WIN32
    char current_address[100];
	memset(current_address, 0, 100);
	getcwd(current_address, 100); //获取当前路径
	cout<<current_address<<endl;
	strcat(current_address, "\\*");
 
	vector<string> files=getFiles((string)current_address);

    int total_cnt = 0;

    cout<<"------Count the number of lines of code -----------------"<<endl;

	for (int i=0; i<files.size(); i++)
	{


        int line = CountLines(files[i]);


        total_cnt += line;
		cout<<"\t"<<files[i]<<":\t"<<line<<endl;
	}

    cout<<"-----------------------------------------"<<endl;
    cout<<"\tTotal Line: \t"<<total_cnt<<endl;

    cin.get();
 
#endif

#if linux
    DIR *dir;
    char basePath[100];
 
    ///get the current absoulte path
    memset(basePath, '\0', sizeof(basePath));
    getcwd(basePath, 999);
    printf("the current dir is : %s\n",basePath);
 
	 
    cout<<endl<<endl;
    vector<string> files=getFiles(basePath);
    for (int i=0; i<files.size(); i++)
    {
    	cout<<files[i]<<endl;
    }
 

#endif






    return 0;
}