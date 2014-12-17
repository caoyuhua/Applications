#include <stdio.h>  
#include <string.h>  
#include <assert.h>  
#include "sqlite3.h"  
  
typedef struct per  
{  
    char *name;  
    int age;  
    char *sex;  
} per;  
  
per a[] = {  
    "David",22,"man",  
    "Eve",28,"man",  
    "Frand",21,"woman"  
};  
  
  
  
/*
int sqlite3_exec(
sqlite3 * db,
const char *sql,
int (*callback)(void*,int,char **,char**),
void *,
char **errmsg
);
*/
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
//第二个参数argc表示输出信息的总行数
//第四个参数azColName表示该行信息列名称的指针，第三个参数argv表示该行信息列数据的指针 
    int i;    
    for(i=0; i<argc; i++){    
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");    
    }    
    printf("\n");    
    return 0;    
}    
  
int main()    
{    
    sqlite3 *pdb;    
    char *zErrMsg;    
    sqlite3_stmt *pstmt;    
    const char *pzTail;    
    const unsigned char *pTmp;  
    int age;  
    int nCol;  
  
    //打开.db格式数据库，若不存在则新建数据库
    int nRet = sqlite3_open("e:\\db\\people.db",&pdb);    
    assert(SQLITE_OK == nRet);    
  
    //sql语句
    const char *sql = "CREATE TABLE IF NOT EXISTS person(name VARCHAR(128),"    
        "age INTEGER,"    
        "sex VARCHAR(7)"    
        ");";    
    nRet = sqlite3_exec(pdb,sql,NULL,NULL,&zErrMsg);//执行sql语句在pdb数据库中创建一名称为person的表.    
    if (nRet != SQLITE_OK)    
    {    
        printf("%s\n",zErrMsg);    
        sqlite3_close(pdb);    
        return 1;    
    }  
  
    sql = "DELETE  FROM person;";  
    nRet = sqlite3_exec(pdb,sql,NULL,NULL,&zErrMsg);    
    if (nRet != SQLITE_OK)    
    {    
        printf("%s\n",zErrMsg);    
        sqlite3_close(pdb);    
        return 1;    
    }  
    //使用sql语句及sqlite3_exec来插入数据
	sql = "INSERT INTO person(name,age,sex) VALUES(\"Alice\",15,\"woman\");";    
    nRet = sqlite3_exec(pdb,sql,NULL,NULL,&zErrMsg);    
    assert(SQLITE_OK == nRet);//若插入数据失败，此处只是assert断言并没打印出错误信息zErrMsg.
  
    sql = "INSERT INTO person(name,age,sex) VALUES(\"Bob\",18,\"man\");";    
    nRet = sqlite3_exec(pdb,sql,NULL,NULL,&zErrMsg);    
    assert(SQLITE_OK == nRet);
  
    sql = "INSERT INTO person(name,age,sex) VALUES(\"Charli\",11,\"man\");";    
    nRet = sqlite3_exec(pdb,sql,NULL,NULL,&zErrMsg);    
    assert(SQLITE_OK == nRet);
  
    //使用sql语句及sqlite3_exec来查询数据
	printf("=====query by sqlite3_exec()=====\n");  
    sql = "SELECT name,age,sex FROM person;";    
    nRet = sqlite3_exec(pdb,sql,callback,NULL,&zErrMsg);    
    assert(SQLITE_OK == nRet);    
  
// 以下为插入数据的另一种方式：使用sqlite3_prepare_v2、sqlite3_bind_text、sqlite3_bind_int、sqlite3_step等接口函数.
    sql = "INSERT INTO person(name,age,sex) VALUES(?,?,?);";  
    nRet = sqlite3_prepare_v2(pdb,sql,strlen(sql),&pstmt,&pzTail);  
    assert(SQLITE_OK == nRet);    
    int i;  
    for (i=0;i<sizeof(a)/sizeof(per);i++)  
    {//将结构体数组a中的所有数值依次插入数据库  
        nCol = 1;  
        sqlite3_bind_text(pstmt,nCol++,a[i].name,strlen(a[i].name),NULL);  
        sqlite3_bind_int(pstmt,nCol++,a[i].age);  
        sqlite3_bind_text(pstmt,nCol++,a[i].sex,strlen(a[i].sex),NULL);  
  
        sqlite3_step(pstmt);  
        sqlite3_reset(pstmt);  
    }  
  
    sqlite3_finalize(pstmt);  
  
//以下为查询数据的另一种方式：使用sqlite3_prepare_v2、sqlite3_step、sqlite3_column_text、sqlite3_column_int等接口函数.
/*
int sqlite3_prepare_v2(
sqlite3 *db,
const char *zSql,//sql语句(该语句是UTF-8编码的字符串)
int nByte,//sql语句的最大字节数
sqlite3_stmt **ppStmt,//OUT:SQL statement handle
const char **pzTail
)
*/
    printf("====== query by sqlite3_prepare_v2()======\n");  
    sql = "SELECT name,age,sex FROM person;";  
    nRet = sqlite3_prepare_v2(pdb,sql,strlen(sql),&pstmt,&pzTail);  
    assert(SQLITE_OK == nRet);    
    while(1)  
    {  
        nRet = sqlite3_step(pstmt);  
        if (SQLITE_DONE == nRet)  
        {  
            sqlite3_finalize(pstmt);  
            break;  
        }  
        if (SQLITE_ROW == nRet)  
        {  
            nCol = 0;  
            pTmp = sqlite3_column_text(pstmt,nCol++);  
            printf("%s|",pTmp);  
  
            age = sqlite3_column_int(pstmt,nCol++);  
            printf("%d|",age);  
  
            pTmp = sqlite3_column_text(pstmt,nCol++);  
            printf("%s\n",pTmp);  
  
            continue;  
        }  
  
        printf("something error.\n");  
        sqlite3_finalize(pstmt);  
        break;  
    }  
  
    sqlite3_close(pdb);    
    return 0;   
}  
