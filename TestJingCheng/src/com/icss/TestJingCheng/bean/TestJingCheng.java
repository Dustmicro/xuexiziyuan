package com.icss.TestJingCheng.bean;

/**
 * �������������������û����̣��ػ����̣������飬�̣߳���
 * ����ʾ��������ִ�н�Ϊ����ʾ��
 * @author HYF
 *
 */
public class TestJingCheng {
	public static void main(String[] args) {
        Thread t = new Thread(() -> {
        	/**��������**/
            for (int i = 0; i < 10; i++) {
                try {
                    Thread.sleep(1000);
                    System.out.println("�û��߳�");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        Thread tdeamon = new Thread(() -> {
            for (int i = 0; i < 100; i++) {
                try {
                    Thread.sleep(1000);
                    System.out.println("�ػ��߳�");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        // �����߳�Ϊ�ػ��߳�   ����������start֮ǰ����  ����ᱨ��
        tdeamon.setDaemon(true);

        t.start();
        tdeamon.start();
    }

}
