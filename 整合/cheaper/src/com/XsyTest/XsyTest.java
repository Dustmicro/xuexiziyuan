package com.XsyTest;

import com.StaticTest.StaticTest;

import java.time.*;//调用时间库
import java.util.*;//写入语法

public class XsyTest {
    public static void main(String args[]) {//函数入口
        Scanner in = new Scanner(System.in);//引用“in”输入
        StaticTest m = new StaticTest();

        id b = new id();//调用id类，输入给b

        System.out.println("首先了解xsy是谁请按0");
        System.out.print("请输入");
        int a1 = in.nextInt();//输入的内容给a1
        if (a1 == 0) {


            System.out.println("姓名"+b.getName() +"\n" +"年龄" + b.getAge() +"\n" +"身高" + b.getShengGao() +"\n"
                    +"居住地" + b.getWhere());
            //打印输出ID类的姓名，年龄，身高，居住地
        }
        System.out.println("想了解她的工资请按9");
        int a4 = in.nextInt();
        if (a4 == 9) {

            System.out.println("工资" + m.);
        }
        System.out.println("下雨天请输入2，晴天请输入3");
        System.out.println("请输入 ");
        int a2 = in.nextInt();//输入的内容给a2
        if (a2 == 2) {
            System.out.println("她会边裸奔边背乘法口诀，然后再次输入4");
            int a3 = in.nextInt();//嵌套，输入内容给a3
        if (a3 == 4) {
            XsyTest.ChengFa();//、、、、、、、、主类调用ChengFa类
        }
        } else if (a2 == 3) {
            System.out.println("她会先看一下日历表");
            XsyTest.CalendarTest();//，，，，，主类调用CalendarTest类
        }

    }
    public static void ChengFa() {

        System.out.println("九九乘法表");
    for(int i = 1;i <= 9;i++){//定义乘法表第一列的数字1-9
        for(int j = 1;j <= i;j++){//定义乘法表第二列数字
                int num = 0;//定义结果
                num = (i * j);
                System.out.print(i +"*" +j +"=" +num +" ");//打印输出每个乘法结果
            }
            System.out.println("\n");//每完成一列换行
        }
    }

    public static void CalendarTest() {

        LocalDate date = LocalDate.now();//调用LocalDate库函数
        int month = date.getMonthValue();
        int today = date.getDayOfMonth();


        date = date.minusDays(today - 1);//这个月的开始
        DayOfWeek weekend = date.getDayOfWeek();//每周，调用
        int value = weekend.getValue();

        System.out.println("星期一 星期二 星期三 星期四 星期五 星期六 星期天");
        for (int i = 1; i < value; i++)
            System.out.print("  ");
        while (date.getMonthValue() == month) {
            System.out.printf("%3d", date.getDayOfMonth());
            if (date.getDayOfMonth() == today)
                System.out.print("*");
            else
                System.out.print(" ");
            date = date.plusDays(1);
            if (date.getDayOfWeek().getValue() == 1)
                System.out.println();
        }
        if (date.getDayOfWeek().getValue() != 1)
            System.out.println();

    }
}
class id {
    private String name;
    private int shengGao = 188;
    private int age;

    private String where;

    public String getName(){
        return name = "张三";
    }
    public void setName(){
        this.name = name;
    }

    public int getShengGao() {
        return shengGao;
    }

    public void setShengGao(int shengGao) {
        this.shengGao = shengGao;
    }

    public int getAge() { return age; }

    public void setAge(int age) {
        this.age = age;
    }

    public java.lang.String getWhere() {
        return where = "四川省";
    }

    public void setWhere(java.lang.String where) {
        this.where = where;
    }
}


