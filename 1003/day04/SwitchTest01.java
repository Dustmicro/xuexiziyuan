/*
   switch�﷨�ṹ
        switch(int��string���͵�����ֵ�����){
            case int��string���͵�����ֵ�����:
			      java���;
				  java���;
				  java���;
				  .....
				  break;
			case int��string���͵�����ֵ�����:
			      java���;
				  java���;
				  java���;
				  .....
				  break;
			...
			default:
			      java���;
				  ...
		}
*/
public class SwitchTest01{
	public static void main(String[] args){
		java.util.Scanner b = new java.util.Scanner(System.in);
		System.out.print("��������ǣ�");
		int num = b.nextInt();
		switch(num){
			case 1:
				System.out.println("����һ");
			    break;
            case 2:
				System.out.println("���ڶ�");
			    break;
		    case 3:
				System.out.println("������");
			    break;
			case 4:
				System.out.println("������");
			    break;
			case 5:
				System.out.println("������");
			    break;
			case 6:
				System.out.println("������");
			    break;
			case 7:
				System.out.println("������");
			    break;
			default:
                System.out.println("����ô���¶���С�ϵܣ�");
		}
	}
}