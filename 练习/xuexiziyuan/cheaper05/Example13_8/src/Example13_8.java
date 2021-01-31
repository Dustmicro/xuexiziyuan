import java.util.*;
class Student implements Comparable{
    int english = 0;
    String name;
    Student(int english,String name){
        this.name = name;
        this.english = english;
    }
    public int compareTo(Object b){
        Student st = (Student)b;
        return(this.english - st.english);
    }
}
public class Example13_8 {
    public static void main(String args[]){
        TreeSet < Student > mytree = new TreeSet<Student>();
        Student st1,st2,st3,st4;
        st1 = new Student(3,"这些人能活到好多岁呢");
        st2 = new Student(90,"狗蛋儿");
        st3 = new Student(66,"江妹儿");
        st4 = new Student(86,"李聪");
        mytree.add(st1);
        mytree.add(st2); 
        mytree.add(st3);
        mytree.add(st4);
        Iterator<Student>te = mytree.iterator();
        while(te.hasNext()){
            Student stu = te.next();
            System.out.println("" + stu.name + "" + stu.english);
        }
    }

}
