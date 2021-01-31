//public class Oo08{
	public static void main(String[] args){
		System.out.println("��ӭʹ�û�߮���ѯϵͳ");
		System.out.println("���룺1��ѯ��������");
		System.out.println("���룺2��ѯ�����ֻ�ʹ�����");
		System.out.println("���룺3����"+"\n"+"����");
		System.out.println("���룺4����ɡ"+"\n"+"��ī��");
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.print("�����룺");
		
		int geren = s.nextInt();
		Shouji b = new Shouji("");//
		b.pinpai = "��Ϊ";
		b.shouming = 8;
		Ren huangyifeng = new Ren();
		huangyifeng.name = "��߮��";
		huangyifeng.age = 21;
		huangyifeng.shengao = 185;
		huangyifeng.s = b;
		if(geren == 3){
			System.out.println("���죬��ī��");
		}else if(geren == 4){
			System.out.println("�����죬����ɡ");
		}else if(geren == 1){
            System.out.println("���ֽУ�"+huangyifeng.name);
			System.out.println("���䣺"+huangyifeng.age);
			System.out.println("��ߣ�"+huangyifeng.shengao);
		}else if(geren == 2){
            System.out.println("�ֻ�Ʒ���ǣ�"+b.pinpai);
			System.out.println("�ֻ�����Ϊ��"+b.shouming +"��");
		}else{
			System.out.println("���������ʲô�����������");
		}
		
    }
}

