/*
    ����forѭ���ҳ�1-100�����е�����
    �������ܹ���1�������������ܱ������� ��������
*/

public class SuShu{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("��ӭʹ��������ѯϵͳ");
		System.out.print("��������Ҫ��ѯ�����֣�");
		int num = s.nextInt();
		boolean SuShu = true;
		for(int j = 2;j < num;j++){
			if (num % j ==0){
				SuShu = false;
				break;
			}
		}
		System.out.println(SuShu ? num+"������" : num+"��������");
	}
}