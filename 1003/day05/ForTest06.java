/*
    for循环嵌套(乘法表)
*/


public class ForTest06{
	public static void main(String[] args){
	
		/*for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				System.out.println(j);
			}*/
		  for(int i=1;i<10;i++){
			  
		  for(int j=1;j<=i;j++){
			  int sum = 0;
			  sum = (i * j);
              System.out.print(+i +"*" +j +"=" +sum +" ");
		  }
		      System.out.print("\n"); //每循环一次换行
		  }
           
		}
}