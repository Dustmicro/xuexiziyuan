//声明日期类
#ifndef DATE_H

	#define DATE_H
	#include<string>
	using namespace std;
	
	class CDATE{
	public:
		CDATE();
		CDATE(unsigned short int year,unsigned short int month,unsigned short int day/*,string dn*/);
		void setDate(unsigned short int year,unsigned short int month,unsigned short int day/*,string dn*/);
		void showDate();
		unsigned short int showyear(){
			return year;
		}
		unsigned short int showmonth(){
			return month;
		}
		unsigned short int showday(){
			return day;
		}
	private:
		unsigned short int year;
		unsigned short int month;
		unsigned short int day;
		/*string dateName;*/
	}; 
#endif

