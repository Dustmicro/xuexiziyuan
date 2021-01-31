#include<iostream> 
#include<cstring>
#include<cstdlib>
#include"stu.h"
using namespace std;
CSTU * CSTU::stuLinkHead=NULL;//��̬���ݳ�Ա����ͳ�ʼ�� 
CSTU * CSTU::stuLinkTail=NULL;//��̬���ݳ�Ա����ͳ�ʼ�� 
CSTU * CSTU::pCur=NULL;//��̬���ݳ�Ա����ͳ�ʼ��  
unsigned short int CSTU::totNum=0;


CSTU::CSTU(){
	//1.��ӵ�ǰѧ������(�����β���)��ѧ������
	this->pNext=NULL;//β���û�к�̽��  
	if(stuLinkHead==NULL){//������û�н�� 
		stuLinkHead=stuLinkTail=this;//���������ͷ��㡢β��㡢ָ�� 
	}else{//�������н�㣬��ǰ�����ӵ������о���β��� 
		stuLinkTail->pNext=this;//��������ԭβ������ӵ���ǰѧ����� 
		stuLinkTail=this;//����ǰѧ���������Ϊ�µ�β��� 
	}
	
	totNum++;//ѧ��������+1 
	//2.���뵱ǰѧ�������� 
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
 	  CSTU *pStu=NULL;//���涯̬����ѧ�����ݴ洢�ռ��ַ 
 	  char menuSel='0'; //����ѡ��˵�����ַ� 
     	while(1){
 		system("cls");
 		cout<<"\t\t============ѧ����Ϣ����ϵͳ=============="<<endl
 	    <<"=*\t\t*\t1.���ѧ����Ϣ\t*="<<endl
 	    <<"=*\t\t*\t2.��ʾѧ����Ϣ\t*="<<endl
 	    <<"=*\t\t*\t3.��ѯѧ����Ϣ\t*="<<endl
 	    <<"=*\t\t*\t0.�˳�ϵͳ\t*="<<endl
 	    <<"\t\t=============================================="<<endl;
	cout<<"��ѡ��0-3��:";
	cin>>menuSel;
	switch(menuSel){
		case '1':pStu=new CSTU;system("pause");break;
		case '2':/*cout<<"\t\tѡ�������ʾѧ����Ϣ��"<<endl;*/this->showStuInfo();system("pause");break;
		case '3':/*cout<<"\t\tѡ����ǲ�ѯѧ����Ϣ��"<<endl;*/
		  if(this->sNoIsExist("1811010008")) cout<<"\t\tѧ���Ѵ��ڣ�"<<endl;
		  system("pause");break;
		case '0':break;
		default:continue;
            }
            if(menuSel=='0')break;
	    }
	 
    }
 
void CSTU::inputStuInfo(){
	system("cls");
	cout<<"\t\t=======����ѧ������======="<<endl;
	cout<<"\t\tѧ�ţ�";cin>>this->sNo;
	cout<<"\t\t������";cin>>this->sName;
	cout<<"\t\t�Ա�";cin>>this->sSex;
	cout<<"\t\t�������ڣ���-��-�գ���";//2020-2-1
	//�����������
	{
		char sDate[11]={'\0'};//��������������ַ���
		char sTemp[5]={'\0'};//�����������������ַ������ꡢ�¡��գ�
		int i=0,j=1;//i�洢���Ƿ���������ַ������ַ�������j�洢�����ַ�������� ��1����ݣ�2���·ݣ�3�����ڣ� 
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
	 
	 //����ɼ� 
	 cout<<"\t\t�ߵ���ѧ��";cin>>this->sScore[0];
	 cout<<"\t\t��ѧӢ�";cin>>this->sScore[1];
	 cout<<"\t\t������ѧ��";cin>>this->sScore[2];
    return;
}



void CSTU::showStuInfo(){
			
			pCur=stuLinkHead;//���������ﵱǰ����ָ��ָ��ͷ��� 
			
			system("cls");
		   	cout<<endl<<endl;
			
			
			if(pCur==NULL){
				cout<<endl
				    <<"\t\t��ǰû��ѧ�����ݣ�"
				    <<endl; 
			}else{//��������ѧ�����ݣ����������ÿ������ѧ������ 
				cout<<endl<<"\t\t===============ѧ����Ϣ==============="<<endl;//�������
				cout<<"\t\tѧ��\t\t����\t\t�Ա�\t\t��������  �ߵ���ѧ  ��ѧӢ��  ���亯��"<<endl;//�����ͷ 
				cout<<"======================================================"<<endl;
				do{
						cout<<"\t\t"//������ǵ�ǰ����ѧ������ 
				    <<pCur->sNo<<"\t"
				    <<pCur->sName<<"\t"
					<<pCur->sSex<<"\t";
				pCur->sBirth.showDate();
				cout<<"\t"
					<<pCur->sScore[0]<<"\t   "
					<<pCur->sScore[1]<<"\t   "
					<<pCur->sScore[2]<<endl;
					
				pCur=pCur->pNext;//��pCurָ���̽�� 
				}while(pCur!=NULL);//���������̽���ʱ���ظ���� 
				
				cout<<"\t\t============================================="<<endl;
				cout<<endl<<"\t\t��ǰ��"<<totNum<<"��ѧ����"<<endl;
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

 
 
 
 
 
