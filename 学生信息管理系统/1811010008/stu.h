
//����ѧ���� 
//#pragma once
#ifndef STU_H
    #define STU_H
    #include <string.h>
    #include "date.h"
    class CSTU{//����࣬�ݹ��� 
	public:
		CSTU();
		CSTU(string sNo,string sName,string sSex,
		unsigned short int year,unsigned short int month,unsigned short int day,int s1,int s2,int s3);
	    CSTU(int i){}//����һ���ն��� 
		~CSTU();
		
		string intNumber();
		void inputStuInfo();//����ѧ������ 
		void showStuInfo();//���ѧ����Ϣ���� 
	    void showMenu();//��ʾ����ѧ����Ϣ�Ĳ˵�
		
		//�Լ�д
	    bool sNoIsExist(string argsNo);//���Ѿ��е�ѧ�������в�ѯ������ѧ���Ƿ���ڣ�����ڷ����߼��棻���򷵻��߼��١� 
		void editStuInfo(string argsNo);//�༭����ѧ�ŵ�ѧ������Ϣ���Ӽ������������ҵ���ѧ����Ϣ�� 
	    void deleteStu(string argsNo);//ɾ������ѧ�ŵ�ѧ���ڵ� 
	    void getAverage(string argsNo);//���ĳ��ѧ�������Ƴɼ�ƽ������ 
	    void sortStuInfo();//��ѧ��ѧ������ 
	
    private:
	    string sNo;//ѧ�� 
	    string sName;//���� 
	    string sSex;//�Ա� 
	    CDATE sBirth;//�������ڣ������Ա 
	    int sScore[3];//���ſγ̳ɼ� 
	    
		CSTU *pNext;//ָ��ǰѧ��������һ��ѧ�����ݴ洢�ռ䣨��ַ�� 
	
	 
	
	static CSTU *stuLinkHead;//����ѧ�����������ͷ���ĵ�ַ 
	static CSTU *stuLinkTail;//����ѧ�����������β���ĵ�ַ 
	static CSTU *pCur;//�������ѧ����������ʱ�������ĵ�ǰ�ڵ�ĵ�ַ 
	static CSTU *pPre;//�������ѧ����������ʱ�������ĵ�ǰ�ڵ��ǰ���ڵ� 
	
	static unsigned short int totNum;//��̬���ݳ�Ա 
	
   };
#endif
