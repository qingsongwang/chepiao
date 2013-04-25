#include "fstream"
#include "iostream"
#include "string"
#include "time.h"
#include "iomanip"
#include "stdlib.h"
#include "windows.h"
#include "conio.h"
using namespace std;
#define NULL 0
struct date{ // 时间
int hour;
int minute;
};
class bus{
int id; //班次号
string start; //起点
string end; //终点
date ts; //发车时间
double time; //行车用时
int max; //额定载量
int order; //已定票数
public:
bus *next;
bus(){order=0;};
~bus(){};</code>
 
void input(); //录入车次信息
void load(ifstream&amp; in); //从文件中载入信息
void output(); //输出车次信息
void write(ofstream&amp; out); //写到文件中
void ordert(int n); //订票
void reordert(int n); //退票
bool judge(); //判断是否已经发车
int getid(){return id;};//获取班次
int getmax(){return max;}; //获取额定量
int gethave(){return order;}; //已定票数
string getend(){return end;}; //获取终点站
};
//从键盘录入信息
void bus::input()
{
cout&lt;&lt;"ttt请按照下面提示依次输入信息"&lt; cout&lt;&lt;"ttt请输入班次"; cin&gt;&gt;id;
cout&lt;&lt;"ttt请输入发车时间（小时 分钟）"; lab1:cin&gt;&gt;ts.hour&gt;&gt;ts.minute;
 
if(ts.hour==24&amp;&amp;ts.minute&lt;=60||ts.hour&lt;24)
{
cout&lt;&lt;"ttt请输入起点站和终点站（起点 终点）"; cin&gt;&gt;start&gt;&gt;end;
cout&lt;&lt;"ttt请输入行车所需时间"; cin&gt;&gt;time;
cout&lt;&lt;"ttt请输入额定载量"; cin&gt;&gt;max;
}
else
{
cout&lt;&lt;"ttt您输入的时间格式不对，请重新输入";
goto lab1;
}
 
}
//输出信息到显示器
void bus::output()
{
cout&lt;&lt;"tt--------------------------------------------------------"&lt; cout&lt;&lt;"tt"&lt; cout&lt;&gt;id&gt;&gt;ts.hour&gt;&gt;ts.minute&gt;&gt;start&gt;&gt;end&gt;&gt;time&gt;&gt;max;
}
//写到文件中去
void bus::write(ofstream&amp; out)
{
out&lt; }
//订票函数
void bus::ordert(int n)
{
order+=n;
}
//退票函数
void bus::reordert(int n)
{
order-=n;
}
//判断本车次是否出发
bool bus::judge()
{
SYSTEMTIME sys; //使用了windows API函数
GetLocalTime( &amp;sys );
if(sys.wHourtm_hourtm_hour==ts.hour &amp;&amp; local-&gt;tm_min&lt;=ts.minute)) return 1; //比较当前时间与发车时间,获得班次的当前状况,返回表示1班次未出发 else return 0; */ } class link{ private:bus *head; public: link() { head=new bus; head-&gt;next=NULL;
};
~link(){delete head;};
 
void input(); //录入车次信息
void append();//追加信息
void modify(); //修改车次信息
void del(); //删除车次信息
bool idfind(bus **p,int n); //根据车次查询车次是否存在
bool endfind(bus **p,string e); //根据终点查询车次是否存在
void search(); //查询车票信息
void show(); //显示所有车票信息
void order(); //订票
void reorder(); //退票
void fload(); //从文件中读取
void save(); //文件保存车票信息
void menu(); //菜单
void menu_1(); //一级子菜单
};
//录入
/*void link::input()
{
bus *p,*q;
p=q=new bus;
int n=0;
char op;
 
while(1)
{
n++;
if(n=1)
head-&gt;next=q;
else
p-&gt;next=q;
p=q;
q=new bus;
q-&gt;input();
cout&lt;&lt;"ttt如果想继续添加请输入y继续，否则退出录入"; cin&gt;&gt;op;
if(op!='y')
{
 
p-&gt;next=NULL;
menu();
break;
}
}
 
}
*/
//追加信息
void link::append()
{
bus *p=head,*q;
char op;
 
while(1)
{
 
while(p-&gt;next!=NULL)
{
p=p-&gt;next;
}
q=new bus;
cout&lt;&lt;"ttt请输入追加的信息"&lt;input();
p-&gt;next=q;
q-&gt;next=NULL;
 
cout&lt;&lt;"ttt增加信息完成";
 
cout&lt;&lt;"继续增加（Y）,否则返回主菜单"&lt;&gt;op;
 
if(op=='Y'||op=='y')
continue;
else
menu();
 
}
 
}
//显示
void link::show()
{
bus *p=head;
char op;
cout&lt;&lt;"tt 所有车次信息如下 "&lt; cout&lt;&lt;"tt--------------------------------------------------------"&lt; cout&lt;&lt;"tt班次 发车时间 起点站 终点站 行车时间 额定载量 已定票数"&lt;next-&gt;judge())
{
cout&lt;&lt;"tt--------------------------------------------------------"&lt; cout&lt;&lt;"tt"&lt; next-&gt;getid()&lt;&lt;"t此班次已经出发"&lt;next-&gt;output();
 
p=p-&gt;next;
}while(p-&gt;next!=NULL);
cout&lt;&lt;"ttt退出系统（E），或者任意键返回主菜单:"; cin&gt;&gt;op;
switch(op)
{
case 'R':menu();break;
case 'E':exit(1);
default: menu();break;
}
 
}
//修改
void link::modify()
{
int n;
bus *p=head;
cout&lt;&lt;"ttt请输入你要修改的车次"; cin&gt;&gt;n;
if(idfind(&amp;p,n))
p-&gt;next-&gt;input();
cout&lt;&lt;"ttt修改成功"&lt; cout&lt;&lt;"ttt信息更新为"&lt;next-&gt;output();
cout&lt; }
//3删除
void link::del()
{
bus *p=head,*q;
int n;
string s;
cout&lt;&lt;"ttt请输入你想删除的班次号"; cin&gt;&gt;n;
if(!idfind(&amp;p,n))
cout&lt;&lt;"ttt你要删除的数据不存在"&lt; cout&lt;&lt;"ttt确认删除？（Y/N）"; char op; cin&gt;&gt;op;
 
if(op=='Y'||op=='y')
{
 
q=p-&gt;next; //记下删除的节点位置
p-&gt;next=q-&gt;next;
delete q;
}
cout&lt;&lt;"ttt删除成功"&lt;next)
{
 
if((q-&gt;next-&gt;getid())==n)
{
 
*p=q; //标记找到的节点位置
cout&lt;&lt;"tt--------------------------------------------------------"&lt; cout&lt;&lt;"tt班次 发车时间 起点站 终点站 行车时间 额定载量 已定票数"&lt;next-&gt;output();
}
q=q-&gt;next;
flag=1;
}
return flag;
}
bool link::endfind(bus **p,string e)
{
bus *q=head;
bool flag=0;
while(q-&gt;next)
{
*p=q; //记下找到的节点位置
if(((q-&gt;next)-&gt;getend())==e)
{
 
cout&lt;&lt;"tt--------------------------------------------------------"&lt; cout&lt;&lt;"tt班次 发车时间 起点站 终点站 行车时间 额定载量 已定票数"&lt;next)-&gt;output();
}
q=q-&gt;next;
flag=1;
}
return flag;
}
//5查询车票信息
void link::search()
{
bus *p=head;
int op,n;
string s;
 
cout&lt;&lt;"ttt1.按照班次查询"&lt; cout&lt;&lt;"ttt2.按照终点查询"&lt; cout&lt;&lt;"ttt3.返回上级菜单"&lt; cout&lt;&lt;"ttt请按照提示输入...."; cin&gt;&gt;op;
 
switch(op)
{
case 1: cout&lt;&lt;"ttt请输入您要查询的班次:"; cin&gt;&gt;n;
if(!idfind(&amp;p,n))
{
cout&lt;&lt;"ttt没有找到您要查询的班次信息"&lt; }
cout&lt; case 2: cout&lt;&lt;"ttt请输入您要查询终点信息："; cin&gt;&gt;s;
if(!endfind(&amp;p,s))
{
cout&lt;&lt;"ttt没有找到您要查询的班次信息"&lt; }
cout&lt; case 3:system("cls"); menu(); break;
default:cout&lt;&lt;"ttt输入错误，感谢使用，系统自动返回主菜单!"&lt; }
}
//订票
void link::order()
{
bus *p=head;
int n;
string s;
int count;
cout&lt;&lt;"ttt请输入需要到达的终点，为您检索："; cin&gt;&gt;s;
if(!endfind(&amp;p,s))
cout&lt;&lt;"ttt找不到你要的数据"&lt;
 
cout&lt;&lt;"ttt请输入您要订购车的班次："; cin&gt;&gt;n;
 
if(!idfind(&amp;p,n))
cout&lt;&lt;"ttt找不到你要的数据"&lt;next-&gt;judge()))
{
 
cout&lt;&lt;"ttt请输入你要订购的票数:"; cin&gt;&gt;count;
 
if((p-&gt;next-&gt;gethave()+count)&lt;=p-&gt;next-&gt;getmax())
{
p-&gt;next-&gt;ordert(count);
cout&lt;&lt;"ttt订票成功，感谢您的使用"&lt; cout&lt;&lt;"ttt如需返回主菜单请按Y，否则将退出系统"; char op; cin&gt;&gt;op;
if(op=='Y'||op=='y')
{
system("cls");
menu();
}
 
}
else
cout&lt;&lt;"ttt非常抱歉，没有足够的票数";
}
else
cout&lt;&lt;"ttt你要订购的班次车已经出发"&lt; }
//
void link::reorder()
{
bus *p=head;
int n;
string s;
cout&lt;&lt;"ttt请输入你要退票的班次号："; cin&gt;&gt;n;
if(!idfind(&amp;p,n))
cout&lt;&lt;"ttt找不到你要的数据"&lt;next-&gt;judge())
{
cout&lt;&gt;count;
 
if((p-&gt;next-&gt;gethave())-count&gt;=0) //所退的票数应不小于所剩余的座位数
{
p-&gt;next-&gt;reordert(count);
cout&lt;&lt;"ttt退票成功！"&lt; }
else
cout&lt;&lt;"ttt抱歉，你只能够退票"&lt;
gethave()&lt;&lt;"张"&lt; }
else
cout&lt;&lt;"ttt你要退订的班次车已经出发";
}
void link::fload()
{
/* cout&lt;&lt;"ttt 车票管理系统 "&lt; cout&lt;&lt;"tt请先导入车次信息，请输入车次信息所在的txt文档地址"&lt; string filename;
cout&lt;&lt;"tt"; cin&gt;&gt;filename;
*/
ifstream in("abc.txt");
bus *p=head,*q;
 
while(!in.eof())
{
 
q=new bus;
q-&gt;load(in);
p-&gt;next=q;
q-&gt;next=NULL;
p=p-&gt;next;
 
}
 
cout&lt;next)
{
(p-&gt;next)-&gt;write(out);
p=p-&gt;next;
}
 
cout&lt;&lt;"ttt文件保存成功！"&lt; }
//主菜单
void link::menu()
{
SYSTEMTIME sys; //使用了windows API函数
GetLocalTime( &amp;sys );
 
cout&lt;&lt;"ttt 车票管理系统(V1.0) @HFUU "&lt; cout&lt;&lt;"ttt 当前系统时间：";
cout&lt; cout&lt;&lt;"ttt================================="&lt; cout&lt;&lt;"ttt1.车次信息操作"&lt; cout&lt;&lt;"ttt2.浏览所有班次信息"&lt; cout&lt;&lt;"ttt3.查询路线"&lt; cout&lt;&lt;"ttt4.售票"&lt; cout&lt;&lt;"ttt5.退票"&lt; cout&lt;&lt;"ttt6.导出车次信息到文本文件"&lt; cout&lt;&lt;"ttt7.退出"&lt; cout&lt;&lt;"ttt请选择。。。";
while(1)
{
char op;
op=getch();
 
cout&lt;next!=NULL)
show();
else
{
system("cls");
cout&lt; menu_1();
}
break;
case '3':search();break;
 
case '4':order();break;
case '5':reorder();break;
case '6' :save();break;
case '7':break;
default:cout&lt;&lt;"ttt输入数据错误，感谢使用，系统自动退出！";break;
 
}
}
}
//选项1的二级菜单
void link::menu_1()
{
cout&lt; cout&lt;&lt;"ttt1.从文件中载入信息"&lt; cout&lt;&lt;"ttt2.追加车次信息"&lt; cout&lt;&lt;"ttt3.修改车次信息"&lt; cout&lt;&lt;"ttt4.删除车次信息"&lt; cout&lt;&lt;"ttt5.返回上级菜单"&lt; cout&lt;&lt;"ttt6.退出系统"&lt; cout&lt;&lt;"ttt请选择。。。";
 
while(1)
{
char op;
 
op=getch();
cout&lt; if(op=='27')
break;
else
switch(op)
{
 
case '1':fload();break;
case '2':append();break;
case '3':modify();break;
case '4':del();break;
case '5':system("cls");menu();break;
case '6':break;
 
default:menu();break;
}
 
}
}
void main()
{
link b;
system("cls");
system("color f1");
b.fload();
b.menu();
 
}
