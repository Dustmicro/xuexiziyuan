#include <iostream>
#include<CSTDLIB>
#include<string.h>
#include"stu.h"
#include"date.h"

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*CDATE d1(2020,11,11,(char *)"购物节");
	d1.showDate();
	
	system("pause");*/
	
	
	/*CSTU s1;
	s1.showStuInfo();
	CSTU s2("1811020001","张三","女",2001,4,8,98,99,100);
	s2.showStuInfo();
	CSTU *pStu=new CSTU;
	*pStu=CSTU("1811020003","李四","男",2001,3,5,89,87,98);
	pStu->showStuInfo();
	delete pStu;
	s2.showStuInfo();*/
	
	CSTU sTemp(1);//此对象仅用于启动菜单
	sTemp.showMenu();
	
	
	return 0;
}
