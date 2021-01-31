/*
    使用递归计算1-N的和

*/

public class DiGui02{
	public static void main(String[] args){
		int n = 10;
		int sum = s(n);
		System.out.println(sum);
	}/*求和
	public static int m(int n){
		
		if (n == 1){
			return 1;
		}
		return n + m(n-1);
	}*/
	//阶乘
	public static int s(int n){
        if (n == 1){
			return 1;
		}
		return n * s(n - 1);
	}
	
}