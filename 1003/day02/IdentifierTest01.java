/*
   关于java语言当中的标识符
      1、什么是标识符 
         -在java源程序中凡是可以自己有权利命名的单词都是标识符
		 -标识符在编辑器中以黑色字体高亮显示
		 -标识符可以标识什么元素？
		    * 类名
			* 方法名
			* 变量名
			* 接口名
			* 常量名
			.....
	  2、标识符的命名规则【不按照这个规则来编译会报错】
	     * 合法的标识符只能由数字，下划线，字母，美元符号等组成不能有其他符号
		 * 不能数字开头
		 * 严格区分大小写
		 * 关键字不能做标识符（蓝色高亮显示）
		 * 理论上无长度限制
	  3、标识符的命名规范【只是一种规范，不属于语法，不遵守规范也不会报错】
	     * 最好见名只意
		 * 遵守驼峰命名方式
		     SystemService
             UserService
		 * 类名、接口名：首字母大写，后面每个单词首字母大写
		 * 变量名、方法名：首字母小写，后面每个单词首字母大写
		 * 常量名：全部大写
*/
public class IdentifierTest01//IdentifierTest01是一个类名，可以改
{
	//main是一个方法名
	public static void main(String[] args){//args是一个变量名
	}
}