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
     ListIntNode *head;//ָ��ͷ���ָ��
     ListIntNode *p,*pre;
     int i;
     int temp;
     head=(ListIntNode *)malloc(sizeof(ListIntNode));//Ϊͷ�ڵ�����ڴ�ռ�
     head->next=NULL;//��ͷ����ָ�������
     pre=head;//�Ƚ�ͷ����׵�ַ�����м����pre
     for(i=1;i<=n;i++)//ͨ��forѭ�����ϼ����µĽ��
      {
       p=(ListIntNode *)malloc(sizeof(ListIntNode));//ΪҪ����Ľڵ����
       //�ڴ�ռ�pָ���²�������׵�ַ
       cin>>temp;
       p->val = temp;
       pre->next=p;//��pָ���½���������Ҳ����ͷ���ָ����ָ��
       //�¸����
       //��һ��������pָ��ģ���Ϊͷ�������Ϊ��
       pre=p;//�������ָ����һ����������
      }
     p->next=NULL;//������һ������ָ���������
     return head;//�������������׵�ַ
}

ListStringNode *CreateStringList(int n)
    {
     ListStringNode *head;//ָ��ͷ���ָ��
     ListStringNode *p,*pre;
     char temp; 
     int i;
     head=(ListStringNode *)malloc(sizeof(ListStringNode));//Ϊͷ�ڵ�����ڴ�ռ�
     head->next=NULL;//��ͷ����ָ�������
     pre=head;//�Ƚ�ͷ����׵�ַ�����м����pre
     for(i=1;i<=n;i++)//ͨ��forѭ�����ϼ����µĽ��
      {
       p=(ListStringNode *)malloc(sizeof(ListStringNode));//ΪҪ����Ľڵ����
       //�ڴ�ռ�pָ���²�������׵�ַ
       cin>>temp;
       p->val = temp;
       pre->next=p;//��pָ���½���������Ҳ����ͷ���ָ����ָ��
       //�¸����
       //��һ��������pָ��ģ���Ϊͷ�������Ϊ��
       pre=p;//�������ָ����һ����������
      }
     p->next=NULL;//������һ������ָ���������
     return head;//�������������׵�ַ
}
int main(){
	ListStringNode* a;
	ListIntNode* b;
	ListIntNode* c;
	cout<<"������A��ֵ"<<endl; 
	a = CreateStringList(5);
	cout<<"������B��ֵ"<<endl; 
	b = CreatInteList(6);
	cout<<"������C��ֵ"<<endl; 
	c = CreatInteList(8);
	//���A��ֵ
	//while(a){
	//	cout<<a<<endl;
	//	a = a->next;
	//}
	//��ӡA 
	while(a){
		cout<<a->val<<endl;
		a = a->next;
	}
	//��ӡb 
	while(b){
		cout<<b->val<<endl;
		b = b->next;
	}
	//��ӡc
	while(c){
		cout<<c->val<<endl;
		c = c->next;
	}
	 
	return 0;
}
