public class Oo04{
	public static void main(String[] args){
		Student huangyifeng = new Student();
		huangyifeng.name = "��߮��";
		Compur daier = new Compur();
		daier.pingpai = "����";
		huangyifeng.c = daier;
		System.out.println(huangyifeng.name + "�ĵ����ǣ�" + huangyifeng.c.pingpai);
	}
}