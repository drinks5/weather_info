#include <stdio.h>
#include <stdlib.h>
#include "analyze_Weather.h"


int Analyze_Weather(char* weather_data)
{
    Lnode *weatherinfo;
    int flag = 0;
    weatherinfo = Init_Node();
   // printList(weatherinfo);
    if((flag = Sub_Analyze_Weather(weather_data,weatherinfo)) <= 0)
    {
	printf("flag error,type is %d\n",flag);
	return -1;
    }
    return 0;
}

Lnode *Init_Node()
{
    Lnode *head, *current, *p;
    int i;
    if((head = (Lnode *)malloc(sizeof(Lnode))) == NULL)
    {
    printf("malloc error\n");
    exit(0);
    }
    p = head;
    p->type = 1;
    strncpy(p->weather,weather_type[0],sizeof(p->weather));
;
    for(i = 1;i<weather_type_len;i++)
    {
        if((current = (Lnode *)malloc(sizeof(Lnode))) == NULL)
        {
        printf("malloc error\n");
        exit(0);
        }
        p->next = current;
        current->type = i+1;
        strncpy(current->weather,weather_type[i],sizeof(current->weather));
        current->next = NULL;
        p = p->next;
    }
    p->next = NULL;
    return head;
}
///*
int Sub_Analyze_Weather(char* data,Lnode* value)
{
    Lnode* current = value;
    char* tmp = NULL;
    int flag = 0;
    if(data == NULL || current == NULL)
    {
        return -1;
    }
    while(current != NULL)
    {
        tmp = strstr(data,current->weather);
        if(tmp != NULL)
        {
            flag = current->type;
	    printf("the matched weather = %s \n",tmp);
            return current->type;
        }
        else
        {
            current = current->next;
        }
    }
    return -2;  //can't match the weather
}
//*/
Lnode *Find_Node(Lnode* head,int pos)  //查找第pos个 结点
{
    Lnode* tmp = head;
    int count = 0;
    if(tmp == NULL || pos<=0)
    {
        return NULL;
    }
    while(tmp->next != NULL && count < pos)
    {
        count++;
        tmp = tmp->next;
    }
    if(count == pos)
    {
        printf("find sucessful and found %d", tmp->type);
        return tmp;
    }
    else
    {
        return NULL;
    }
}

void printList(Lnode *head)
{
    Lnode *p = head;

    if (p == NULL)
    {
    printf("List is empty!\n");
    return;
    }
    while (p != NULL)
    {
    printf("%d \n", p->type);
    printf("weather = %s\n",p->weather);
    p = p->next;
    }
    printf("\n");
}

Lnode *createList()
{
    Lnode *head, *current, *p;
    if((head = (Lnode *)malloc(sizeof(Lnode))) == NULL)
    {
    printf("malloc error\n");
    exit(0);
    }
    p = head;
    printf("Input Pos,weather,-1 to break:\n");
    scanf("%d %s\n",&head->type,head->weather);  //定义头结点

    if(head->type == -1)
    {
    head->next = NULL; //只有头结点的情况
    return head;
    }
    while(1)   //链表的赋值与衔接
    {
        if((current = (Lnode *)malloc(sizeof(Lnode))) == NULL)
        {
        printf("malloc error\n");
        exit(0);
        }
        p->next = current;
        scanf("%d %s\n",&current->type,current->weather);
        current->next = NULL;
        p = p->next;
        if(current->type == -1)
        {

            break;
        }
    }
    p->next = NULL;
    return head;
}
/*

Lnode *insertList(Lnode *head,int elem,int position)
{
Lnode *current, *p;
int i = position - 1;
current = head;


while (i > 0 && current->next != NULL)
{
current = current->next;
i--;
}

if (i > 0) //结点数小于输入的位置position
{
printf("Position is wrong!/n");
return head;
}

p = (Lnode *)malloc(sizeof(Lnode));
p->pos = elem;
p->next = current->next;
current->next = p;

return head;
}
/*

Lnode *deleteElem(Lnode *head,int elem)
{
Lnode *p = head;
Lnode *ptemp;
int flag = 0; //记录便表中elem的个数

while (1)
{
if (head->pos == elem) //删除头结点的情况
{
flag++;
head = head->next;
free(p);
p = head;
}
else
{
break;
}
}

while (p->next != NULL)
{
if (p->pos->pos == elem )
{
flag++;
ptemp = p->next;
if (p->next->next != NULL)
{
p->next = p->next->next;
free(ptemp);
ptemp = NULL;
}
else //最后一个结点
{
free(ptemp);
ptemp =NULL;
p->next = NULL;
break;
}
}
else //没有删除结点时，查询下一个结点
{
p = p->next;
}
}
printf("%d number '%d' was found and deleted./n", flag, elem);
return head;
}

/*
Lnode *reverseList(Lnode *head)
{
Lnode *current, *pnext, *ptemp;

current = head;
pnext = head->next;
head->next =NULL;

while (pnext != NULL)
{
ptemp = pnext->next;
pnext->next = current;
current = pnext;
pnext = ptemp;
}

head = current;
return head;
}
*/
