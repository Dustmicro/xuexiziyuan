/*
    ����java�����е�if��䣬����ѡ��ṹ
	   1���﷨�ṹ
	      ��һ�֣�
		      if(�������ʽ){
				  java���;
				  java���;
				  java���;
				  .....
			  }
		  �ڶ��֣�
		      if(�������ʽ){
				  java���;
				  java���;
				  ��������
			  }else{
				  java���;
				  java���;
				  ��������
			  }
		  �����֣�
		      if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }......
		  �����֣�
		      if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else if(�������ʽ){
				  java���;
				  java���;
				  ...
			  }else (�������ʽ){
				  java���;
				  java���;
				  ...
			  }...... 
	2���ص㣺����java�е�if���ֻҪ��һ����ִ֧������if���ȫ������
	3��ע�⣺���ϵĵڶ��ֺ͵����ַ�ʽ������else���Ա�֤���з�ִ֧��
	4�������Ŀ�����䶼������Ƕ��ʹ�õ�ֻҪ�������
	5��
*/
public class IfTest01{
	public static void main(String[] args){
		//��������λ�õ��幫�ﷶΧ���пϵ»��Ļ�ȥKFC���緹
		double distance = 3.0;//��λKM
		//�ж����
		if(distance < 5){
			System.out.println("ȥ�ϵ»����緹��");
		}
		/*
		    ���󣺼���ѧ���ɼ��ɼ����ܴ�С����
			����ѧ���ɼ��жϵȼ�
			    [90-100]  A
				[80-90]   B
				[70-80]   c
				[60-70]   D
				[0-60]    E
 		
        int grad=90;
		if(grad>=90){
			System.out.println('A');
		}else if(grad>=80){
			System.out.println('B');
		}else if(grad>=70){
			System.out.println('C');
		}else if(grad>=60){
			System.out.println('D');
		}else {
			System.out.println('E');
		}*/
		double score = 59.5;
		if(score < 0 || score > 100){
            System.out.println("�Բ������ṩ�ĳɼ����Ϸ�");
		}else if(score >= 90){
			System.out.println("��ѧ���ĳɼ��ȼ��ǣ�A");
		}else if(score >= 80){
			System.out.println("��ѧ���ĳɼ��ȼ��ǣ�B");
		}else if(score >= 70){
			System.out.println("��ѧ���ĳɼ��ȼ��ǣ�C");
		}else if(score >= 60){
			System.out.println("��ѧ���ĳɼ��ȼ��ǣ�D");
		}else{
			System.out.println("��ѧ���ĳɼ��ȼ��ǣ�E");
		}
	}
}