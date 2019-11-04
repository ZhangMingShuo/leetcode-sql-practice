# 线性表的操作
## 顺序表
### 按值查找
> [!NOTE]
> int LocateElem(SqList L,ElemType e){  
    for(int i=0;i<L.length;i++)  
        if(L.data[i]==e)  
            return i+1;  
    return 0;  
}  

### 插入
> [!NOTE]
> bool ListInsert(SqList &L,int i,ElemType e){  
    if(i<1||i>L.length+1){  
        return false;  
    }  
    if(L.length>=MaxSize)  
        return false;  
    for(int j=L.length;j>=i;j--)  
        L.data[j]=L.data[j-1];  
    L.data[i-1]=e;  
    L.length++;  
    return true;  
}  

### 删除
> [!NOTE]
> bool ListDelete(SqList &L,int i,ElemType &e){  
    if(i<1||i>L.length) return false;  
    e=L.data[i-1];  
    for(int j=i;j<L.length;j++)  
        L.data[j-1]=L.data[j];  
    L.length--;  
    return true;  
}

### 删除最小元素
> [!NOTE]
> ElemType DeleteMin(SqList &L){  
    ElemType min=L.data[0];  
    int minloc=0;  
    for(int i=0;i<L.length;i++)  
    {  
        if(L.data[i]<min){  
            minloc=i;  
            min=L.data[i];  
        }  
    }  
    L.data[minloc]=L.data[L.length-1];  
    L.length--;  
    return min;  
}  

### 逆置顺序表
> [!NOTE]
> void ReverseSqList(SqList &L){  
    for(int i=0;i<(L.length+1)/2;i++)  
    {  
        ElemType t;  
        t=L.data[i];  
        L.data[i]=L.data[L.length-1-i];  
        L.data[L.length-1-i]=t;  
    }  
}  

### 有序表去重
> [!NOTE]
> bool Delete_Same(SqList &L){  
    if(L.length==0)return false;  
    int i=0,j;                      //i存储第一个不相同的元素，j作指针  
    for(j=1;j<L.length;j++)  
        if(L.data[i]!=L.data[j])  //查找下一个与上个元素值不同的元素  
            L.data[++i]=L.data[j];//找到后，则将元素前移  
    L.length=i+1;  
    return true;  
}  
### 将顺序表的第i到j逆置
> [!NOTE]
> void ReverseSqList(SqList &L,int m,int n){  
    for(int i=m;i<m+(n-m+1)/2;i++)  
    {  
        ElemType t;  
        t=L.data[i];  
        L.data[i]=L.data[n+m-i];  
        L.data[n+m-i]=t;  
    }  
}  

### 循环左移p
> [!NOTE]
> void LeftShift(SqList &L,int p){  
    ReverseSqList(L,0,p-1);  
    ReverseSqList(L,p,L.length-1);  
    ReverseSqList(L,0,L.length-1);  
} 

## 链表

### 定义
> [!NOTE]
> typedef int ElemType;  
typedef struct LNode{  
    ElemType data;  
    struct LNode *next;   
}LNode,*LinkList;  
 
### 头插法建立单链表
> [!NOTE]
> LinkList CreateList(LinkList &L){  
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

### 尾插法建立单链表
> [!NOTE]
> LinkList Create_tail_List(LinkList &L){  
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

### 插入元素
> [!NOTE]
> bool InsertList(LinkList &L,ElemType e){  
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

### 获取第i个元素
> [!NOTE]
> LNode *GetElem(LinkList L,int i){  
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

### 按值查找元素
> [!NOTE]
> LNode *Search(LinkList L,ElemType e){  
    LNode *p = L->next;  
    while(p!=NULL && p->data!=e){  
        p=p->next;   
    }  
    return p;  
} 

### 在第i个位置插入元素
> [!NOTE]
> bool ListFrontInsert(LinkList L,int i,ElemType e){  
    LNode* p = GetElem(L,i-1);  
    if(p==NULL)  
        return false;  
    LNode *s=(LNode*)malloc(sizeof(LNode));  
    s->data=e;  
    s->next=p->next;  
    p->next=s;  
    return true;  
} 

### 打印链表
> [!NOTE]
> void PrintList(LinkList L)  
{  
    L=L->next;  
    while(L!=NULL){  
        printf("%d   ",L->data);  
        L=L->next;   
    }  
    printf("\n");  
}

### 删除第i个元素
> [!NOTE]
> bool ListDelete(LinkList L,int i){  
    LNode*p=GetElem(L,i-1);  
    LNode*q;  
    q=p->next;  
    p->next=q->next;  
    free(q);  
    return true;  
}  

### 设计一个递归算法删除不带头结点的单链表的所有值为x的结点
> [!NOTE]
> void Del_X_3(LinkList &L,ElemType x){  
    LNode *p;  
    if(L==NULL) return;  
    if(L->data==x){  
        p=L;  
	L=L->next;  
	free(P);  
	Del_X_3(L->next,x);  
    }else{  
        Del_X_3(L->next,x);   
    }
}  
