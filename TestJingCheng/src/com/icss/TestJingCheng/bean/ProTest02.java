package com.icss.TestJingCheng.bean;

/**
 * 更改用户进程数组，测试进程组优先级
 * @author HYF
 *
 */
public class ProTest02 {
    public static void main(String[] args) throws InterruptedException {
        ThreadGroup g = new ThreadGroup("测试分组");
        // 4个线程  优先级：1 3 5 7
        for (int i = 0; i < 4; i++) {
            String str = String.valueOf("优先级为"+(2*i+1)+"的线程");
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
                System.out.println(Thread.currentThread().getName()+"累加："+a.get());
                break;
            }
        }
    }
}

// 输出结果 （不定）
//优先级为5的线程累加：2140
//优先级为7的线程累加：2294
//优先级为3的线程累加：431
//优先级为1的线程累加：139

