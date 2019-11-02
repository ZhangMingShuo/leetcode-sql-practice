# 顺序表的操作
## 按值查找
> [!NOTE]
> int LocateElem(SqList L,ElemType e){  
    for(int i=0;i<L.length;i++)  
        if(L.data[i]==e)  
            return i+1;  
    return 0;  
}  

## 插入
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

## 删除
> [!NOTE]
> bool ListDelete(SqList &L,int i,ElemType &e){  
    if(i<1||i>L.length) return false;  
    e=L.data[i-1];  
    for(int j=i;j<L.length;j++)  
        L.data[j-1]=L.data[j];  
    L.length--;  
    return true;  
}
     
ElemType DeleteMin(SqList &L){
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

## 逆置顺序表
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

## 有序表去重
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
