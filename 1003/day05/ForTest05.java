/*
    需求：累加1-100之间的奇数和
	“+=”累加符号
*/


public class ForTest05{
	public static void main(String[] args){
	
		int i;
		int sum = 0;

		for( i = 1;i <= 100;i += 2){
			
			sum += i;
		}
		System.out.println("奇数和为--->" +sum );
	}
}