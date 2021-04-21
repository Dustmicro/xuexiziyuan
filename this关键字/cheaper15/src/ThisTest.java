//有关于this的用法
public class ThisTest {
    static{
        System.out.println("A");
    }

    public static void main(String args[]){
        Custmor a1 = new Custmor("钟颜玉");
        a1.shopping();
        Custmor a2 = new Custmor("钟颜玉真的在");
        a2.shopping();
    }
}
class Custmor{
    String name;
    public Custmor(String s){
        name = s;
    }
    public void shopping(){
        System.out.println(name + "在食屎啦");//该行中的name调用就是this的用法指向当前对象，针对于实例变量不能用于static静态方法
        //静态方法的调用只需要类名不需要对象，而this就是通过对象来调用
    }
}
//例如
/*class OO{
    String name = "你妈";
    public static void stu(){
        System.out.println(name);
    }
}*/