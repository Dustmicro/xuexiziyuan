
//声明学生类 
//#pragma once
#ifndef STU_H
    #define STU_H
    #include <string.h>
    #include "date.h"
    class CSTU{//组合类，递归类 
	public:
		CSTU();
		CSTU(string sNo,string sName,string sSex,
		unsigned short int year,unsigned short int month,unsigned short int day,int s1,int s2,int s3);
	    CSTU(int i){}//创建一个空对象 
		~CSTU();
		
		string intNumber();
		void inputStuInfo();//输入学生数据 
		void showStuInfo();//输出学生信息数据 
	    void showMenu();//显示操作学生信息的菜单
		
		//自己写
	    bool sNoIsExist(string argsNo);//在已经有的学生数据中查询给定的学号是否存在：如存在返回逻辑真；否则返回逻辑假。 
		void editStuInfo(string argsNo);//编辑给定学号的学生的信息（从键盘重新输入找到的学生信息） 
	    void deleteStu(string argsNo);//删除给定学号的学生节点 
	    void getAverage(string argsNo);//输出某个学生的三科成绩平均数； 
	    void sortStuInfo();//按学生学号排序 
	
    private:
	    string sNo;//学号 
	    string sName;//姓名 
	    string sSex;//性别 
	    CDATE sBirth;//出生日期，对象成员 
	    int sScore[3];//三门课程成绩 
	    
		CSTU *pNext;//指向当前学生关联下一个学生数据存储空间（地址） 
	
	 
	
	static CSTU *stuLinkHead;//保存学生数据链表的头结点的地址 
	static CSTU *stuLinkTail;//保存学生数据链表的尾结点的地址 
	static CSTU *pCur;//保存操作学生数据链表时所操作的当前节点的地址 
	static CSTU *pPre;//保存操作学生数据链表时所操作的当前节点的前驱节点 
	
	static unsigned short int totNum;//静态数据成员 
	
   };
#endif
