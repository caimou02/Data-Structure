#include <stdio.h>
#include"linklist.h"
#include<stdlib.h>


linklist list_create(){
	linklist H;
	H = (linklist)malloc(sizeof(listnode));
    if(H == NULL){
	printf("malloc failed\n");
	return H;
	}
	H->data = 0;
	H->next = NULL;//赋初值

	return H;
}

int list_tail_insert(linklist H, data_t value){
	if(H == NULL){
		printf("H is NULL\n");
	return -1;
	}

	//1 new node
	linklist p;
	if((p = (linklist)malloc(sizeof(listnode))) == NULL){
	printf("malloc failed\n");
	return -1;
	}
	p->data = value;
	p->next = NULL;
	//2 locate tail node
	linklist q;//用q来找尾节点
	q = H;
	while(q->next != NULL){
		q = q->next;//q即为链表的尾节点
	}
	
	//3 insert
	q->next = p;
	return 0;
}

int list_show(linklist H){
    if(H == NULL){
	printf("H is NULL\n");
	return -1;
	}
	linklist q;
	q = H;
	while(q->next != NULL){
	printf("%d ",q->next->data);
	q = q->next;
	}
	puts("");
	return 0;

}
linklist list_get(linklist H,int pos){
	linklist p;
	int i;
	if(H == NULL){
	printf("H is NULL\n");
	return NULL;
	}
	if(pos == -1){
	return H;
	}
	if(pos < -1){
	printf("pos is invalid\n");
	return NULL;
	}
	p = H;
	for(i = 0; i <= pos; i++){
	p = p->next;
	if(p == NULL){
	printf("pos is invalid\n");
	return NULL;
	}
	}
	return p;
}

int list_insert(linklist H, data_t value, int pos){
	if(H == NULL){
	printf("H is NULL\n");
	return -1;
	}
	linklist p;
	//1 locate node pos-1
	p = list_get(H,pos-1);
	if(p == NULL){
	return -1;
	}
	//2 new node q
	linklist q;
	if((q = (linklist)malloc(sizeof (listnode))) == NULL){
		printf("malloc failed\n");
		return -1;
	}
	//3 insert
	q->data = value;
	q->next = p->next;
	p->next = q;

	return 0;

}


int list_delete(linklist H, int pos){
	if(H == NULL){
	printf("H is NULL\n");
	return -1;
	}
	linklist q;//用来存储被删除节点的地址，方便在删除后释放内存
	linklist p;
	p = list_get(H, pos-1);
	if(p != NULL)
	q = p->next;
	if(p == NULL)//p->next == NULL 说明此时p为链表的最后一个节点，后面没有节点可删
		return -1;
    if(p->next == NULL){    //p->next == NULL 说明此时p为链表的最后一个节点，后面没有节点可删
		printf("delete pos is invalid\n");
		return -1;
	}
	p->next = p->next->next;
	if(q != NULL)
	printf("delete:%d\n",q->data);
	free(q);
	q = NULL;//杜绝野指针

	return 0;
}

linklist list_free(linklist H){
	if(H == NULL){
	printf("H is NULL\n");
	return NULL;
	}
	linklist p;

	p = H;

	while(H != NULL){
	p = H;
	H = H->next;//H 和 p指向的是同一个节点，free（p）后H也丢失目标
	printf("free:%d\n",p->data);
	free(p);
	}
	puts("");

	return NULL;

}

int list_reverse(linklist H){
	if(H == NULL){
	printf("H is NULL\n");
	return -1;
	}
	if(H->next == NULL || H->next->next == NULL){
	printf("没必要反转\n");
	return 0;
	}
	linklist p,q;
	p = H->next->next;
	H->next->next = NULL;
	while(p != NULL){
	q = p;
	p = p->next;
	q->next = H->next;
	H->next = q;
	}
	return 0;
}

linklist list_adjmax(linklist H, data_t * value){
    if(H == NULL){
	printf("H is NULL\n");
	return NULL;
	}
	if(H->next == NULL || H->next->next == NULL || H->next->next->next == NULL){
	printf("H不够长\n");
	return H;
	}
	linklist p,q,r;
	int sum;
	q = H->next;
	p = H->next->next;
	r = q;
	sum = q->data + p->data;
    while(p->next != NULL){
	p = p->next;
	q = q->next;
	if(sum < (p->data + q->data)){
		sum = p->data + q->data;
		r = q;
	}
	}
	*value = sum;
	return r;
	
}

int list_merge(linklist H1,linklist H2){
	linklist p,q,r;

	if(H1 == NULL || H2 == NULL){
	printf("H1 || H2 is NULL\n");
	}
	p = H1->next;
	q = H2->next;
	r = H1;
	H1->next = NULL;
	H2->next = NULL;
	while(p && q){
	if(p->data <= q->data){
	r->next = p;
	p = p->next;
	r = r->next;
	r->next = NULL;
	}else{
	r->next = q;
	q = q->next;
	r = r->next;
	r->next = NULL;
	}
	}
	if(p == NULL){
	r->next = q;
	}else{
	r->next = p;
	}
	return 0;
}


int list_sort(linklist H){
	if(H == NULL){
	printf("H is NULL\n");
	}
	linklist r,q,p;
	p = H->next;
	H->next = NULL;
	while(p){
	q = p;
	p = p->next;
	r = H;
	while(r->next && r->next->data < q->data){
	r = r->next;
	}
	q->next = r->next;
	r->next = q;
	}
	return 0;

}
