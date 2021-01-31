/*
    体验方法重载的优点

*/
public class FangFa05{
	public static void main(String[] args){
		System.out.println(m(1,2));
        System.out.println(m(1.0,2.0));
        System.out.println(m(1L,2L));

	 }
	public static int m(int a,int b){
		return a + b;
	}
	public static double m(double a,double b){
		return a + b;
	}
	public static long m(long a,long b){
		return a + b;
	}
}