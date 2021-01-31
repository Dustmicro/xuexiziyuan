/*
    关于java语言中的if语句，属于选择结构
	   1、语法结构
	      第一种：
		      if(布尔表达式){
				  java语句;
				  java语句;
				  java语句;
				  .....
			  }
		  第二种：
		      if(布尔表达式){
				  java语句;
				  java语句;
				  。。。。
			  }else{
				  java语句;
				  java语句;
				  。。。。
			  }
		  第三种：
		      if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }......
		  第四种：
		      if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else if(布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }else (布尔表达式){
				  java语句;
				  java语句;
				  ...
			  }...... 
	2、重点：对于java中的if语句只要有一个分支执行整个if语句全部结束
	3、注意：以上的第二种和第四种方式都带有else可以保证会有分支执行
	4、有所的控制语句都可以是嵌套使用的只要合理就行
	5、
*/
public class IfTest01{
	public static void main(String[] args){
		//需求：所在位置的五公里范围内有肯德基的话去KFC吃午饭
		double distance = 3.0;//单位KM
		//判断语句
		if(distance < 5){
			System.out.println("去肯德基吃午饭！");
		}
		/*
		    需求：假设学生成绩成绩可能带小数点
			根据学生成绩判断等级
			    [90-100]  A
				[80-90]   B
				[70-80]   c
				[60-70]   D
				[0-60]    E
 		
        int grad=90;
		if(grad>=90){
			System.out.println('A');
		}else if(grad>=80){
			System.out.println('B');
		}else if(grad>=70){
			System.out.println('C');
		}else if(grad>=60){
			System.out.println('D');
		}else {
			System.out.println('E');
		}*/
		double score = 59.5;
		if(score < 0 || score > 100){
            System.out.println("对不起，你提供的成绩不合法");
		}else if(score >= 90){
			System.out.println("该学生的成绩等级是：A");
		}else if(score >= 80){
			System.out.println("该学生的成绩等级是：B");
		}else if(score >= 70){
			System.out.println("该学生的成绩等级是：C");
		}else if(score >= 60){
			System.out.println("该学生的成绩等级是：D");
		}else{
			System.out.println("该学生的成绩等级是：E");
		}
	}
}