#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

ListNode *CreateList(int n)
    {
     ListNode *head;//指向头结点指针
     ListNode *p,*pre;
     int i;
     head=(ListNode *)malloc(sizeof(ListNode));//为头节点分配内存空间
     head->next=NULL;//将头结点的指针域清空
     pre=head;//先将头结点首地址赋给中间变量pre
     for(i=1;i<=n;i++)//通过for循环不断加入新的结点
      {
       p=(ListNode *)malloc(sizeof(ListNode));//为要插入的节点分配
       //内存空间p指向新插入结点的首地址
       p->val = 0;
       pre->next=p;//将p指向新结点插入链表也就是头结点指针域指向
       //下个结点
       //第一个结点就是p指向的，因为头结点内容为空
       pre=p;//这个起着指向下一个结点的作用
      }
     p->next=NULL;//最后将最后一个结点的指针域清空了
     return head;//返回这个链表的首地址
}

int main(){
	ListNode a1;
	ListNode a2;
	ListNode a3;
	ListNode b1;
	ListNode b2;
	ListNode b3;
	ListNode* l1;
	ListNode* l2;
	ListNode* sum;
	a1.val = 2;
	a2.val = 4;
	a3.val = 3;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;
	b1.val = 5;
	b2.val = 6;
	b3.val = 4;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;
	l1 = &a1;
	l2 = &b1;
	int a=0,b=0;
	int aNumber=1,bNumber=1;
	//获得A的值
	while(l1){
		//cout<<(*l1).val<<endl;
		a=a+(*l1).val*aNumber;
		//cout<<a<<endl;
		aNumber = aNumber * 10;
		l1 = l1->next;
	}
	//获得B的值 
	while(l2){
		//cout<<(*l2).val<<endl;
		b=b+(*l2).val*bNumber;
		bNumber = bNumber * 10;
		l2 = l2->next;
	}
	int sum=0;
	sum = a + b;
	//cout<<"sum="<<sum<<"||a="<<a<<"||b="<<b<<endl;
	//输出十进制的数 
	//cout<<"[";
	//while(sum/10!=0){
	//	cout<<sum%10<<",";
	//	sum = sum/10;
	//}
	//cout<<sum<<"]";
	//输出链表
	 
	return 0;
}
