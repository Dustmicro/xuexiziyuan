public class JisuanQi{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("��ӭʹ�ñ������ϵͳ������");
		System.out.print("�������һ�����֣�");
		int num1 = s.nextInt();
		System.out.print("������������ţ�");
		String fuhao = s.next();
		System.out.print("������ڶ������֣�");
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
		System.out.println("�������ǣ�" + num1 + fuhao + num2 + "=" + result);
	}
}