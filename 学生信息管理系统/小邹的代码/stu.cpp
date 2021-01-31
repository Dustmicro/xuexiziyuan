#include<iostream>                //����ѧ����ĳ�Ա���� 
#include<cstring>
#include<cstdlib>
#include<fstream>
#include"stu.h"
using namespace std;
 
CSTU *CSTU::stuLinkHead=NULL;//��̬���ݳ�Ա����ͳ�ʼ�� 
CSTU *CSTU::stuLinkTail=NULL;//��̬���ݳ�Ա����ͳ�ʼ��
CSTU *CSTU::pCur=NULL;//��̬���ݳ�Ա����ͳ�ʼ��
CSTU *CSTU::pPre=NULL;

unsigned short int CSTU::totNum=0;
CSTU::CSTU(){
 //1.��ӵ�ǰѧ�����󵽣������β�ڵ㣩ѧ������
	this->pNext=NULL;//β�ڵ�û�к�̽ڵ� 
	if(stuLinkHead==NULL){//������û�нڵ� 
		stuLinkHead=stuLinkTail=this;//���������ͷ��㡢β�ڵ�ָ�� 
	}else{//�������нڵ㣬��ǰ�ڵ���ӵ������о���β�ڵ� 
		stuLinkTail->pNext=this;//��������ԭβ�ڵ����ӵ�ǰѧ���ڵ� 
		stuLinkTail=this;//����ǰѧ������ڵ�����Ϊ�µ�β�ڵ� 
		
	}
 	totNum++;//ѧ��������+1
	 //���뵱ǰѧ��������
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
 
void CSTU::inputStuInfo(){//�༭ѧ����Ϣ 
 	system("cls");//���� 
	cout<<"\t\t=======����ѧ������======="<<endl;
	cout<<"\t\t              ѧ��: ";cin>>this->sNo;
	cout<<"\t\t              ����: ";cin>>this->sName;
	cout<<"\t\t              �Ա�: ";cin>>this->sSex;

	cout<<"\t\t��������(��-��-��): ";//2020-02-01 
 	//�����������
	{
		char sDate[11]={'\0'};//��������������ַ���
		char sTemp[5]={'\0'};//�����������������ַ������ꡢ�¡��գ� 
		int i=0,j=1;//i�洢���Ƿ���������ַ������ַ�������j�洢�����ַ�������ţ�1����ݣ�2���·ݣ�3�����ڣ� 
		
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
	cout<<"\t\t          �ߵ���ѧ: ";cin>>this->sScore[0];
	cout<<"\t\t          ��ѧӢ��: ";cin>>this->sScore[1];
	cout<<"\t\t          ���亯��: ";cin>>this->sScore[2]; 
}
 
 
void CSTU::showStuInfo(){//��ʾѧ����Ϣ 
 	
 	pCur=stuLinkHead;//���������ǰ��ָ��(pCur)ָ��ͷ�ڵ㣨��������ķ����Ǵ�ͷ��ʼ����ͷ��β�� 
 	float p=0;
 	if(pCur==NULL){
 		cout<<endl
 			<<"\t\t��ǰû��ѧ�����ݣ�"
 			<<endl; 
	} else{//��������ѧ�����ݣ����������ÿ���ڵ��ѧ������
	 	  cout<<endl<<"\t\t========ѧ����Ϣ========"<<endl;//�������
		  cout<<"\t\tѧ��\t\t����\t�Ա�\t  ��������\t�ߵ���ѧ\t��ѧӢ��\t���亯��\tƽ���ɼ�"<<endl;//�����ͷ 
		  
		  do{
		  	
		  	cout<<"\t\t"//�����ǰ�ڵ��ѧ������ 
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
		  	    
		
			pCur=pCur->pNext;//��pCurָ���̽�� 
		  }while(pCur!=NULL);//���к�̽��ʱ���ظ���� 
		  
		  
	  
	}
 	
 	
 	/*cout<<"\t\tѧ�� "<<sNo<<endl;
 	cout<<"\t\t���� "<<sName<<endl;
 	cout<<"\t\t�Ա� "<<sSex<<endl;
 	cout<<"\t\t�������� ";sBirth.showDate();cout<<endl;
 	cout<<"\t\t�γ̳ɼ�: �ߵ���ѧ: "<<sScore[0]<<";��ѧӢ��: "<<sScore[1]<<";���亯��: "<<sScore[2]<<endl;*/
	 	cout<<"========================================="<<endl;
		cout<<"\t\t��ǰ��"<<totNum<<"��ѧ����"<<endl;
}



bool CSTU::sNoIsExist(string argNo){
 	bool existFlag=false;
 	pCur=stuLinkHead;
 	
 	if(pCur!=NULL){
 		do{
 			
 			if(pCur->sNo==argNo){
 				existFlag=true;
 				cout<<"��ѧ�ŵ�ѧ������Ϣ��"<<endl;
				cout<<endl<<"\t\t========ѧ����Ϣ========"<<endl;//�������
		  		cout<<"\t\tѧ��\t\t����\t�Ա�\t  ��������\t�ߵ���ѧ\t��ѧӢ��\t���亯��\tƽ���ɼ�"<<endl;//�����ͷ 
		  			float p;
		  			cout<<"\t\t"//�����ǰ�ڵ��ѧ������ 
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
 
void CSTU::editStuInfo(string argNo){//�޸�ѧ����Ϣ 
 	CSTU *pStu=NULL;
 	system("cls");
 	pCur=stuLinkHead;
 	if(pCur!=NULL){
 		do{
 			if(pCur->sNo==argNo){
 				
 				cout<<"============��������ѧ������=============="<<endl;
				cout<<"\t\t              ѧ��: ";cin>>this->sNo;
				cout<<"\t\t              ����: ";cin>>this->sName;
				cout<<"\t\t              �Ա�: ";cin>>this->sSex;
				cout<<"\t\t��������(��-��-��): ";//2020-02-01 
		 	//�����������
			{
				char sDate[11]={'\0'};//��������������ַ���
				char sTemp[5]={'\0'};//�����������������ַ������ꡢ�¡��գ� 
				int i=0,j=1;//i�洢���Ƿ���������ַ������ַ�������j�洢�����ַ�������ţ�1����ݣ�2���·ݣ�3�����ڣ� 
				
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
		 		cout<<"\t\t          �ߵ���ѧ: ";cin>>this->sScore[0];
				cout<<"\t\t          ��ѧӢ��: ";cin>>this->sScore[1];
				cout<<"\t\t          ���亯��: ";cin>>this->sScore[2]; 
					
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

void CSTU::writeStu(){//�����ļ�����
	pCur=stuLinkHead;
	ofstream outfile("stu.txt");
	if(!outfile){
		cout<<"�ļ�δ�򿪣�����"<<endl;
	}else{
		cout<<"�ļ��ɹ��򿪣�"<<endl;
		
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

void CSTU::showMenu(){//�˵� 
 	CSTU *pStu=NULL;
 	char menuSel='0';
 	string a;
 	while(1){
	 	system("cls");
	 	cout<<"\t\t=======ѧ����Ϣ����ϵͳ======="<<endl;
	 	cout<<"\t\t*\t1.���ѧ����Ϣ\t*"<<endl;
	 	cout<<"\t\t*\t2.��ʾѧ����Ϣ\t*"<<endl;
	 	cout<<"\t\t*\t3.��ѯѧ����Ϣ\t*"<<endl;
	 	cout<<"\t\t*\t4.ɾ��ѧ����Ϣ\t*"<<endl;
	 	cout<<"\t\t*\t5.��ѧ����������\t*"<<endl;
	 	cout<<"\t\t*\t0.�˳�ϵͳ\t*"<<endl;
	 	cout<<"\t\t========================================"<<endl;
	 	cout<<"\t\t\t��ѡ��0-5���� ";
		cin>>menuSel;
		switch(menuSel){
			case '1':pStu=new CSTU;system("pause");break;     //cout<<"\t\tѡ��������ѧ����Ϣ��"<<endl;system("pause");break;
			case '2':/*cout<<"\t\tѡ�������ʾѧ����Ϣ��"<<endl;*/this->showStuInfo();system("pause");break;
			case '3':/*cout<<"\t\tѡ����ǲ�ѯѧ����Ϣ��"<<endl;*/cout<<"������Ҫ��ѯ��ѧ����ѧ�ţ�" ; 
					cin>>a;
					if(this->sNoIsExist(a))cout<<"\t\tѧ���Ѵ��ڣ�"<<endl;
						else cout<<"��ѧ�Ų�����"<<endl;
					cout<<"================================================="<<endl;
					cout<<"\t\t*\t1.�༭ѧ����Ϣ\t*"<<endl;
					cout<<"\t\t*\t0.���ز˵�\t*"<<endl;
					cout<<"\t\t\t��ѡ��0-1���� ";
					int b;  cin>>b;
					if(b==1) this->editStuInfo(a);
					system("pause");break;
			case '4':cout<<"������Ҫɾ����ѧ����ѧ�ţ�" ; cin>>a;
					this->deleteStu(a);system("pause");break;
			case '5':this->sorStuInfo();system("pause");break;
			case '0':break;
			default:continue;
		}
		if(menuSel=='0') break;
	} 
}
