//声明日期类 

#ifndef DATE_H
#define DATE_H
#include<string.h>

  using namespace std;
    class CDATE{
    public:
    	CDATE();
    	CDATE(unsigned short int year,unsigned short int month,unsigned short int day/*,string dn*/);
    	void setDate(unsigned short int year,unsigned short int month,unsigned short int day/*,string dn*/);
        void showDate(); 
	private:
    	unsigned short int year;
    	unsigned short int month;
    	unsigned short int day;
    	//string dateName; 
	};
#endif
