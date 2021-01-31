public class Oo01{
	public static void main(String[] args){
		//创建一个丈夫对象
        Husband huangyifeng = new Husband();
		huangyifeng.name = "黄弋峰";
		//创建一个妻子对象
		Wife luomingli = new Wife();
		luomingli.name = "罗明俪";
		//结婚[能够通过丈夫找到妻子，也能够通过妻子找到丈夫]
		huangyifeng.w = luomingli;
		luomingli.h = huangyifeng;
		System.out.println(huangyifeng.name + "的老婆叫：" + huangyifeng.w.name);
		System.out.println(luomingli.name + "的丈夫叫：" + luomingli.h.name);
        
	}
}
