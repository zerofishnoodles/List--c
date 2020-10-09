#include<cstring>
#include "dev.h"

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


status AddList(LISTS &Lists,char ListName[], char FileName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，从L文件中导入数据
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //初始化
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;


    //添加数据
    FILE *fp;
    fp = fopen(FileName, "r");
    int i=0;
    while (!feof(fp)){
        int a = fgetc(fp);
        if(feof(fp)) break;
        ListInsert(Lists.elem[Lists.length].L, i++, a);
    }
    fclose(fp);
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
        printf("%s\n", LISTS.elem[i].name);
    }
}