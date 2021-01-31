/*
   关于字面值：
       * 字面值：(就是数据，一看能看出的)
	       - 10
		   - 100
		   - "abc"
		   - true
		   - false
	   * 字面值是java源程序的组成部分之一，包括标识符和关键字他们都是java源程序的组成部分
	   * 数据在现实世界当中是分门别类的，所以数据在计算机中也是有类型的：【数据类型】
	       - 10、100         属于整型字面值
		   - 3.14            属于浮点型字面值
		   - true、false     属于布尔型字面值
		   - ‘abc’，‘中国人’ 属于字符串型字面值
		   - 'S'.'人'        属于字符型字面值
	   * 注意：
	       java语言中所有的字符串型字面值必须用双引号括起来
           java语言中所有的字符型字面值必须用单引号括起来
*/
public class ConstTest01
{
	public static void mian(String[] args){
		System.out.println("abc");
		System.out.println('A');
		System.out.println(10);
		System.out.println(true);
		System.out.println(3.14);
	}
}
