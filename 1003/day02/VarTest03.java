public class VarTest03{
	//这里的static不能去掉
	static int y = 40
	public static void main(String[] args){
		//变量i的作用域是main方法
		//在整个main方法中是有效的，可以访问
		int i = 100;
		//编写一个for循环
		for(int a=0;a<9;a++){//a变量的作用域只在for循环中，for循环结束后a变量的内存就释放了
		}
		//这里无法访问变量a
		//System.out.println(a);
		int j;//作用域是main方法
		for(j=0;j<9;j++){
		}
		System.out.println(j);//访问的是main方法中的j变量 
	}
	public static void nihao(){
		//这里无法访问main方法中的变量i
		//已经出了i变量的作用域

		//System.out.println(i);
		System.out.println(y);
	}
}