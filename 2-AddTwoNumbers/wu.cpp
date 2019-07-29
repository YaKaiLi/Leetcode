#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct ListIntNode {
    int val;
    ListIntNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

struct ListStringNode {
    char val;
    ListStringNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};


ListIntNode *CreatInteList(int n)
    {
     ListIntNode *head;//指向头结点指针
     ListIntNode *p,*pre;
     int i;
     int temp;
     head=(ListIntNode *)malloc(sizeof(ListIntNode));//为头节点分配内存空间
     head->next=NULL;//将头结点的指针域清空
     pre=head;//先将头结点首地址赋给中间变量pre
     for(i=1;i<=n;i++)//通过for循环不断加入新的结点
      {
       p=(ListIntNode *)malloc(sizeof(ListIntNode));//为要插入的节点分配
       //内存空间p指向新插入结点的首地址
       cin>>temp;
       p->val = temp;
       pre->next=p;//将p指向新结点插入链表也就是头结点指针域指向
       //下个结点
       //第一个结点就是p指向的，因为头结点内容为空
       pre=p;//这个起着指向下一个结点的作用
      }
     p->next=NULL;//最后将最后一个结点的指针域清空了
     return head;//返回这个链表的首地址
}

ListStringNode *CreateStringList(int n)
    {
     ListStringNode *head;//指向头结点指针
     ListStringNode *p,*pre;
     char temp; 
     int i;
     head=(ListStringNode *)malloc(sizeof(ListStringNode));//为头节点分配内存空间
     head->next=NULL;//将头结点的指针域清空
     pre=head;//先将头结点首地址赋给中间变量pre
     for(i=1;i<=n;i++)//通过for循环不断加入新的结点
      {
       p=(ListStringNode *)malloc(sizeof(ListStringNode));//为要插入的节点分配
       //内存空间p指向新插入结点的首地址
       cin>>temp;
       p->val = temp;
       pre->next=p;//将p指向新结点插入链表也就是头结点指针域指向
       //下个结点
       //第一个结点就是p指向的，因为头结点内容为空
       pre=p;//这个起着指向下一个结点的作用
      }
     p->next=NULL;//最后将最后一个结点的指针域清空了
     return head;//返回这个链表的首地址
}
int main(){
	ListStringNode* a;
	ListIntNode* b;
	ListIntNode* c;
	cout<<"请输入A的值"<<endl; 
	a = CreateStringList(5);
	cout<<"请输入B的值"<<endl; 
	b = CreatInteList(6);
	cout<<"请输入C的值"<<endl; 
	c = CreatInteList(8);
	//获得A的值
	//while(a){
	//	cout<<a<<endl;
	//	a = a->next;
	//}
	//打印A 
	while(a){
		cout<<a->val<<endl;
		a = a->next;
	}
	//打印b 
	while(b){
		cout<<b->val<<endl;
		b = b->next;
	}
	//打印c
	while(c){
		cout<<c->val<<endl;
		c = c->next;
	}
	 
	return 0;
}
