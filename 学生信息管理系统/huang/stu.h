//����ѧ���� 

#ifndef STU_H
#define STU_H
#include "date.h"
#include <string.h>
//#pragma once


class CSTU{//����ࡢ�ݹ��� 
	public:
		CSTU();
		CSTU(string sNo,string sName,string sSex,unsigned short int year,
		unsigned short int month,unsigned short int day,int s1,int s2,int s3);
		CSTU(int i){}//����һ���ն��� 
		~CSTU();
		void inputStuInfo();//����ѧ������ 
		
		
		void showStuInfo();//���ѧ����Ϣ���� 
		void showMenu();//��ʾ����ѧ����Ϣ��һ���˵� 
		bool sNoIsExist(string argNo);//���Ѿ��е�ѧ�������в�ѯ������ѧ���Ƿ���� �������ڷ����߼��棻���߷����߼��� 
	private:
	
	string sNo;//ѧ�� 
    string sName;//���� 
    string  sSex;//�Ա�	
    CDATE sBirth;//��������
    int sScore[3];//���ſγɼ� 
    
    CSTU *pNext;//ָ��ǰѧ��������һ��ѧ�����ݴ洢�ռ��ַ 
    static CSTU *stuLinkHead; //����ѧ�����������ͷ���ĵ�ַ 
    static CSTU *stuLinkTail;//����ѧ�����������β���ĵ�ַ
    static CSTU *pCur;//�������ѧ����������ʱ�������ĵ�ǰ���ĵ�ַ 
    static unsigned short int totNum;//��̬���ݳ�Ա 
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
