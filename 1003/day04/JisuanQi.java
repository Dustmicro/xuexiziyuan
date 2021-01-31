public class JisuanQi{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("欢迎使用本计算机系统！！！");
		System.out.print("请输入第一个数字：");
		int num1 = s.nextInt();
		System.out.print("请输入运算符号：");
		String fuhao = s.next();
		System.out.print("请输入第二个数字：");
		int num2 = s.nextInt();
		int result = 0;
		switch(fuhao){
			case "+" :
				result = num1 + num2;
			break;
			case "-" :
				result = num1 - num2;
			break;
			case "*" :
				result = num1 * num2;
			break;
			case "/" :
				result = num1 / num2;
			break;
			
		}
		System.out.println("运算结果是：" + num1 + fuhao + num2 + "=" + result);
	}
}