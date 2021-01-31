/*
   1、循环结构：
        在程序中总有一些代码需要反复执行，将把需要反复执行的代码片段放到循环体中
		再联合计数器共同控制这段需要反复执行的飞马
   2、for循环
      while循环
	  do...while循环
   3、for(初始化表达式；布尔表达式；更新表达式){
          需要执行的代码片段【java语句构成】
   }
   4、for循环执行原理
      

*/


public class ForTest01{
	public static void main(String[] args){
		int i;
		for(i=0;i<=10;i++){
			System.out.println(i);
		}
	}
}