#include<cstring>
#include "dev.h"
#include <cstdlib>
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL) {
        L.elem = (ElemType *) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = 100;
        return OK;
    }
    else return INFEASIBLE;

    /********** End **********/
}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem==NULL){
        return INFEASIBLE;
    }
    else{
        free(L.elem);
        L.elem = NULL;
        return OK;
    }

    /********** End **********/
}

status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        free(L.elem);
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }

    /********** End **********/
}
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        if(L.length == 0) return TRUE;
        else return FALSE;
    }

    /********** End **********/
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else return L.length;

    /********** End **********/
}

status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        if(i<1||i>L.length) return ERROR;
        else{
            e = L.elem[i-1];
            return OK;
        }
    }

    /********** End **********/
}


status LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        for(int i=0;i<L.length;i++){
            if(e == L.elem[i]){
                return i+1;
            }
        }
        return ERROR;
    }

    /********** End **********/
}


status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        for(int i=0;i<L.length;i++){
            if(e==L.elem[i]){
                if(i==0) return ERROR;
                else{
                    pre = L.elem[i-1];
                    return OK;
                }
            }
        }
        return ERROR;
    }

    /********** End **********/
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        for(int i=0;i<L.length;i++){
            if(e==L.elem[i]){
                if(i==L.length-1) return ERROR;
                else{
                    next = L.elem[i+1];
                    return OK;
                }
            }
        }
        return ERROR;
    }

    /********** End **********/
}


status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        if(L.length==0){
            L.elem[0] = e;
            L.length++;
            return OK;
        }
        if(i<1||i>L.length+1) return ERROR;
        if(L.length == L.listsize){
            L.elem = (ElemType *)realloc(L.elem,sizeof(ElemType)*(L.listsize+LISTINCREMENT));
            L.listsize = L.listsize+LISTINCREMENT;

        }
        if(i==L.length+1){
            L.elem[L.length] = e;
            L.length++;
            return OK;
        }
        for(int j=L.length-1;j>=i-1;j--){
            L.elem[j+1] = L.elem[j];
        }
        L.elem[i-1] = e;
        L.length++;
        return OK;
    }

    /********** End **********/
}


status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        if(i<1||i>L.length) return ERROR;
        else{
            e = L.elem[i-1];
            for(int j=i-1;j<L.length;j++){
                L.elem[j] = L.elem[j+1];
            }
            L.length--;
            return OK;
        }
    }
    /********** End **********/
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        for(int i=0;i<L.length;i++){
            if(i==L.length-1) {printf("%d", L.elem[i]); return OK;}
            printf("%d ", L.elem[i]);
        }
        printf("\n");
        return OK;
    }

    /********** End **********/
}

status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        FILE *fp;
        fp = fopen(FileName, "w");
        for(int i=0;i<L.length;i++){
            fputc(L.elem[i],fp);
        }
        fclose(fp);
        return OK;
    }

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL) return INFEASIBLE;
    else{
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize = LIST_INIT_SIZE;
        FILE *fp;
        fp = fopen(FileName, "r");
        int i=0;
        while(!feof(fp)){
            int a = fgetc(fp);
            if(feof(fp)) return OK;
            if(L.length==L.listsize){
                L.elem = (ElemType *)realloc(L.elem, sizeof(ElemType)*(L.listsize+LISTINCREMENT));
                L.listsize = L.listsize+LISTINCREMENT;
            }
            L.elem[i++] = a;
            L.length++;
        }
        fclose(fp);
        L.length--;
        return OK;
    }

    /********** End **********/
}


status Add_to_Lists(LISTS &Lists,char ListName[], SqList L)
// 在Lists中增加一个名称为ListName的空线性表，从L中导入数据
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //初始化
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L.elem = (ElemType *)malloc(sizeof(ElemType)*L.length);
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;


    //添加数据
    Lists.elem[Lists.length].L.length= L.length;
    Lists.elem[Lists.length].L.listsize= L.listsize;
    for (int i=0;i<L.length;i++){
        Lists.elem[Lists.length].L.elem[i]= L.elem[i];
    }
    Lists.length ++;
    return 1;
    /********** End **********/
}


status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name, ListName)==0){
            for(int j=i;j<Lists.length-1;j++){
                strcpy(Lists.elem[j].name, Lists.elem[j+1].name);
                Lists.elem[j].L.elem = Lists.elem[j+1].L.elem;
                Lists.elem[j].L.length = Lists.elem[j+1].L.length;
                Lists.elem[j].L.listsize = Lists.elem[j+1].L.listsize;
            }
            Lists.length--;
            return 1;
        }
    }
    return 0;

    /********** End **********/
}


int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name, ListName)==0){
            return i+1;
        }
    }
    return 0;

    /********** End **********/
}

void showlist(LISTS LISTS){
    printf("there are %d lists\n", LISTS.length);
    for(int i=0;i<LISTS.length;i++){
        printf("%s:", LISTS.elem[i].name);
        for (int j = 0; j < LISTS.elem[i].L.length; ++j) {
            printf("%d ",LISTS.elem[i].L.elem[j]);
        }
        printf("\n");

    }
}

void merge(ElemType *arr, int start, int mid, int end){
    /*
     * function：对两个数组进行排序，两个数组连续存储，由mid分开
     * input:
     * arr: 待排序的数组
     * mid：数组中间位置元素的下标
     * end：数组末尾元素的下标
     */
    int i=start,j=mid+1,k=0;
    ElemType *temp;
    temp = (ElemType *)malloc(sizeof(ElemType) * (end+1));  //暂时存储新数组
    while (i<=mid&&j<=end){  //对两个数组从第一个元素开始进行比较
        if (arr[i]<arr[j]){
            temp[k] = arr[i];
            k++;i++;
            continue;
        }
        else if (arr[i]==arr[j]){
            temp[k] = arr[i];
            k++;
            temp[k] = arr[j];
            k++;
            i++;j++;
            continue;
        }
        else{
            temp[k] = arr[j];
            k++;j++;
            continue;
        }
    }

    while (i<=mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j<=end){
        temp[k] = arr[j];
        k++;j++;
    }

    for (j=0, i=start;j<k;j++,i++){  //将新数组复制给原数组
        arr[i] = temp[j];
    }
}


void Merge_sort(ElemType *arr, int start, int end){
    //用递归的方法实现归并排序
    /*
     * input：
     * arr: 待排序的数组
     * start: 数组的首元素的下标
     * end：数组的最后一个元素的下标
     */
    if (start>=end)
        return;  //结束条件
    int mid = (start+end)/2;
    Merge_sort(arr, start, mid);
    Merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

status Load_from_Lists(LISTS &Lists, char ListName[], SqList &L){
    /*
     * function：从多线性表导入指定名字的线性表
     * input:
     * Lists: 多线性表对象
     * ListName: 指定的线性表名字
     * L：线性表
     */
    for(int i=0;i<Lists.length;i++){
        if(strcmp(Lists.elem[i].name, ListName)==0){
            L.length = Lists.elem[i].L.length;
            L.listsize = Lists.listsize;
            L.elem = (ElemType *)malloc(sizeof(ElemType)*L.length);
            for (int j=0;j<Lists.elem[i].L.length;j++){
                L.elem[j] = Lists.elem[i].L.elem[j];
            }
            return 1;
        }
    }
    return 0;
}