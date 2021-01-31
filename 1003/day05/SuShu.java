/*
    需求：for循环找出1-100中所有的素数
    素数：能够被1和自身整除不能被其他数 整除的数
*/

public class SuShu{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("欢迎使用素数查询系统");
		System.out.print("请输入您要查询的数字：");
		int num = s.nextInt();
		boolean SuShu = true;
		for(int j = 2;j < num;j++){
			if (num % j ==0){
				SuShu = false;
				break;
			}
		}
		System.out.println(SuShu ? num+"是素数" : num+"不是素数");
	}
}