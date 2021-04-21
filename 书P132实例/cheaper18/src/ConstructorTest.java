import java.util.Random;

public class  ConstructorTest {
    public static void main(String[] args) {
        var staff = new Employee[3];//Employee创造三个数组

        //分别填入三个数组员工信息
        staff[0] = new Employee("张三", 10000);
        staff[1] = new Employee("李四",40000);
        staff[2] = new Employee("王五",6);

        for(Employee e : staff)//分别打印输出员工信息
            System.out.println("name=" + e.getName() + ",id" + e.getId() + ",salary" + e.getSalary());
    }
}
class Employee{
    private static int nextId;
    private int id;
    private String name = "";
    private double salary;
    static{//一个静态方法
        var generator = new Random();//Random生成随机数
        nextId = generator.nextInt(10);//Random生成10以内随机数
    }

    //构造一个无参构造器
    {
        id = nextId;//身份id等于由random生成的随机数
        nextId++;//每个员工的随机数+1
    }

    //在此类中构造一个Employee的方法，用于指向员工姓名，工资
    public Employee(String name, double salary){
        //这里的name,salary指向由此方法代入的实例变量
        this.name = name;
        this.salary = salary;
    }
    public Employee(double s){
        this("Employee #" + nextId,s);
    }
    public Employee(){
        //name initialized to "" --see above
        //salary not explicitly set--initialized to 0
        //id initialized in initialized block
    }
    //私有 get
    public String getName(){
        return name;
    }
    public double getSalary(){
        return salary;
    }
    public int getId(){
        return id;
    }
}
