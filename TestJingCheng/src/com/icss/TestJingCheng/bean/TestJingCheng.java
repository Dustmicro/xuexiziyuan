package com.icss.TestJingCheng.bean;

/**
 * 这是用来创建并测试用户进程（守护进程，进程组，线程）的
 * 代码示例，不可执行仅为代码示例
 * @author HYF
 *
 */
public class TestJingCheng {
	public static void main(String[] args) {
        Thread t = new Thread(() -> {
        	/**右移数组**/
            for (int i = 0; i < 10; i++) {
                try {
                    Thread.sleep(1000);
                    System.out.println("用户线程");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        Thread tdeamon = new Thread(() -> {
            for (int i = 0; i < 100; i++) {
                try {
                    Thread.sleep(1000);
                    System.out.println("守护线程");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        // 设置线程为守护线程   ！！必须在start之前设置  否则会报错
        tdeamon.setDaemon(true);

        t.start();
        tdeamon.start();
    }

}
