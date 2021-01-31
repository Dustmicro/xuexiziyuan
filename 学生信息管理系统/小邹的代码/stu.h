// ����ѧ����
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
		
		void inputStuInfo();//����ѧ������ 
		
		void showStuInfo();
		void showMenu();//��ʾ����ѧ����Ϣ�Ĳ˵� 
		bool sNoIsExist(string argNo);//�����е�ѧ�������в�ѯ������ѧ���Ƿ���ڣ��������򷵻��߼��棬���򷵻��߼��١� 
		void editStuInfo(string argNo);//�༭����ѧ�ŵ�ѧ������Ϣ���Ӽ��������ҵ���ѧ����Ϣ�� 
		void totalStulnfo();//����ƽ���ɼ� 
		void sorStuInfo();//��ѧ���������� 
		void deleteStu(string argNo);//ɾ������ѧ�ŵ�ѧ���ڵ� 
		void writeStu();
		void readStu();

	private:
		string sNo;
		string sName;
		string sSex;
		CDATE sBirth;
		int sScore[3];//�γ̳ɼ� 
		
		CSTU *pNext;
		
		static CSTU *stuLinkHead;//����ѧ�����������ͷ����ַ 
		static CSTU *stuLinkTail;//β�ڵ� 
		static CSTU *pCur;//��ǰ�ڵ� 
		static CSTU *pPre;//�������ѧ�������������������ĵ�ǰ�ڵ��ǰ���ڵ� 

		static unsigned short int totNum;
	};
#endif 
