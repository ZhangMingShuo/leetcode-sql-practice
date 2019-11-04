#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 头插法建立单链表
 * */
LinkList CreateList(LinkList &L){
    LNode *s;ElemType x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}
/*
 * 尾插法建立单链表
 * 
 */
LinkList Create_tail_List(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    int x;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
   	s->data=x;
	r->next=s;
	r=s;
	scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
bool InsertList(LinkList &L,ElemType e){
    /*
    头插法插入元素e
    LNode *s =(LNode*)malloc(sizeof(LNode));
    s->next = L->next;
    L->next = s;
    s->data = e;
    return true;
    */
    LNode *r=L;
    LNode *s =(LNode*)malloc(sizeof(LNode));
    while(r->next!=NULL){
	r=r->next;
    }    
    s->data=e;
    r->next=s;
    s->next=NULL;
}
LNode *GetElem(LinkList L,int i){
    if(i<0) return NULL;
    if(i==0) return L;
    int j=1;
    LNode *p = L->next;
    while(p!=NULL && j<i){
        p = p->next;
        j++;
    }
    return p;
}
LNode *Search(LinkList L,ElemType e){
    LNode *p = L->next;
    while(p!=NULL && p->data!=e){
        p=p->next;
    }
    return p;
}
bool ListFrontInsert(LinkList L,int i,ElemType e){
    LNode* p = GetElem(L,i-1);
    if(p==NULL)
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
void PrintList(LinkList L)
{
    L=L->next;
    while(L!=NULL){
        printf("%d   ",L->data);
        L=L->next;
    }
    printf("\n");
}
bool ListDelete(LinkList L,int i){
    LNode*p=GetElem(L,i-1);
    LNode*q;
    q=p->next;
    p->next=q->next;
    free(q);
    return true;
}
bool ListDeleteSame(LinkList &L){
    LNode *p=L->next;
    LNode *q;//q point to ptr prior
    LNode *ptr;//scan all nodes ptr after p
    while(p!=NULL){
        q=p;
	ptr=p->next;
	while(ptr!=NULL){
	    if(ptr->data==p->data){
		q->next=ptr->next;
		free(ptr);
		ptr=q->next;
	    }else{
		q=q->next;
		ptr=ptr->next;
	    }
	}
	p=p->next;
    }
}
LinkList Merge(LinkList La,LinkList Lb){
    LinkList Lc;
    LNode *pa,*pb,*pc,*ptr;
    Lc=La;
    pc=La;
    pa=La->next;
    pb=Lb->next;
    while(pa!=NULL&&pb!=NULL){
	if(pa->data<pb->data){//insert pa after pc
            pc->next=pa;
   	    pc=pa;
	    pa=pa->next;
	}else if(pa->data>pb->data){
	    pc->next=pb;
	    pc=pb;
	    pb=pb->next;
	}else{
	    pc->next=pa;
	    pc=pa;
	    pa=pa->next;
	    ptr=pb;
            pb=pb->next;
	    free(ptr);
	}
    }
    if(pa!=NULL)
	pc->next=pa;
    else 
	pc->next=pb;
    free(Lb);
    return Lc;
}
int ListLength(LinkList L){
    if(L->next==NULL)
	return 0;
    int length=0;
    while(L->next!=NULL){
	L=L->next;
	length++;	
    }
    return length;
}
int main(){
    LinkList L,L1,L2;
    Create_tail_List(L);
    Create_tail_List(L1);
    cout<<ListLength(L1)<<endl;
    ListDeleteSame(L);
    PrintList(L);
    int num;
    cout<<"请输入元素序号"<<endl;
    cin>>num;
    printf("%d \n",GetElem(L,num)->data);
    cout<<"请输入查找元素的值"<<endl;
    cin>>num;
    cout<<Search(L,num)->data;
    cout<<"请输入元素的位置和值"<<endl;
    int loc;cin>>loc;
    ElemType e;cin>>e;
    ListFrontInsert(L,loc,e);
    PrintList(L);
    cout<<"请输入待删除元素位置"<<endl;
    cin>>num;
    ListDelete(L,num);
    PrintList(L);
    return 0;
}
