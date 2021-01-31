// 声明学生类
//#pragma once 

#ifndef STU_H
	#define STU_H
	#include<cstring>
	#include"date.h"
using namespace std;
	class CSTU{
	public:
		CSTU();
		CSTU(string sNo,string sName,string sSex,unsigned short int year,unsigned short int month,unsigned short int day,
		int s1,int s2,int s3);
		CSTU(int i){}
		~CSTU();
		
		void inputStuInfo();//输入学生数据 
		
		void showStuInfo();
		void showMenu();//显示操作学生信息的菜单 
		bool sNoIsExist(string argNo);//在已有的学生数据中查询给定的学号是否存在：若存在则返回逻辑真，否则返回逻辑假。 
		void editStuInfo(string argNo);//编辑给定学号的学生的信息（从键盘输入找到的学生信息） 
		void totalStulnfo();//单科平均成绩 
		void sorStuInfo();//按学号升序排序 
		void deleteStu(string argNo);//删除给定学号的学生节点 
		void writeStu();
		void readStu();

	private:
		string sNo;
		string sName;
		string sSex;
		CDATE sBirth;
		int sScore[3];//课程成绩 
		
		CSTU *pNext;
		
		static CSTU *stuLinkHead;//保存学生数据链表的头结点地址 
		static CSTU *stuLinkTail;//尾节点 
		static CSTU *pCur;//当前节点 
		static CSTU *pPre;//保存操作学生数据链表是所操作的当前节点的前驱节点 

		static unsigned short int totNum;
	};
#endif 
