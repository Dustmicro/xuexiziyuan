#include<iostream>
#include<cstring>
#include<stdlib.h>
#include"stu.h"

using namespace std;
//����ѧ����ĳ�Ա����
CSTU * CSTU::stuLinkHead=NULL;//��̬���ݳ�Ա����ͳ�ʼ�� 
CSTU * CSTU::stuLinkTail=NULL;//��̬���ݳ�Ա����ͳ�ʼ��
CSTU * CSTU::pCur=NULL;//��̬���ݳ�Ա����ͳ�ʼ��
CSTU * CSTU::pPre=NULL;

unsigned short int CSTU::totNum=0;

bool CSTU::sNoIsExist(string argsNo){
	pCur=stuLinkHead;
	while(1){
	if(pCur->sNo==argsNo){
		cout<<"\t\t����"<<endl;
		return true; 
	}
	pCur=pCur->pNext;
	if(pCur==NULL){
		cout<<"\t\t������"<<endl;
		return false;
	}	
	}
	
	
	
}
void CSTU::editStuInfo(string argsNo){
	pCur=stuLinkHead;
	while(1){
    if(pCur->sNo==argsNo)
    {
        cout<<"\t\t============����ѧ������============"<<endl; 
	cout<<"\t\t              ѧ�ţ�";cin>>pCur->sNo; 
	cout<<"\t\t              ������";cin>>pCur->sName;
	cout<<"\t\t              �Ա�";cin>>pCur->sSex;
		cout<<"\t\t��������(��-��-��)��";//2020-02-01
	//����������� 
	{
	  char sDate[11]={'\0'};//��������������ַ��� 
	  char sTemp[5]={'\0'};//�����������������ַ���(�꣬�£���) 
	  int i=0,j=1;//�洢���Ƿ���������ַ������ַ�������j�洢�����ַ�������� ��1����ݣ�2���·ݣ�3�����ڣ� 
      
	  unsigned short int yTemp=0;
	  unsigned short int mTemp=0;
	  unsigned short int dTemp=0;
	  
	  cin>>sDate;
	  for(int pos=0;pos<strlen(sDate);pos++) {
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
	
   //����ɼ�
   cout<<"\t\t         �ߵ���ѧ��" ;cin>>pCur->sScore[0];		
   cout<<"\t\t         ��ѧӢ�" ;cin>>pCur->sScore[1];
   cout<<"\t\t         ���亯����" ;cin>>pCur->sScore[2]; 
   break;
	}
	pCur=pCur->pNext;
	if(pCur==0){
		break;
	}
}
} 
void CSTU::deleteStu(string argsNo){
	pCur=stuLinkHead;
    pPre=stuLinkHead; 
  if(pCur->sNo==argsNo){
    	
    	pCur=pCur->pNext;
    	pPre=pCur;
    	delete pCur;
	}
    while(pCur->sNo!=argsNo && pCur->pNext!=NULL){
    	 
    	pPre=pCur;
		pCur=pCur->pNext;
	}
    	if(pCur->sNo == argsNo){
    		
    	pPre->pNext=pCur->pNext;
    	delete pCur;
		}
		else{
			cout<<"û�нڵ�";
		}
}

void CSTU::getAverage(string argsNo){
	pCur=stuLinkHead;
	if(pCur->sNo==argsNo){
			cout<<"\t\t"<<pCur->sName <<"���Ƶ�ƽ�����ǣ�"; 
			double average;
			average=(pCur->sScore[0]+pCur->sScore[1]+pCur->sScore[2])/3;
			cout<<average<<endl;
	
		}
	while(pCur->sNo!=argsNo && pCur->pNext!=NULL){
		pCur=pCur->pNext;
		if(pCur->sNo==argsNo){
			cout<<"\t\t"<<pCur->sName <<"���Ƶ�ƽ�����ǣ�"; 
			double average;
			average=(pCur->sScore[0]+pCur->sScore[1]+pCur->sScore[2])/3;
			cout<<average<<endl;
	
		}
	}
	
}

CSTU::CSTU(){
	//1.��ӵ�ǰѧ�����������β��㣩��ѧ������ 
	this->pNext=NULL;//β���û�к�̽�� 
	if(stuLinkHead==NULL){//������û�н��
	stuLinkHead=stuLinkTail=this;//���������ͷ��㣬β���ָ�� 
	}else{//�������н�㣬��ǰ�����ӵ������о���β���
	  stuLinkTail->pNext=this;//��������ԭβ������ӵ���ǰѧ����� 
	  stuLinkTail=this;//����ǰѧ���������Ϊ�µ�β��� 
	        
	}                                                                                                    
	totNum++;//ѧ��������+1 
	//2.���뵱ǰѧ��������
	this->inputStuInfo(); 
}

CSTU::CSTU(string sNo,string sName,string sSex,unsigned short int year,
		unsigned short int month,unsigned short int day,int s1,int s2,int s3)
		:sBirth(year,month,day){
	this->sNo=sNo;this->sName=sName;this->sSex=sSex;
	this->sScore[0]=s1;this->sScore[1]=s2;this->sScore[2]=s3;	
	totNum++;	
}


CSTU::~CSTU(){
    totNum--;
	}

void CSTU::inputStuInfo(){
	system("cls");
	cout<<"\t\t============����ѧ������============"<<endl; 
	cout<<"\t\t              ѧ�ţ�";cin>>this->sNo; 
	cout<<"\t\t              ������";cin>>this->sName;
	cout<<"\t\t              �Ա�";cin>>this->sSex;
	cout<<"\t\t��������(��-��-��)��";//2020-02-01
	//����������� 
	{
	  char sDate[11]={'\0'};//��������������ַ��� 
	  char sTemp[5]={'\0'};//�����������������ַ���(�꣬�£���) 
	  int i=0,j=1;//�洢���Ƿ���������ַ������ַ�������j�洢�����ַ�������� ��1����ݣ�2���·ݣ�3�����ڣ� 
      
	  unsigned short int yTemp=0;
	  unsigned short int mTemp=0;
	  unsigned short int dTemp=0;
	  
	  cin>>sDate;
	  for(int pos=0;pos<strlen(sDate);pos++) {
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
	
   //����ɼ�
   cout<<"\t\t         �ߵ���ѧ��" ;cin>>this->sScore[0];		
   cout<<"\t\t         ��ѧӢ�" ;cin>>this->sScore[1];
   cout<<"\t\t         ���亯����" ;cin>>this->sScore[2];   
	
}
	 

void CSTU::showStuInfo(){
	
	pCur=stuLinkHead;//���������ǰ����ָ�루pCur��ָ��ͷ��㣨��������ķ����Ǵ�ͷ��ʼ����ͷ��β�� 
	
	if(pCur==NULL){
		cout<<endl
		    <<"\t\t��ǰû��ѧ�����ݣ�"
		    <<endl; 
	}else{//��������ѧ�����ݣ����������ÿ������е�ѧ������
	    cout<<endl<<"\t\t=========ѧ����Ϣ=========��"<<endl;//�������
	    cout<<"\t\tѧ��\t����\t�Ա�\t��������\t�ߵ���ѧ\t��ѧӢ��\t���亯��"<<endl;//�����ͷ 
		cout<<"=============================================="<<endl;
		do{
			cout<<"\t\t"//����ĵ�ǰ����ѧ������ 
		        <<pCur->sNo<<"\t"
		        <<pCur->sName<<"\t"
		     	<<pCur->sSex<<"\t";
			pCur->sBirth.showDate();
			cout<<"\t"
			<<pCur->sScore[0]<<"\t"
			<<pCur->sScore[1]<<"\t"
			<<pCur->sScore[2]<<endl;
	
	    	pCur=pCur->pNext;//��pCurָ���̽��	
		} while(pCur!=NULL);//���к�̽��ʱ���ظ���� 
		
		cout<<"=============================================="<<endl;
		cout<<endl<<"\t\t��ǰ��"<<totNum<<"��ѧ����"<<endl; 
   
   
   }	

	
		
}

string CSTU::intNumber(){
	string num;
	cout<<"\t\t         ";cin>>num;
	return num;
}
void CSTU::showMenu(){
	
	CSTU *pStu=NULL;//���涯̬����ѧ�����ݴ洢�ռ�ĵ�ַ 
	
	char menuSel='0';//����ѡ��Ĳ˵�����ַ� 
	while(1){
	system("cls");
	cout<<"\t\t=====ѧ����Ϣ����ϵͳ====="<<endl
	    <<"\t\t*\t1.���ѧ����Ϣ\t*"<<endl          
	    <<"\t\t*\t2.��ʾѧ����Ϣ\t*"<<endl 
	    <<"\t\t*\t3.��ѯѧ����Ϣ\t*"<<endl 
	    <<"\t\t*\t4.�޸�ѧ����Ϣ\t*"<<endl 
	    <<"\t\t*\t5.ɾ��ѧ����Ϣ\t*"<<endl 
	    <<"\t\t*\t6.��ѯ�ɼ�ƽ����\t*"<<endl 
	    <<"\t\t*\t7.ѧ������\t*"<<endl 
	    <<"\t\t*\t0.�˳�ϵͳ\t*"<<endl
	    <<"\t\t============================"<<endl;
	cout<<"��ѡ��(0-6): " ;
	cin>>menuSel;
	switch(menuSel){
		case '1':pStu=new CSTU;system("pause");break; 
		case '2':this->showStuInfo();system("pause");break; 
		case '3':{
	     	cout<<"\t\t����Ҫ��ѯѧ����ѧ��"<<endl;
			sNoIsExist(intNumber());
		    system("pause");break;
			 }
			 
		case'0':cout<<"�˳�ϵͳ"<<endl;break;
		        default:continue;
		case '4': cout<<"\t\t��Ҫ�޸�ѧ����ѧ��:"<<endl;
		          editStuInfo(intNumber());
		          system("pause");
				  break;
	    case '5':cout<<"\t\tҪɾ����ѧ�ţ�"<<endl; 
				 deleteStu(intNumber());
				 system("pause");
				 break;
			  
		case '6':cout<<"\t\tҪ��ѯ��ѧ�ţ�"<<endl;
				 getAverage(intNumber());
				 system("pause");
				 break;
		case '7':sortStuInfo();
		         break;
			}
	if(menuSel=='0')	break;
	
 }
}



