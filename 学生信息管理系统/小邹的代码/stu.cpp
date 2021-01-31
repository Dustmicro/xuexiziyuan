#include<iostream>                //定义学生类的成员函数 
#include<cstring>
#include<cstdlib>
#include<fstream>
#include"stu.h"
using namespace std;
 
CSTU *CSTU::stuLinkHead=NULL;//静态数据成员定义和初始化 
CSTU *CSTU::stuLinkTail=NULL;//静态数据成员定义和初始化
CSTU *CSTU::pCur=NULL;//静态数据成员定义和初始化
CSTU *CSTU::pPre=NULL;

unsigned short int CSTU::totNum=0;
CSTU::CSTU(){
 //1.添加当前学生对象到（链表的尾节点）学生链表
	this->pNext=NULL;//尾节点没有后继节点 
	if(stuLinkHead==NULL){//链表中没有节点 
		stuLinkHead=stuLinkTail=this;//设置链表的头结点、尾节点指针 
	}else{//链表中有节点，当前节点添加到链表中就是尾节点 
		stuLinkTail->pNext=this;//将链表中原尾节点链接当前学生节点 
		stuLinkTail=this;//将当前学生这个节点设置为新的尾节点 
		
	}
 	totNum++;//学生总人数+1
	 //输入当前学生的数据
	 this->inputStuInfo(); 
}
 CSTU::CSTU(string sNo,string sName,string sSex,unsigned short int year,unsigned short int month,unsigned short int day,
int s1,int s2,int s3):sBirth(year,month,day){
 	this->sNo=sNo;this->sName=sName;this->sSex=sSex;
 	this->sScore[0]=s1;this->sScore[1]=s2;this->sScore[2]=s3;
 	totNum++;
}
 
 CSTU::~CSTU(){
 	
 	totNum--;
}
 
void CSTU::inputStuInfo(){//编辑学生信息 
 	system("cls");//清屏 
	cout<<"\t\t=======输入学生数据======="<<endl;
	cout<<"\t\t              学号: ";cin>>this->sNo;
	cout<<"\t\t              姓名: ";cin>>this->sName;
	cout<<"\t\t              性别: ";cin>>this->sSex;

	cout<<"\t\t出生日期(年-月-日): ";//2020-02-01 
 	//输入出生日期
	{
		char sDate[11]={'\0'};//保存输入的日期字符串
		char sTemp[5]={'\0'};//保存分离出来的数字字符串（年、月、日） 
		int i=0,j=1;//i存储的是分离出来的字符串的字符个数，j存储的是字符串的序号（1：年份；2：月份；3：日期） 
		
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
	cout<<"\t\t          高等数学: ";cin>>this->sScore[0];
	cout<<"\t\t          大学英语: ";cin>>this->sScore[1];
	cout<<"\t\t          复变函数: ";cin>>this->sScore[2]; 
}
 
 
void CSTU::showStuInfo(){//显示学生信息 
 	
 	pCur=stuLinkHead;//将表达链表当前的指针(pCur)指向头节点（单项链表的访问是从头开始，从头到尾） 
 	float p=0;
 	if(pCur==NULL){
 		cout<<endl
 			<<"\t\t当前没有学生数据！"
 			<<endl; 
	} else{//链表当中有学生数据，输出链表中每个节点的学生数据
	 	  cout<<endl<<"\t\t========学生信息========"<<endl;//输出标题
		  cout<<"\t\t学号\t\t姓名\t性别\t  出生日期\t高等数学\t大学英语\t复变函数\t平均成绩"<<endl;//输出表头 
		  
		  do{
		  	
		  	cout<<"\t\t"//输出当前节点的学生数据 
		  	    <<pCur->sNo<<"\t"
		  	    <<pCur->sName<<"\t"
		  	    <<pCur->sSex<<"\t";
		  		pCur->sBirth.showDate();
		  	p=(pCur->sScore[0]+pCur->sScore[1]+pCur->sScore[2])/3.0; 
			cout<<"\t" 
			  	<<pCur->sScore[0]<<"\t\t"
		  	    <<pCur->sScore[1]<<"\t\t"
		  	    <<pCur->sScore[2]<<"\t\t"
				<<p<<endl;
		  	    
		
			pCur=pCur->pNext;//将pCur指向后继结点 
		  }while(pCur!=NULL);//当有后继结点时，重复输出 
		  
		  
	  
	}
 	
 	
 	/*cout<<"\t\t学号 "<<sNo<<endl;
 	cout<<"\t\t姓名 "<<sName<<endl;
 	cout<<"\t\t性别 "<<sSex<<endl;
 	cout<<"\t\t出生日期 ";sBirth.showDate();cout<<endl;
 	cout<<"\t\t课程成绩: 高等数学: "<<sScore[0]<<";大学英语: "<<sScore[1]<<";复变函数: "<<sScore[2]<<endl;*/
	 	cout<<"========================================="<<endl;
		cout<<"\t\t当前有"<<totNum<<"名学生。"<<endl;
}



bool CSTU::sNoIsExist(string argNo){
 	bool existFlag=false;
 	pCur=stuLinkHead;
 	
 	if(pCur!=NULL){
 		do{
 			
 			if(pCur->sNo==argNo){
 				existFlag=true;
 				cout<<"该学号的学生的信息："<<endl;
				cout<<endl<<"\t\t========学生信息========"<<endl;//输出标题
		  		cout<<"\t\t学号\t\t姓名\t性别\t  出生日期\t高等数学\t大学英语\t复变函数\t平均成绩"<<endl;//输出表头 
		  			float p;
		  			cout<<"\t\t"//输出当前节点的学生数据 
		  	    		<<pCur->sNo<<"\t"
		  	  		  <<pCur->sName<<"\t"
		  			    <<pCur->sSex<<"\t";
				  		pCur->sBirth.showDate();
		 		 	p=(pCur->sScore[0]+pCur->sScore[1]+pCur->sScore[2])/3.0; 
					cout<<"\t" 
					  	<<pCur->sScore[0]<<"\t\t"
		  			    <<pCur->sScore[1]<<"\t\t"
		  	 		    <<pCur->sScore[2]<<"\t\t"
						<<p<<endl;
 				break;
			 }else{
			 	pCur=pCur->pNext;
			 }
		 }while(pCur!=NULL);
		 
	 }
 	return existFlag;
}
 
void CSTU::editStuInfo(string argNo){//修改学生信息 
 	CSTU *pStu=NULL;
 	system("cls");
 	pCur=stuLinkHead;
 	if(pCur!=NULL){
 		do{
 			if(pCur->sNo==argNo){
 				
 				cout<<"============重新输入学生数据=============="<<endl;
				cout<<"\t\t              学号: ";cin>>this->sNo;
				cout<<"\t\t              姓名: ";cin>>this->sName;
				cout<<"\t\t              性别: ";cin>>this->sSex;
				cout<<"\t\t出生日期(年-月-日): ";//2020-02-01 
		 	//输入出生日期
			{
				char sDate[11]={'\0'};//保存输入的日期字符串
				char sTemp[5]={'\0'};//保存分离出来的数字字符串（年、月、日） 
				int i=0,j=1;//i存储的是分离出来的字符串的字符个数，j存储的是字符串的序号（1：年份；2：月份；3：日期） 
				
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
				pCur->sBirth=CDATE(yTemp,mTemp,dTemp);
			} 
		 		cout<<"\t\t          高等数学: ";cin>>this->sScore[0];
				cout<<"\t\t          大学英语: ";cin>>this->sScore[1];
				cout<<"\t\t          复变函数: ";cin>>this->sScore[2]; 
					
					pCur->sNo=this->sNo;
					pCur->sName=this->sName;
					pCur->sSex=this->sSex;
					
					pCur->sScore[0]=this->sScore[0];
					pCur->sScore[1]=this->sScore[1];
					pCur->sScore[2]=this->sScore[2];
			}else {
					 	pCur=pCur->pNext;
					 }
					 
					 	
					 
		}while(pCur!=NULL);
	}
	
 	
}
 
 
void CSTU::deleteStu(string argNo){
pCur=stuLinkHead;
int c=1;
 	while(pCur!=NULL){
 		if(pCur->sNo==argNo){
 			if(c==1){
 				stuLinkHead=stuLinkHead->pNext;
 				delete pCur;break;
			}else if(c==totNum){
				stuLinkTail=pPre;
				pPre->pNext=NULL;
				delete pCur;break;
			}else{
				pPre->pNext=pCur->pNext;
 				delete pCur;
				break;
			}
				
			 }
		else {
			pPre=pCur;
			pCur=pCur->pNext;c++;
			 }
		}
			
}
 
void CSTU::sorStuInfo(){
 	CSTU *pStu=NULL;
 	
 	for(pCur=stuLinkHead;pCur!=NULL;pCur=pCur->pNext){
 		for(pPre=pCur->pNext;pPre!=NULL;pPre=pPre->pNext){
			if(pCur->sNo>pPre->sNo){
 				string t1sNo,t1sName,t1sSex;
 				int t1sScore[3];
 				unsigned short int a,b,c;
				t1sNo=pCur->sNo;
				t1sName=pCur->sName;
				t1sSex=pCur->sSex;
				a=pCur->sBirth.showyear();
				b=pCur->sBirth.showmonth();
				c=pCur->sBirth.showday();
				t1sScore[0]=pCur->sScore[0];
				t1sScore[1]=pCur->sScore[1];
				t1sScore[2]=pCur->sScore[2];
				pCur->sNo=pPre->sNo;
				pCur->sName=pPre->sName;
				pCur->sSex=pPre->sSex;
				pCur->sBirth.setDate(pPre->sBirth.showyear(),pPre->sBirth.showmonth(),pPre->sBirth.showday());
				pCur->sScore[0]=pPre->sScore[0];
				pCur->sScore[1]=pPre->sScore[1];
				pCur->sScore[2]=pPre->sScore[2];
				pPre->sNo=t1sNo;
				pPre->sName=t1sName;
				pPre->sSex=t1sSex;
				pPre->sBirth.setDate(a,b,c);
				pPre->sScore[0]=t1sScore[0];
				pPre->sScore[1]=t1sScore[1];
				pPre->sScore[2]=t1sScore[2];
			}
		}	 
	 }
 }

/*void CSTU::readStu(){
	
	ifstream infile("stu.exe");
	
	infile.getline(pCur,sizeof(pStu));
}*/

void CSTU::writeStu(){//读出文件函数
	pCur=stuLinkHead;
	ofstream outfile("stu.txt");
	if(!outfile){
		cout<<"文件未打开！！！"<<endl;
	}else{
		cout<<"文件成功打开！"<<endl;
		
		do{
			
		outfile<<pCur->sNo
			   <<pCur->sName
			   <<pCur->sSex
			   <<pCur->sBirth.showyear()
			   <<pCur->sBirth.showmonth()
			   <<pCur->sBirth.showday()
			   <<pCur->sScore[0]
			   <<pCur->sScore[1]
			   <<pCur->sScore[2]<<endl;
			   
			   pCur=pCur->pNext;
	}while(pCur!=NULL);
	
		
		return;
	}
	outfile.close();
	return;
}

void CSTU::showMenu(){//菜单 
 	CSTU *pStu=NULL;
 	char menuSel='0';
 	string a;
 	while(1){
	 	system("cls");
	 	cout<<"\t\t=======学生信息管理系统======="<<endl;
	 	cout<<"\t\t*\t1.添加学生信息\t*"<<endl;
	 	cout<<"\t\t*\t2.显示学生信息\t*"<<endl;
	 	cout<<"\t\t*\t3.查询学生信息\t*"<<endl;
	 	cout<<"\t\t*\t4.删除学生信息\t*"<<endl;
	 	cout<<"\t\t*\t5.以学号升序排序\t*"<<endl;
	 	cout<<"\t\t*\t0.退出系统\t*"<<endl;
	 	cout<<"\t\t========================================"<<endl;
	 	cout<<"\t\t\t请选择（0-5）： ";
		cin>>menuSel;
		switch(menuSel){
			case '1':pStu=new CSTU;system("pause");break;     //cout<<"\t\t选择的是添加学生信息。"<<endl;system("pause");break;
			case '2':/*cout<<"\t\t选择的是显示学生信息。"<<endl;*/this->showStuInfo();system("pause");break;
			case '3':/*cout<<"\t\t选择的是查询学生信息。"<<endl;*/cout<<"请输入要查询的学生的学号：" ; 
					cin>>a;
					if(this->sNoIsExist(a))cout<<"\t\t学号已存在！"<<endl;
						else cout<<"该学号不存在"<<endl;
					cout<<"================================================="<<endl;
					cout<<"\t\t*\t1.编辑学生信息\t*"<<endl;
					cout<<"\t\t*\t0.返回菜单\t*"<<endl;
					cout<<"\t\t\t请选择（0-1）： ";
					int b;  cin>>b;
					if(b==1) this->editStuInfo(a);
					system("pause");break;
			case '4':cout<<"请输入要删除的学生的学号：" ; cin>>a;
					this->deleteStu(a);system("pause");break;
			case '5':this->sorStuInfo();system("pause");break;
			case '0':break;
			default:continue;
		}
		if(menuSel=='0') break;
	} 
}
