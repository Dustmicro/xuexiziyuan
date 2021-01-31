/*
    需求：
	  判断当前天气：
	     当外边下雨的时候：
		   带雨伞：
		     判断性别：
			   当性别是男：带一把黑伞
			   当性别是女：带一把花伞
		 当外边是晴天是：
		    判断天气温度：
			    当天气温度在30度以上：
				     当性别是男：戴墨镜
                     当性别是女：擦防晒霜

*/
public class IfTest03{
	public static void main(String[] args){
		java.util.Scanner s = new java.util.Scanner(System.in);
		System.out.println("欢迎使用本系统");
        System.out.println("说明1：1表示下雨天，0表示晴天");
		System.out.println("说明2: 1表示男，0表示女");
		System.out.println("说明3：温度为数字");
		System.out.print("请输入性别：");
		
		int xingbie = s.nextInt();

		System.out.print("请输入当前天气状况： ");
		int weather = s.nextInt();
		if(weather == 1){
			System.out.println("下雨天");
			if(xingbie == 1){
				System.out.println("带一把黑伞");
			}else if(xingbie == 0){
				System.out.println("带一把花伞");
			}else{
				System.out.println("您是个玩意儿？");
			}
		}else if(weather == 0){
			//接收温度
            
            System.out.print("当前温度为：");
			int tmp = s.nextInt();
            if(tmp > 30){
				System.out.println("晴天");
				if(xingbie == 1){
				System.out.println("戴墨镜");
			}else if(xingbie == 0){
				System.out.println("擦防晒霜");
			}else{
				System.out.println("您是个玩意儿？");
			}
			
		}
			
		}else{
			System.out.println("您输入的天气不存在");
		}
	}
}