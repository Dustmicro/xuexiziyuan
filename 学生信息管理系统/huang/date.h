//����������



#ifndef DATE_H
#include <string.h>
#define DATE_H
using namespace std;
class CDATE{
	public:
	   CDATE();
	   CDATE(unsigned short int year,unsigned short int month,unsigned short int day /*string dn*/); 
       void setDate(unsigned short int year,unsigned short int month,unsigned short int day /*string dn*/);
	   void showDate();
	
	private:
	   unsigned short int year;
	   unsigned short int month;
	   unsigned short int day;
	   //string dateName;
}; 
#endif
