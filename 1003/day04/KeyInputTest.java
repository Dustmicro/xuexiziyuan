/*
    接收用户键盘输入
	固定编写
*/
public class KeyInputTest{
	public static void main(String[] args){
		//第一步创建键盘扫面器对象
		java.util.Scanner s = new java.util.Scanner(System.in);
		//第二步调用Scanner对象的next()方法开始接收用户键盘输入
		//程序执行到这里会停下来等待用户输入
		//当用户输入的时候并且最终敲回车键时，键入的信息会自动赋值给userInputContent
		//接收文本（字符串）
		//String userInputContent = s.next();
		
		//接收数字
		int num = s.nextInt();
		//System.out.println("您输入了："+ userInputContent);
		System.out.println("您的计算结果是："+ num);
	}
}
/*
   总结：
   java.util.Scanner s = new.java.util.Scanner(System.in);
   String str = s.next();//字符串
   int num = s.nextInt();//数字
*/
