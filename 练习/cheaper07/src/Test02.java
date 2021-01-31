public class Test02 {
    public class static void main(String[] args){
        User u = new User(20);
    }
    public static void add(User u){
        u.age++
    }
    class User{
        //实例变量
        int age;
        //构造方法
        public User(int i){
            age = i;
        }
    }
}
