public class Oo01{
	public static void main(String[] args){
		//����һ���ɷ����
        Husband huangyifeng = new Husband();
		huangyifeng.name = "��߮��";
		//����һ�����Ӷ���
		Wife luomingli = new Wife();
		luomingli.name = "����ٳ";
		//���[�ܹ�ͨ���ɷ��ҵ����ӣ�Ҳ�ܹ�ͨ�������ҵ��ɷ�]
		huangyifeng.w = luomingli;
		luomingli.h = huangyifeng;
		System.out.println(huangyifeng.name + "�����ŽУ�" + huangyifeng.w.name);
		System.out.println(luomingli.name + "���ɷ�У�" + luomingli.h.name);
        
	}
}
