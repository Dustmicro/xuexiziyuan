/*
    ����
	  �жϵ�ǰ������
	     ����������ʱ��
		   ����ɡ��
		     �ж��Ա�
			   ���Ա����У���һ�Ѻ�ɡ
			   ���Ա���Ů����һ�ѻ�ɡ
		 ������������ǣ�
		    �ж������¶ȣ�
			    �������¶���30�����ϣ�
				     ���Ա����У���ī��
                     ���Ա���Ů������ɹ˪

*/
public class IfTest03{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("��ӭʹ�ñ�ϵͳ");
        System.out.println("˵��1��1��ʾ�����죬0��ʾ����");
		System.out.println("˵��2: 1��ʾ�У�0��ʾŮ");
		System.out.println("˵��3���¶�Ϊ����");
		System.out.print("�������Ա�");
		
		int xingbie = s.nextInt();

		System.out.print("�����뵱ǰ����״���� ");
		int weather = s.nextInt();
		if(weather == 1){
			System.out.println("������");
			if(xingbie == 1){
				System.out.println("��һ�Ѻ�ɡ");
			}else if(xingbie == 0){
				System.out.println("��һ�ѻ�ɡ");
			}else{
				System.out.println("���Ǹ��������");
			}
		}else if(weather == 0){
			//�����¶�
            
            System.out.print("��ǰ�¶�Ϊ��");
			int tmp = s.nextInt();
            if(tmp > 30){
				System.out.println("����");
				if(xingbie == 1){
				System.out.println("��ī��");
			}else if(xingbie == 0){
				System.out.println("����ɹ˪");
			}else{
				System.out.println("���Ǹ��������");
			}
			
		}
			
		}else{
			System.out.println("�����������������");
		}
	}
}