#ifndef COMMON_H
#define COMMON_H
#include<QString>
////////////////////文件信息/////////////////
struct FileInfo
{

    FileInfo():fileid(0) , size(0),pFile( nullptr )
      , pos(0) , isPause(0),timestamp(0){

    }

    int fileid;
    QString name;
    QString dir;
    QString time;
    int size;
    QString md5;
    QString type;
    QString absolutePath;

    int pos; //上传或下载到什么位置
    int timestamp; //时间戳：文件的身份
    int isPause; //暂停  0 1

    //文件指针
    FILE* pFile;
};


#endif // COMMON_H
