#include <Windows.h>
 
#define GB (1024*1024*1024)
 
//获取磁盘容量
quint64 getDiskSpace(QString iDriver, bool flag)
{
    //iDriver为盘符(例如"C\"),flag为true则求磁盘总容量，为false则求磁盘剩余容量
    LPCWSTR strDriver=(LPCWSTR)iDriver.utf16();
    ULARGE_INTEGER freeDiskSpaceAvailable, totalDiskSpace, totalFreeDiskSpace;
 
    //调用函数获取磁盘参数(单位为字节Byte),转化为GB，需要除以(1024*1024*1024)
    GetDiskFreeSpaceEx( strDriver, &freeDiskSpaceAvailable, &totalDiskSpace, &totalFreeDiskSpace) ;
    if(flag)
    {
    	return (quint64) totalDiskSpace.QuadPart/GB;
    }
    else
    {
    	return (quint64) totalFreeDiskSpace.QuadPart/GB;
    }
} 
 
//获取电脑所有盘符名
QStringList getDiskName()
{
    QFileInfoList list = QDir::drives();
    QStringList diskNameList(NULL);
 
    for (int i=0; i<list.count(); i++)
    {
 
    	QString str = list.at(i).absoluteDir().absolutePath();
    	diskNameList.append(str);
    }
    return diskNameList;
}
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    QStringList diskList = getDiskName();
 
    foreach(QString str, diskList)
    {
    	if (str.isEmpty())
    	{
    	    continue;
    	}
    	quint64 totalDiskSpace = getDiskSpace(str, true);
    	quint64 freeDiskSpace = getDiskSpace(str, false);
    	qDebug() << QString::fromLocal8Bit("盘符") + str + QString::fromLocal8Bit("【总容量:") << totalDiskSpace \
				 << QString::fromLocal8Bit("\t剩余容量:") << freeDiskSpace << QString::fromLocal8Bit("】");
    }
 
    return a.exec();
}