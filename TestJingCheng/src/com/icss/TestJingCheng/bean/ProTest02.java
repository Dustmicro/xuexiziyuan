package com.icss.TestJingCheng.bean;

/**
 * �����û��������飬���Խ��������ȼ�
 * @author HYF
 *
 */
public class ProTest02 {
    public static void main(String[] args) throws InterruptedException {
        ThreadGroup g = new ThreadGroup("���Է���");
        // 4���߳�  ���ȼ���1 3 5 7
        for (int i = 0; i < 4; i++) {
            String str = String.valueOf("���ȼ�Ϊ"+(2*i+1)+"���߳�");
            new TP(str,g,2*i+1).start();
        }
        Thread.sleep(3000);
        g.interrupt();

    }
}

class TP extends  Thread{
    AtomicInteger a = new AtomicInteger();
    public  TP(String name,ThreadGroup tg,int pro){
        super(tg,name);
        this.setPriority(pro);

    }
    @Override
    public void run() {
        while (true){
            try {
                Thread.sleep(1);
                a.incrementAndGet();
            }catch (Exception e){
                System.out.println(Thread.currentThread().getName()+"�ۼӣ�"+a.get());
                break;
            }
        }
    }
}

// ������ ��������
//���ȼ�Ϊ5���߳��ۼӣ�2140
//���ȼ�Ϊ7���߳��ۼӣ�2294
//���ȼ�Ϊ3���߳��ۼӣ�431
//���ȼ�Ϊ1���߳��ۼӣ�139

