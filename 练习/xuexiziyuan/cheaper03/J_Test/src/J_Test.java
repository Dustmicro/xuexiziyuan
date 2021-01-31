public class J_Test {
    String m_kobe = "1";
    String[] m_king = {"2"};

    public static void main(String[] args){
        J_Test app = new J_Test();
        app.mb_operate(app.m_kobe,app.m_king);
        System.out.println(app.m_kobe+app.m_king[0]);
    }

    static void mb_operate(String kobe, String[] king) {
        kobe = new String("3");
        king[0] = new String("4");
    }

}
