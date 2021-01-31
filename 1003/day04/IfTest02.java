/*
   需求：
      假设系统给定一个人的年龄，根据年龄来判断这个人出于生命哪个阶段
	  [0-5]幼儿
	  [6-10]少儿
	  [11-18]青少年
	  [19-35]青年
	  [36-55]中年
	  [56-150]老年
*/
public class IfTest02{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
        System.out.println("欢迎来到罗明俪外貌判别系统");
		System.out.print("您输入的年龄是：");
		int age = s.nextInt();
		//System.out.println("age= "+age);
		String str = "真的没法形容了";
		if(age < 0 || age > 150){
			str = "您输入的年龄不合法，应输入【0-150】之间";
		}else if(age <= 5){
			str = "好看";
		}else if(age <= 10){
			str = "漂亮";
		}else if(age <= 18){
			str = "乖得批爆";
		}else if(age <= 35){
			str = "丑的批爆";
		}else if(age <= 55){
			str = "没法形容了";
		}
		System.out.println("你处于" +str +"阶段");
	}
}