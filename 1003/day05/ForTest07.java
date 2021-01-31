/*
    找出1-100内的所有素数

*/

public class ForTest07{
	public static void main(String[] args){
		for(int i = 2;i <= 100;i++){
			boolean Su = true;
            for(int j = 2;j < i;j++){
				if(i % j ==0){
					Su = false;
					break;
				}
			}

			if(Su){
				System.out.println("素数是："+i);
			}
		}
	}
}