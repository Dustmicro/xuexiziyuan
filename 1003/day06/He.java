/*
    不使用递归计算1-N的和
*/
public class He{
	public static void main(String[] args){
		/*int sum = 0;
		for(int i = 1;i <= 4;i++){
			sum += i;
		}
		System.out.println("sum="+sum);
		*/
		int n = 4;
		int sum = m(4);
		System.out.println(sum);

	}
	public static int m(int n){
		int result = 0;
		for(int i = 1;i <= n;i++){
			result += i;
		}
		return result;
	}
}