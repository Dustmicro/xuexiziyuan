public class Oo04{
	public static void main(String[] args){
		Student huangyifeng = new Student();
		huangyifeng.name = "»Æß®·å";
		Compur daier = new Compur();
		daier.pingpai = "´÷¶û";
		huangyifeng.c = daier;
		System.out.println(huangyifeng.name + "µÄµçÄÔÊÇ£º" + huangyifeng.c.pingpai);
	}
}