/*
    �ݹ����

*/

public class DiGui01{
	//������
	public static void main(String[] args){
		//����doSome
		System.out.println("main begin");
		doSome();
		System.out.println("main over");
	}
	//���µĴ���Ƭ��ֻ��һ��
	//���ǿ��Ա��ظ�����
	public static void doSome(){
		System.out.println("begin");
		doSome();//���д��벻��������һ�г���Ͳ��Ὺʼ
		System.out.println("over");
	}
}