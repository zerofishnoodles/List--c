#include<cstring>
#include "dev.h"
#include <cstdlib>
status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        if(L.length == 0) return TRUE;
        else return FALSE;
    }

    /********** End **********/
}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else return L.length;

    /********** End **********/
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
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
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem == NULL) return INFEASIBLE;
    else{
        FILE *fp;
        fp = fopen(FileName, "w");
//        fp = NULL;
        if (fp==NULL){
            printf("�ļ�·������");
            exit(-1);
        }
        for(int i=0;i<L.length;i++){
            fputc(L.elem[i],fp);
        }
        fclose(fp);
        return OK;
    }

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(L.elem != NULL) return INFEASIBLE;
    else{
        L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize = LIST_INIT_SIZE;
        FILE *fp;
        fp = fopen(FileName, "r");
//        fp = NULL;
        if (fp==NULL){
            printf("�ļ�·������");
            exit(-1);
        }
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
// ��Lists������һ������ΪListName�Ŀ����Ա���L�е�������
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    //��ʼ��
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L.elem = (ElemType *)malloc(sizeof(ElemType)*L.length);
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;


    //�������
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
// Lists��ɾ��һ������ΪListName�����Ա�
{
    // �������ﲹ����룬��ɱ�������
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
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    // �������ﲹ����룬��ɱ�������
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
     * function��������������������������������洢����mid�ֿ�
     * input:
     * arr: �����������
     * mid�������м�λ��Ԫ�ص��±�
     * end������ĩβԪ�ص��±�
     */
    int i=start,j=mid+1,k=0;
    ElemType *temp;
    temp = (ElemType *)malloc(sizeof(ElemType) * (end+1));  //��ʱ�洢������
    while (i<=mid&&j<=end){  //����������ӵ�һ��Ԫ�ؿ�ʼ���бȽ�
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

    for (j=0, i=start;j<k;j++,i++){  //�������鸴�Ƹ�ԭ����
        arr[i] = temp[j];
    }
}


void Merge_sort(ElemType *arr, int start, int end){
    //�õݹ�ķ���ʵ�ֹ鲢����
    /*
     * input��
     * arr: �����������
     * start: �������Ԫ�ص��±�
     * end����������һ��Ԫ�ص��±�
     */
    if (start>=end)
        return;  //��������
    int mid = (start+end)/2;
    Merge_sort(arr, start, mid);
    Merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

status Load_from_Lists(LISTS &Lists, char ListName[], SqList &L){
    /*
     * function���Ӷ����Ա���ָ�����ֵ����Ա�
     * input:
     * Lists: �����Ա����
     * ListName: ָ�������Ա�����
     * L�����Ա�
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