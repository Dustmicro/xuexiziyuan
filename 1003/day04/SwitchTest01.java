/*
   switch语法结构
        switch(int或string类型的字面值或变量){
            case int或string类型的字面值或变量:
			      java语句;
				  java语句;
				  java语句;
				  .....
				  break;
			case int或string类型的字面值或变量:
			      java语句;
				  java语句;
				  java语句;
				  .....
				  break;
			...
			default:
			      java语句;
				  ...
		}
*/
public class SwitchTest01{
	public static void main(String[] args){
		java.util.Scanner b = new java.util.Scanner(System.in);
		System.out.print("您输入的是：");
		int num = b.nextInt();
		switch(num){
			case 1:
				System.out.println("星期一");
			    break;
            case 2:
				System.out.println("星期二");
			    break;
		    case 3:
				System.out.println("星期三");
			    break;
			case 4:
				System.out.println("星期四");
			    break;
			case 5:
				System.out.println("星期五");
			    break;
			case 6:
				System.out.println("星期六");
			    break;
			case 7:
				System.out.println("星期日");
			    break;
			default:
                System.out.println("你怎么回事儿啊小老弟！");
		}
	}
}