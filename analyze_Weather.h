/* -author   : drinksober
   -date     : 2015.04.29
   -function : analyze the weather_type for json_data that get by internet
   -parameter: pjson_waether
   -return   : weather_type
   -example  : "晴转多云"  ----- the weather type is cloud
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define weather_type_len 6
                      //type_value
                      //parameter error
                      //-2; can't match the weather
#define rain  "雨"    //1
#define sun   "晴"    //2
#define shade "阴"    //3
#define cloud "云"    //4
#define snow  "雪"    //5
#define wind  "风"    //6

static char* weather_type[weather_type_len] ={{rain},{sun},{shade},{cloud},{snow},{wind}};  // you can extend the weather type from here.

typedef struct Node
{
int type;
char weather[15];
struct Node *next;
}Lnode;

extern int Analyze_Weather(char* weather_data);
extern void printList(Lnode *head);  //打印
extern Lnode *createList();          //创建链表， 手动输入链表值
extern Lnode *insertList(Lnode *head,int elem,int position); // 插入
extern Lnode *deleteElem(Lnode *head,int elem);  //删除
extern Lnode *reverseList(Lnode *head);   //反转
extern void SaveList(Lnode* head);    //把链表数据保存为txt文件
extern Lnode *Find_Node(Lnode* head,int pos); //查找在链表中第pos个位置的结点。
Lnode *Init_Node();           //初始化链表 初值为设定的数值
int Sub_Analyze_Weather(char* data,Lnode* value);
