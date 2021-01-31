/*
     循环语句和条件语句的嵌套使用【for和if的嵌套】
     需求：输出1-100的奇数
*/
public class ForTest04{
	public static void main(String[] args){
		//方案一：从1开始每个数递增加一
		int i;
		for( i = 1;i <= 100;i += 2){
			System.out.println("奇数"+i);
		//方案二：从1开始对每个数进行判断
		//i % 2 = 0 //偶数
		//i % 2 = 1 //奇数
		//i % 2 != 0 //奇数
		/*for( i = 1;i <= 100;i++){
			if(i % 2 != 0){
				System.out.println("奇数-->" +i);
			}*/
		}
		}
	}
