/*
   ����
      ����ϵͳ����һ���˵����䣬�����������ж�����˳��������ĸ��׶�
	  [0-5]�׶�
	  [6-10]�ٶ�
	  [11-18]������
	  [19-35]����
	  [36-55]����
	  [56-150]����
*/
public class IfTest02{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
        System.out.println("��ӭ��������ٳ��ò�б�ϵͳ");
		System.out.print("������������ǣ�");
		int age = s.nextInt();
		//System.out.println("age= "+age);
		String str = "���û��������";
		if(age < 0 || age > 150){
			str = "����������䲻�Ϸ���Ӧ���롾0-150��֮��";
		}else if(age <= 5){
			str = "�ÿ�";
		}else if(age <= 10){
			str = "Ư��";
		}else if(age <= 18){
			str = "�Ե�����";
		}else if(age <= 35){
			str = "�������";
		}else if(age <= 55){
			str = "û��������";
		}
		System.out.println("�㴦��" +str +"�׶�");
	}
}