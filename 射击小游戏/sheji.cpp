#include <easyx.h>
#include <time.h>
#include <conio.h>

class Bullet;
class Tank;
class E_Bullet;
class Boss;
bool dead = false;
bool wined = false;
struct pos//������
{
 int a;
 int b;
};
class E_Bullet//���˴�����ӵ�
{
public:
 clock_t d;
 int x;
 int y;
 bool on = false;
 pos show()//�����µ�λ��
 {
 setfillcolor(RGB(255, 180, 20));
 fillrectangle(x - 5, y - 5, x + 5, y + 5);
 return pos{ x,y };
 }
 pos del()//����ԭ����λ��
 {
 setfillcolor(0);
 setlinecolor(0);
 fillrectangle(x - 5, y - 5, x + 5, y + 5);
 rectangle(x - 5, y - 5, x + 5, y + 5);
 return pos{ x,y };
 }
 pos move()//����
 {
 x -= 3;
 return pos{ x,y };
 }
};
class Bullet//��Ҵ�����ӵ���ͬ��
{
public:
 clock_t d;
 int x;
 int y;
 bool on = false;
 pos show()
 {
 setfillcolor(RGB(150, 180, 210));
 fillrectangle(x - 5, y - 5, x + 5, y + 5);
 return pos{ x,y };
 }
 pos del()
 {
 setfillcolor(0);
 setlinecolor(0);
 fillrectangle(x - 5, y - 5, x + 5, y + 5);
 rectangle(x - 5, y - 5, x + 5, y + 5);
 return pos{ x,y };
 }
 pos move()//����
 {
 x += 3;
 return pos{ x,y };
 }
};
class Boss//����
{
public:
 bool hurting = false;
 clock_t d_hurt;
 COLORREF clr = RGB(0, 130, 125);
 int x;
 int y;
 int hp = 100;//����
 clock_t d;//�жϾ�����һ��ִ��ĳһ�������˶��
 clock_t att_d;
 bool angle = false;//����
 pos show()
 {
 setfillcolor(clr);
 fillrectangle(x - 20, y - 40, x + 20, y + 40);
 return pos{ x,y };
 }
 pos del()
 {
 setfillcolor(0);
 setlinecolor(0);
 rectangle(x - 20, y - 40, x + 20, y + 40);
 fillrectangle(x - 20, y - 40, x + 20, y + 40);
 return pos{ x,y };
 }
 void fire(E_Bullet& but)//����
 {
 but.on = true;//����һ���ӵ�
 but.x = x - 20;
 but.y = y;
 but.d = clock();
 }
 void move()//�������µ��ƶ�
 {
 if (angle == true)
 y -= 5;
 if (angle == false)
 y += 5;
 if (y >= 440)
 angle = true;
 if (y <= 40)
 angle = false;
 }
 void hurt()//����
 {
 hp -= 4;
 d_hurt = clock();
 setfillcolor(0);
 setlinecolor(WHITE);
 fillrectangle(160, 485, 560, 510);//����Ѫ��
 rectangle(160, 485, 160 + hp * 4, 510);
 setfillcolor(RGB(230, 0, 1));
 setlinecolor(RGB(255, 255, 255));
 fillrectangle(160, 485, 160 + hp * 4, 510);
 rectangle(160, 485, 160 + hp * 4, 510);
 hurting = true;
 if (hp <= 0)//����
 {
 wined = true;
 }
 }
};
class Tank//����࣬ͬ��
{
public:
 bool hurting = false;
 int hp = 100;
 int x;
 COLORREF clr = RGB(150, 180, 210);
 int y;
 clock_t d_hurt;
 Tank() {}
 Tank(int _x, int _y) { x = _x; y = _y; }
 Tank operator=(pos p) { x = p.a; y = p.a; }
 pos show()
 {
 setfillcolor(clr);
 fillrectangle(x - 25, y - 25, x + 25, y + 25);
 setfillcolor(RGB(100, 200, 180));
 fillrectangle(x, y + 5, x + 40, y - 5);
 return pos{ x,y };
 }
 pos del()
 {
 setfillcolor(0);
 setlinecolor(0);
 fillrectangle(x - 25, y - 25, x + 25, y + 25);
 rectangle(x - 25, y - 25, x + 25, y + 25);
 fillrectangle(x, y + 5, x + 40, y - 5);
 rectangle(x, y + 5, x + 40, y - 5);
 return pos{ x,y };
 }
 void fire(Bullet& but)
 {
 but.on = true;
 but.x = x + 45;
 but.y = y;
 but.d = clock();
 but.show();
 }
 void hurt()
 {
 hp -= 2;
 d_hurt = clock();
 setfillcolor(0);
 setlinecolor(WHITE);
 fillrectangle(160, 515, 560, 540);
 rectangle(160, 515, 560, 540);
 rectangle(160, 515, 160 + hp * 4, 540);
 setfillcolor(RGB(0, 255, 1));
 setlinecolor(RGB(255, 255, 255));
 fillrectangle(160, 515, 160 + hp * 4, 540);
 rectangle(160, 515, 160 + hp * 4, 540);
 hurting = true;
 if (hp <= 0)
 dead = true;
 }
};
#define BT_MAX 8
int main()
{
 initgraph(640, 550, 4);//��ʼ����Ļ
 settextcolor(RGB(0, 254, 0));
 settextstyle(35, 0, _T("����"));
 outtextxy(150, 200, _T("W,S�ƶ�,K����"));
 Sleep(3000);
 setlinecolor(0);
 setfillcolor(0);
 rectangle(0, 0, 640, 550);
 fillrectangle(0, 0, 640, 550);
 setlinecolor(RGB(255, 255, 255));
 setfillcolor(RGB(255, 255, 255));
 clock_t delay = clock();//����ƶ�����ʱ
 clock_t d_f = clock();//��ҿ������ʱ
 line(0, 481, 640, 481);//�ָ����Ѫ��
 Bullet bt[BT_MAX];//��ҵ��ӵ�
 Tank tk(30, 30);//���
 Boss bo;//����
 bo.x = 580;
 bo.y = 240;
 E_Bullet ebt[BT_MAX];//���˵��ӵ�
 bo.d = clock();//��ʼ����ʱ
 bo.att_d = clock();
 tk.show();
 settextstyle(20, 0, _T("����"));
 outtextxy(10, 485, _T("BOSS������ֵ:"));
 setfillcolor(RGB(230, 0, 1));
 fillrectangle(160, 485, 560, 510);//����Ѫ��
 outtextxy(10, 520, _T("��ҵ�����ֵ:"));
 setfillcolor(RGB(0, 255, 1));
 fillrectangle(160, 515, 560, 540);//���Ѫ��
 while (1)//��ѭ��
 {
 if (wined || dead)//������˻��ߵ�������
 break;
 if (GetAsyncKeyState('W') & 0x8000)//����ƶ�
 {
 if (tk.y > 28 && (clock() - delay) >= 40)
 {
 tk.del(); tk.y -= 3; tk.show(); delay = clock();
 }
 }
 if (GetAsyncKeyState('w') & 0x8000)//����ƶ�
 {
 if (tk.y > 28 && (clock() - delay) >= 40)
 {
 tk.del(); tk.y -= 3; tk.show(); delay = clock();
 }
 }
 if (GetAsyncKeyState('k') & 0x8000)//��ҿ���
 {
 for (int i = 0; i < BT_MAX; i++)
 {
 if (bt[i].on == false && (clock() - d_f) > 800)
 {
  bt[i].on = true;
  tk.fire(bt[i]);
  d_f = clock();
  break;
 }
 }
 }
 if (GetAsyncKeyState('K') & 0x8000)//��ҿ���
 {
 for (int i = 0; i < BT_MAX; i++)
 {
 if (bt[i].on == false && (clock() - d_f) > 800)
 {
  tk.fire(bt[i]);
  d_f = clock();
  break;
 }
 }
 }
 if (GetAsyncKeyState('S') & 0x8000)//����ƶ�
 {
 if (tk.y < 452 && (clock() - delay) >= 40)
 {
 tk.del(); tk.y += 3; tk.show(); delay = clock();
 }
 }
 if (GetAsyncKeyState('s') & 0x8000)//����ƶ�
 if (tk.y < 452 && (clock() - delay) >= 40)
 {
 tk.del(); tk.y += 3; tk.show(); delay = clock();
 }
 for (int i = 0; i < BT_MAX; i++)//�����ӵ���ʹ�ӵ�ˢ��
 {
 if (bt[i].on == true && (clock() - bt[i].d) > 20)
 {
 bt[i].del();
 bt[i].move();
 bt[i].show();
 bt[i].d = clock();
 if (bt[i].x >= 635)
  bt[i].on = false, bt[i].del();//��������Ļ���Ҷ�
 if ((bt[i].x + 5 >= bo.x - 20 && bt[i].x - 5 <= bo.x + 20) && (bt[i].y - 5 < bo.y + 40 && bt[i].y + 5 > bo.y - 40))
  //���е���
  bt[i].on = false, bo.hurt(), bt[i].del();
 }
 }
 if (clock() - bo.att_d > 700)//�����Զ�����
 {
 for (int i = 0; i < BT_MAX; i++)
 {
 if (ebt[i].on == false)
 {
  bo.fire(ebt[i]); break;
 }
 }
 bo.att_d = clock();
 }
 for (int i = 0; i < BT_MAX; i++)//�����ӵ�ˢ�£�ͬ��
 {
 if (ebt[i].on == true && (clock() - ebt[i].d > 20))
 {
 ebt[i].del();
 ebt[i].move();
 ebt[i].show();
 ebt[i].d = clock();
 if (ebt[i].x < 5)
  ebt[i].del(), ebt[i].on = false;
 if (ebt[i].x - 5 < tk.x + 25 && ebt[i].x + 5 > tk.x - 25 && ebt[i].y - 5 < tk.y + 25 && ebt[i].y + 5 > tk.y - 25)
 {
  ebt[i].on = false, tk.hurt(), ebt[i].del();
 }
 }
 }
 if (tk.hurting == true)//���������˸0.1��
 if (clock() - tk.d_hurt > 100)
 {
 tk.clr = RGB(150, 180, 210), tk.show(), tk.hurting = false;
 }
 else
 tk.clr = RGB(255, 0, 0), tk.show();
 if (bo.hurting == true)//����������˸0.1��
 if (clock() - bo.d_hurt > 100)
 {
 bo.clr = RGB(0, 130, 125), bo.show(), bo.hurting = false;
 }
 else
 bo.clr = RGB(0, 255, 0), bo.show();
 if (clock() - bo.d > 50)//�����ƶ���ʱ;
 bo.del(), bo.move(), bo.show(), bo.d = clock();
 }
 if (wined)//ʤ���ѷ�
 {
 settextcolor(RGB(0, 254, 0));
 settextstyle(35, 0, _T("����"));
 outtextxy(150, 200, _T("������boss!��Ӯ�ˣ���"));
 }
 else
 {
 settextcolor(RGB(254, 0, 0));
 settextstyle(35, 0, _T("����"));
 outtextxy(140, 200, _T("�㱻boss����ˣ�"));
 }
 Sleep(5000);
 closegraph();
 return 0;
}
