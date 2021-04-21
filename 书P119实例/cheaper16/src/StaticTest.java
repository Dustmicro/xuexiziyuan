//有关static的静态方法是使用
public class StaticTest {
    public static void main(String args[]){//StaticTest类的main方法
        Employee[] staff = new Employee[3];//用Employee类构造一个新的数组
        staff[0] = new Employee("张三",40000);//用new构造新的变量
        staff[1] = new Employee("李四",50000);
        staff[2] = new Employee("王五",60000);
        for(Employee e : staff){//Employee类调用staff数组
            e.setId();
            System.out.println("name=" + e.getName() + ",id=" + e.getId() + ",salary=" + e.getSalary());
            //打印输出员工信息
        }
        int n = Employee.getNextId();
        System.out.println("Next available id=" + n);//打印输出下一个员工信息
    }
}
class Employee{
    private static int nextId = 1;

    private String name;
    private double salary;
    private int id;

    public Employee(String n,double s){
        name = n;
        salary = s;
        id = 0;

    }
    public String getName(){
        return name;
    }

    public double getSalary(){
        return salary;
    }

    public int getId(){
        return id;
    }

    public void setId(){
        id = nextId;
        nextId++;
    }
    public static int getNextId(){
        return nextId;
    }

    public static void main(String[] args){//Employee类的main方法
        Employee e = new Employee("你妈",40000);
        System.out.println(e.getName() + " " + e.getSalary());
    }
}
