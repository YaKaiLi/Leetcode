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
     ListNode *head;//ָ��ͷ���ָ��
     ListNode *p,*pre;
     int i;
     head=(ListNode *)malloc(sizeof(ListNode));//Ϊͷ�ڵ�����ڴ�ռ�
     head->next=NULL;//��ͷ����ָ�������
     pre=head;//�Ƚ�ͷ����׵�ַ�����м����pre
     for(i=1;i<=n;i++)//ͨ��forѭ�����ϼ����µĽ��
      {
       p=(ListNode *)malloc(sizeof(ListNode));//ΪҪ����Ľڵ����
       //�ڴ�ռ�pָ���²�������׵�ַ
       p->val = 0;
       pre->next=p;//��pָ���½���������Ҳ����ͷ���ָ����ָ��
       //�¸����
       //��һ��������pָ��ģ���Ϊͷ�������Ϊ��
       pre=p;//�������ָ����һ����������
      }
     p->next=NULL;//������һ������ָ���������
     return head;//�������������׵�ַ
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
	//���A��ֵ
	while(l1){
		//cout<<(*l1).val<<endl;
		a=a+(*l1).val*aNumber;
		//cout<<a<<endl;
		aNumber = aNumber * 10;
		l1 = l1->next;
	}
	//���B��ֵ 
	while(l2){
		//cout<<(*l2).val<<endl;
		b=b+(*l2).val*bNumber;
		bNumber = bNumber * 10;
		l2 = l2->next;
	}
	int sum=0;
	sum = a + b;
	//cout<<"sum="<<sum<<"||a="<<a<<"||b="<<b<<endl;
	//���ʮ���Ƶ��� 
	//cout<<"[";
	//while(sum/10!=0){
	//	cout<<sum%10<<",";
	//	sum = sum/10;
	//}
	//cout<<sum<<"]";
	//�������
	 
	return 0;
}
