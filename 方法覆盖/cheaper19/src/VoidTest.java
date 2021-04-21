import java.util.Scanner;
public class VoidTest {
    public static void main(String[] args) {//程序入口
    Dog a1 = new Dog();
    a1.song();
    System.out.println(a1);
    System.out.println("请输入0-3");
    Scanner a2 = new Scanner(System.in);
    int A = a2.nextInt();
    if(A == 0){

    }
    }
}
class ChengFa{
    int x = 1;
    int y = 1;

}
class Animal{
    private String name;

    public void song(){
        System.out.println("张三很帅");
    }
    public void sing(){
        System.out.println("李四很雄厚");
    }
    public String getName(){
        return name;
    }
    public void setName(){
        this.name = name;
    }

}
class Dog extends Animal{
    public void  song(){
        System.out.println("张四真的很帅");
    }

}