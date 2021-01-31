import sun.util.locale.StringTokenIterator;

import java.util.*;
public class Example9_14 {
    public static void main(String args[]){
        String s = "市话费：28.89元，长途话费：128.87元，上网费：298元。";
        String delim = "市话长途话上网费元：，。";
        StringTokenizer fenxi = new StringTokenizer(s,delim);//用delim中的字符的任意组合作为分隔标记
        double totalMoney = 0;
        while(fenxi.hasMoreTokens()){
            double money = Double.parseDouble(fenxi.nextToken());
            System.out.println(money);
            totalMoney += money;
        }
        System.out.println("总费用：" + totalMoney + "元");
    }
}
