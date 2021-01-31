#include<iostream> 
#include<cstring>
#include<cstdlib>
#include"stu.h"
using namespace std;
CSTU * CSTU::stuLinkHead=NULL;//静态数据成员定义和初始化 
CSTU * CSTU::stuLinkTail=NULL;//静态数据成员定义和初始化 
CSTU * CSTU::pCur=NULL;//静态数据成员定义和初始化  
unsigned short int CSTU::totNum=0;


CSTU::CSTU(){
	//1.添加当前学生对象(链表的尾结点)到学生链表
	this->pNext=NULL;//尾结点没有后继结点  
	if(stuLinkHead==NULL){//链表中没有结点 
		stuLinkHead=stuLinkTail=this;//设置链表的头结点、尾结点、指针 
	}else{//链表中有结点，当前结点添加到链表中就是尾结点 
		stuLinkTail->pNext=this;//将链表中原尾结点连接到当前学生结点 
		stuLinkTail=this;//将当前学生结点设置为新的尾结点 
	}
	
	totNum++;//学生总人数+1 
	//2.输入当前学生的数据 
	this->inputStuInfo(); 
}

CSTU::CSTU(string sNo,string sName,string sSex,unsigned short int year,
		unsigned short int month,unsigned short int day,
		int s1,int s2,int s3):sBirth(year,month,day){
			
	this->sNo=sNo;this->sName=sName;this->sSex=sSex;
	this->sScore[0]=s1;this->sScore[1]=s2;this->sScore[2]=s3;
	totNum++;
		}
		
CSTU::~CSTU(){
	totNum--;
}
void CSTU::showMenu(){
 	  CSTU *pStu=NULL;//保存动态分配学生数据存储空间地址 
 	  char menuSel='0'; //保存选择菜单项的字符 
     	while(1){
 		system("cls");
 		cout<<"\t\t============学生信息管理系统=============="<<endl
 	    <<"=*\t\t*\t1.添加学生信息\t*="<<endl
 	    <<"=*\t\t*\t2.显示学生信息\t*="<<endl
 	    <<"=*\t\t*\t3.查询学生信息\t*="<<endl
 	    <<"=*\t\t*\t0.退出系统\t*="<<endl
 	    <<"\t\t=============================================="<<endl;
	cout<<"请选择（0-3）:";
	cin>>menuSel;
	switch(menuSel){
		case '1':pStu=new CSTU;system("pause");break;
		case '2':/*cout<<"\t\t选择的是显示学生信息。"<<endl;*/this->showStuInfo();system("pause");break;
		case '3':/*cout<<"\t\t选择的是查询学生信息。"<<endl;*/
		  if(this->sNoIsExist("1811010008")) cout<<"\t\t学号已存在！"<<endl;
		  system("pause");break;
		case '0':break;
		default:continue;
            }
            if(menuSel=='0')break;
	    }
	 
    }
 
void CSTU::inputStuInfo(){
	system("cls");
	cout<<"\t\t=======输入学生数据======="<<endl;
	cout<<"\t\t学号：";cin>>this->sNo;
	cout<<"\t\t姓名：";cin>>this->sName;
	cout<<"\t\t性别：";cin>>this->sSex;
	cout<<"\t\t出生日期（年-月-日）：";//2020-2-1
	//输入出生日期
	{
		char sDate[11]={'\0'};//保存输入胡日期字符串
		char sTemp[5]={'\0'};//保存分离出来的数字字符串（年、月、日）
		int i=0,j=1;//i存储的是分离出来的字符串的字符个数，j存储的是字符串的序号 （1：年份；2：月份；3：日期） 
	    unsigned short int yTemp=0;
	    unsigned short int mTemp=0;
	    unsigned short int dTemp=0;
		
		
		cin>>sDate;
	    for(int pos=0;pos<strlen(sDate);pos++){
	    	if(sDate[pos]=='-'){
	    	    i=0,j++;
				memset(sTemp,'\0',sizeof(sTemp));	
			}else{
				sTemp[i]=sDate[pos];
				i++;
			}
	    	switch(j){
	    		case 1:yTemp=atoi(sTemp);break;
	    		case 2:mTemp=atoi(sTemp);break;
	    		case 3:dTemp=atoi(sTemp);break;
			}
		}
		this->sBirth=CDATE(yTemp,mTemp,dTemp);
	 }
	 
	 //输入成绩 
	 cout<<"\t\t高等数学：";cin>>this->sScore[0];
	 cout<<"\t\t大学英语：";cin>>this->sScore[1];
	 cout<<"\t\t复变数学：";cin>>this->sScore[2];
    return;
}



void CSTU::showStuInfo(){
			
			pCur=stuLinkHead;//将表达链表达当前结点的指针指向头结点 
			
			system("cls");
		   	cout<<endl<<endl;
			
			
			if(pCur==NULL){
				cout<<endl
				    <<"\t\t当前没有学生数据！"
				    <<endl; 
			}else{//链表当中有学生数据，输出链表中每个结点的学生数据 
				cout<<endl<<"\t\t===============学生信息==============="<<endl;//输出标题
				cout<<"\t\t学号\t\t姓名\t\t性别\t\t出生日期  高等数学  大学英语  复变函数"<<endl;//输出表头 
				cout<<"======================================================"<<endl;
				do{
						cout<<"\t\t"//输出的是当前结点的学生数据 
				    <<pCur->sNo<<"\t"
				    <<pCur->sName<<"\t"
					<<pCur->sSex<<"\t";
				pCur->sBirth.showDate();
				cout<<"\t"
					<<pCur->sScore[0]<<"\t   "
					<<pCur->sScore[1]<<"\t   "
					<<pCur->sScore[2]<<endl;
					
				pCur=pCur->pNext;//将pCur指向后继结点 
				}while(pCur!=NULL);//当有这个后继结点的时候，重复输出 
				
				cout<<"\t\t============================================="<<endl;
				cout<<endl<<"\t\t当前有"<<totNum<<"名学生。"<<endl;
			}
			
		
		return;
		}
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
  return existFlag;
	
}

 
 
 
 
 
