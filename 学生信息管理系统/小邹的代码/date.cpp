//定义日期类的成员
#include<iostream>
#include<string.h>
#include"date.h"

using namespace std;
 
 CDATE::CDATE(){
 	year=1970;
 	month=1;
 	day=1;
 	/*dateName=" ";*/
 }
 CDATE::CDATE(unsigned short int year,unsigned short int month,unsigned short int day/*,string dn*/){
 	this->year=year;this->month=month;this->day=day;/*this->dateName=dn;*/
 }
 void CDATE::setDate(unsigned short int year,unsigned short int month,unsigned short int day){
 	this->year=year;this->month=month;this->day=day;/*this->dateName=dn;*/
 }
 void CDATE::showDate(){
	cout<<year<<"年"<<month<<"月"<<day<<"日"/*<<"	"<<dateName*/;
	
 }
