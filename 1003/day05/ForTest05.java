/*
    �����ۼ�1-100֮���������
	��+=���ۼӷ���
*/


public class ForTest05{
	public static void main(String[] args){
	
		int i;
		int sum = 0;

		for( i = 1;i <= 100;i += 2){
			
			sum += i;
		}
		System.out.println("������Ϊ--->" +sum );
	}
}