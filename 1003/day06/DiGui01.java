/*
    递归调用

*/

public class DiGui01{
	//主方法
	public static void main(String[] args){
		//调用doSome
		System.out.println("main begin");
		doSome();
		System.out.println("main over");
	}
	//以下的代码片段只有一份
	//但是可以被重复调用
	public static void doSome(){
		System.out.println("begin");
		doSome();//这行代码不结束，下一行程序就不会开始
		System.out.println("over");
	}
}