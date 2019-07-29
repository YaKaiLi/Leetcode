#include<stdio.h>
#include<stdlib.h>
 
//******�궨���������******
#define DATA_SIZE 200
#define EXTEND_DATA_SIZE 50
#define NO 0
#define OK 1
#define ERROR -1
 
//******�����������ͱ���******
typedef int Status;
typedef char Excelelem;
typedef int Numelem;
 
//******�������ݽṹ******
typedef struct Node
{
	Excelelem book;
	struct Node *next;
}Liststruct;
 
/******�����ͷ��Ϣ******/
typedef struct
{
	Excelelem book[100]; //��ͷ��Ϣ
	Liststruct *next;
	Numelem Length;
}ListHead;
 
//******��ʼ������******
Liststruct *init(int *i)
{
	Liststruct *Head,*p,*q;
	Excelelem ch;
	Head=q=NULL;
	printf("������˳���Head������:\n");
	while((ch=getchar())!='\n')
	{
		p=(Liststruct *)malloc(sizeof(Liststruct));
		p->book=ch;
		if(!(*i)) Head=q=p,(*i)++;
		else
		{
			q->next=p;
			q=p;
			(*i)++;
		}
	}//ע��*q++��(*q)++,������
	if(q) q->next=NULL;
	return Head;
}
 
ListHead *Headinit()
{
	ListHead *Head;
	Head=(ListHead *)malloc(sizeof(ListHead));
	Head->Length=0;
	Head->next=init(&Head->Length);
	return Head;
}
 
/******��ӡ������������******/
void DATA_cout(ListHead *Head)
{
	Liststruct *p=Head->next;
	while(p!=NULL)
	{
		printf("%c",p->book);
		p=p->next;
	}
	printf("\n");
	return ;
}
 /******��ӡ����localλ��Ԫ������******/
void Local(ListHead* Head,int local)
{
	if(Head->Length<local || local<1)
	{
		printf("���棡������%dλ�õ�Ԫ��\n",local);
		return ;
	}
	Liststruct *p=Head->next;
	int i=1;
	while(p && i++!=local)
		p=p->next;
	printf("%c\n",p->book);
	return ;
}
 
/******�ҵ����г��ֵ��ַ�ch��λ��******/
void DATA_find(ListHead* Head,char ch)
{
	int i=1,flag=0,count=1;
	Liststruct *p=Head->next;
	while(p)
	{
		if(p->book==ch)
		{
			flag=1;
			printf("%d.�ڵ�%d��λ�ó���Ԫ��%c\n",count++,i,ch);
		}
		p=p->next;
		i++;
	}
	if(!flag)
		printf("δ���ҵ�%cԪ�أ�\n",ch);
	return ;
}
 
/******�ڵ�k��Ԫ��ǰ����һ��Ԫ��******/
void DATA_Insert(ListHead *Head,int k,Excelelem ch)
{
	if(Head->Length<k || k<1)
	{
		printf("���棡������%dλ�õ�Ԫ��\n",k);
		return ;
	}
	Liststruct *p=Head->next,*q,*t;
	int i=1;
	while(p && i++!=k)
		t=p,p=p->next;
	q=(Liststruct *)malloc(sizeof(Liststruct));
	q->book=ch;
	if(k==1)
	{
		Head->next=q;
		q->next=p;
	}
	else
	{
		q->next=p;
		t->next=q;
	}
	Head->Length++;
	return ;
}
 
/******ɾ����k��Ԫ��******/
void DATA_Delete(ListHead *Head,int k)
{
	if(Head->Length<k || k<1)
	{
		printf("���棡������%dλ�õ�Ԫ��\n",k);
		return ;
	}
	int i=1;
	Liststruct *p=Head->next,*q;
	while(p && i++!=k)
		q=p,p=p->next;
	if(k==1)
		Head->next=p->next;
	else
		q->next=p->next;
	free(p);
	Head->Length--;
	return ;
}
 
/******��������******/
void DATA_UN(ListHead *Head)
{
	Liststruct *p,*q;
	p=Head->next;
	Head->next=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		q->next=Head->next;
		Head->next=q;
	}
	return ;
}
 
/******�����ڴ�******/
void List_FREE(ListHead *Head)
{
	Liststruct *p=Head->next,*q;
	free(Head);
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	return ;
}
 
int main()
{
	ListHead *Head;
	Numelem i;
	Excelelem ch;
	puts("");
	puts("******�ȴ�����Head��ʼ��!******");
	Head=Headinit();
	puts("******����Head��ʼ�����!******");
	printf("�����е�����Ϊ:\n");
	DATA_cout(Head);
	printf("����Head�ĳ���Ϊ:\n");
	printf("%d\n",Head->Length);
	printf("�����%d��Ԫ����:\n",i=2);
	Local(Head,i);
	printf("�����г���%cԪ�ص�λ�÷ֱ���:\n",ch='6');
	DATA_find(Head,ch);
	printf("������ĵ�%d��Ԫ��֮ǰ����%c\n",i=4,ch='9');
	DATA_Insert(Head,i,ch);
	printf("�����е�����Ϊ:\n");
	DATA_cout(Head);
	printf("�������е�%d��Ԫ��ɾ��\n",i=3);
	DATA_Delete(Head,i);
	printf("�����е�����Ϊ:\n");
	DATA_cout(Head);
	printf("����������Ԫ�����ã����Ժ�...\n\n");  //���ַ���
	DATA_UN(Head);
	printf("�����е�����Ϊ:\n");
	DATA_cout(Head);
	puts("******����Headʹ�����!******\n");
	List_FREE(Head);
	return 0;
}
 

