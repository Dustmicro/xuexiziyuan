//声明学生类 

#ifndef STU_H
#define STU_H
#include "date.h"
#include <string.h>
//#pragma once


class CSTU{//组合类、递归类 
	public:
		CSTU();
		CSTU(string sNo,string sName,string sSex,unsigned short int year,
		unsigned short int month,unsigned short int day,int s1,int s2,int s3);
		CSTU(int i){}//创建一个空对象 
		~CSTU();
		void inputStuInfo();//输入学生数据 
		
		
		void showStuInfo();//输出学生信息数据 
		void showMenu();//显示操作学生信息的一个菜单 
		bool sNoIsExist(string argNo);//在已经有的学生数据中查询给定的学号是否存在 ：若存在返回逻辑真；否者返回逻辑假 
	private:
	
	string sNo;//学号 
    string sName;//姓名 
    string  sSex;//性别	
    CDATE sBirth;//出生日期
    int sScore[3];//三门课成绩 
    
    CSTU *pNext;//指向当前学生关联下一个学生数据存储空间地址 
    static CSTU *stuLinkHead; //保存学生数据链表的头结点的地址 
    static CSTU *stuLinkTail;//保存学生数据链表的尾结点的地址
    static CSTU *pCur;//保存操作学生数据链表时所操作的当前结点的地址 
    static unsigned short int totNum;//静态数据成员 
};
bool CSTU::sNoIsExist(string argNo){
	bool existFlag=false;
	pCur=stuLinkHead;
	
	if(pCur!=NULL){  
		do{
			
		
		if(pCur->sNo==argNo){
		   existFlag=true;
		   break;	
		}else{
			pCur=pCur->pNext;
		}
		    
	}while(pCur!=NULL);
  }


#endif
