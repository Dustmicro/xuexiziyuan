package com.EmployeeTest;

import java.time.*;
public class EmployeeTest {
    public static void main(String[] args){
        //用三个Employee对象填充staff数组
        Employee[] staff = new Employee[3];

        //在构造的Employee数组中填入3个Employee对象
        staff[0] = new Employee("狗蛋儿",75000,2000,12,15);
        staff[1] = new Employee("江妹儿",750000,2100,12,5);
        staff[2] = new Employee("布莱克",40000,2011,2,15);

        //提高每个人工资5%
        //使用Employee类中的raiseSalary方法将每个员工的薪水提高5%
        for (Employee e : staff)
            e.raiseSalary(5);

        //打印所有Employee对象信息
        //调用getName方法，getSalary方法，getHireDay方法打印各个员工的信息
        for (Employee e : staff)
            System.out.println("name=" + e.getName() + ",salary=" + e.getSalary() + ",hireDay=" + e.getHireDay());
    }
}
class Employee{
    private String name;
    private double salary;
    private LocalDate hireDay;

    public Employee(String n,double s,int year,int month,int day){
        name = n;
        salary = s;
        hireDay = LocalDate.of(year,month,day);

    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public LocalDate getHireDay() {
        return hireDay;
    }
    public void raiseSalary(double byPercent){
        double raise = salary * byPercent / 100;
        salary += raise;
    }
}
