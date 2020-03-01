# -*- coding: UTF-8 -*-

import os
from os import path
from glob import glob
import re


# 定义删除 同步文件的 函数
# 删除 符合模式的文件
def DeleteSyncFiles(files, pattern):
    for file in files:
        if pattern in file:
            print("deleting. ", file)
            os.remove(file)



# 列出 path 下面的所有文件  依次判断, 是文件夹的递归得到结果
def ListFiles(path,files):
    curDirList = os.listdir(path)

    cnt = 1
    for filename in curDirList:
        filepath = os.path.join(path,filename)

        print("cur dir: \t %s" %(filepath))

        if(os.path.isdir(filepath)):
            if "node_modules" in filepath:
                return files
            if "vendor" in filepath:
                return files
            ListFiles(filepath,files)
        else:
            files.append(filepath)
        
        if "sync-conflict-" in filepath:
            print("deleting. ", filepath)
            os.remove(filepath)
        print("%d:\t %s" % (cnt,filepath))
        cnt += 1
    return files

# 输出文件夹 所有文件
def printFiles(path, files):
    cnt = 1
    for file in files:
        print("%d:\t %s" % (cnt,file))
        cnt += 1
    

#  main 执行
if __name__ == "__main__":
    print("Start Exec")

    root_dir = ["D:\Code\Web","D:\Code\Vision"]
    allfiles = []

    for dir in root_dir:
        ListFiles(dir, allfiles)
    # printFiles(root_dir, allfiles)

    # pattern = "sync-conflict-"
    # DeleteSyncFiles(allfiles,pattern)

    # print("List remain files.......")
    # allfiles = []
    # ListFiles(root_dir, allfiles)
    # printFiles(root_dir, allfiles)

    print("delete Sync files Successful!")