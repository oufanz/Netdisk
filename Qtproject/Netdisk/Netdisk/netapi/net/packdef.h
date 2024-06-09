#pragma once

#include<memory.h>
#include<string>
#define _DEF_BUFFER         (4096)
#define _DEF_CONTENT_SIZE	(1024)
#define _MAX_SIZE           (40)
#define _MAX_PATH_SIZE         (260)

//自定义协议   先写协议头 再写协议结构
//登录 注册 获取好友信息 添加好友 聊天 发文件 下线请求
#define _DEF_PACK_BASE	(10000)
#define _DEF_PACK_COUNT (100)

//注册
#define _DEF_PACK_REGISTER_RQ	(_DEF_PACK_BASE + 0 )
#define _DEF_PACK_REGISTER_RS	(_DEF_PACK_BASE + 1 )
//登录
#define _DEF_PACK_LOGIN_RQ	(_DEF_PACK_BASE + 2 )
#define _DEF_PACK_LOGIN_RS	(_DEF_PACK_BASE + 3 )


//返回的结果
#define tel_is_exist		(0)
#define name_is_exist		(1)
#define register_success	(2)
//登录请求的结果
#define tel_not_exist		(0)
#define password_error		(1)
#define login_success		(2)


typedef int PackType;

//协议结构
//注册
typedef struct STRU_REGISTER_RQ
{
	STRU_REGISTER_RQ():type(_DEF_PACK_REGISTER_RQ)
	{
		memset( tel  , 0, sizeof(tel));
		memset( name  , 0, sizeof(name));
		memset( password , 0, sizeof(password) );
	}
	//需要手机号码 , 密码, 昵称
	PackType type;
	char tel[_MAX_SIZE];
	char name[_MAX_SIZE];
	char password[_MAX_SIZE];

}STRU_REGISTER_RQ;

typedef struct STRU_REGISTER_RS
{
	//回复结果
	STRU_REGISTER_RS(): type(_DEF_PACK_REGISTER_RS) , result(register_success)
	{
        memset(name,0,sizeof name);
	}
	PackType type;
	int result;
    char name[_MAX_SIZE];
}STRU_REGISTER_RS;

//登录
typedef struct STRU_LOGIN_RQ
{
	//登录需要: 手机号 密码 
	STRU_LOGIN_RQ():type(_DEF_PACK_LOGIN_RQ)
	{
		memset( tel , 0, sizeof(tel) );
		memset( password , 0, sizeof(password) );
	}
	PackType type;
	char tel[_MAX_SIZE];
	char password[_MAX_SIZE];

}STRU_LOGIN_RQ;


typedef struct STRU_LOGIN_RS
{
    //登录需要: 手机号 密码
    STRU_LOGIN_RS():type(_DEF_PACK_LOGIN_RS),result(login_success),userid(0)
    {
        memset( name , 0, sizeof(name) );
    }
    PackType type;
    int result;
    int userid;
    char name[_MAX_SIZE];

}STRU_LOGIN_RS;



////////////////////文件上传/////////////////
//上传文件请求
#define _DEF_PACK_UPLOAD_FILE_RQ       (_DEF_PACK_BASE + 4 )
//上传文件回复
#define _DEF_PACK_UPLOAD_FILE_RS       (_DEF_PACK_BASE + 5 )

//文件内容请求
#define _DEF_PACK_FILE_CONTENT_RQ       (_DEF_PACK_BASE + 6 )
//文件内容回复
#define _DEF_PACK_FILE_CONTENT_RS       (_DEF_PACK_BASE + 7 )


//上传文件请求
struct STRU_UPLOAD_FILE_RQ
{
    STRU_UPLOAD_FILE_RQ():type(_DEF_PACK_UPLOAD_FILE_RQ)
      ,userid(0),size(0),timestamp(0){
        memset( fileName , 0, sizeof(fileName) );
        memset( dir , 0, sizeof(dir) );
        memset( md5 , 0, sizeof(md5) );
        memset( fileType , 0, sizeof(fileType) );
        memset( time , 0, sizeof(time) );
    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid; //服务器与时间戳配合,区分不同任务
    char fileName[_MAX_PATH_SIZE]; //上传文件名字
    int size;//大小
    char dir[_MAX_PATH_SIZE];//上传到什么目录
    char md5[_MAX_SIZE]; //上传文件的md5, 用于验证文件是否完整无误
    char fileType[_MAX_SIZE];//文件类型
    char time[_MAX_SIZE]; //上传时间
};

//上传文件回复
struct STRU_UPLOAD_FILE_RS
{
    STRU_UPLOAD_FILE_RS(): type(_DEF_PACK_UPLOAD_FILE_RS)
      , userid(0), fileid(0),result(1),timestamp(0){

    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid; //文件id
    int result; //结果
};


//文件内容请求
struct STRU_FILE_CONTENT_RQ
{
    STRU_FILE_CONTENT_RQ():type(_DEF_PACK_FILE_CONTENT_RQ),
        userid(0),fileid(0),len(0),timestamp(0){
        memset( content , 0 , sizeof(content));
    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid;//文件id
    char content[_DEF_BUFFER];//文件内容 也叫文件块   _DEF_BUFFER  4096
    int len;//文件内容长度
};

//文件内容回复
struct STRU_FILE_CONTENT_RS
{
    STRU_FILE_CONTENT_RS():type(_DEF_PACK_FILE_CONTENT_RS),
        userid(0),fileid(0),result(1),len(0),timestamp(0){

    }
    PackType type;
    int timestamp;//时间戳用于区分不同任务
    int userid;//用户id
    int fileid;//文件id
    int result;//结果
    int len;//文件内容长度

};


