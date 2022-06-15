#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"
linkqueue * queue_create(){
	linkqueue * lq;
	if((lq = (linkqueue *)malloc(sizeof(linkqueue))) == NULL){
		printf("malloc linkqueue falied\n");
		return NULL;
	}
	lq->front = lq->rear = (linklist )malloc(sizeof(listnode));//要么一起成功要么一起失败，只需要判断其中一个是否为空就行
	if(lq->front == NULL){
	printf("malloc node failed\n");
	free(lq);
	lq = NULL;
	return NULL;
	}
	lq->front->data = 0;
	lq->front->next = NULL;
	return lq;
}
int enqueue(linkqueue *lq, datatype x){
	if(lq == NULL){
		printf("lq is NULL\n");
		return -1;
	}
	linklist p;
	if((p = (linklist)malloc(sizeof(listnode))) == NULL){
		printf("malloc node failed\n");
		return -1;
	}
	p->data = x;
	p->next = NULL;
	lq->rear->next = p;
	lq->rear = p;
	return 0;
}
datatype dequeue(linkqueue *lq){
	if(lq == NULL){
		printf("lq is NULL\n");
		return NULL;
	}
	linklist p;
	p = lq->front;
	lq->front = p->next;
	free(p);
	p = NULL;
	return (lq->front->data);//释放的是头结点，front从指向头指点变为指向队头

}
int queue_show(linkqueue *lq){
	if(lq == NULL){
		printf("lq is NULL\n");
		return -1;
	}
	linklist q;
	q = lq->front->next;
	while(q != lq->rear->next){
	//	printf("%d\n",q->data);
		q = q->next;
	}
		return 0;
}
int queue_empty(linkqueue *lq){
	if(lq == NULL){
		printf("lq is NULL\n");
		return -1;
	}
	return ( lq->front == lq->rear ? 1 : 0 );
}
int queue_clear(linkqueue *lq){
	if(lq == NULL){
		printf("lq is NULL\n");
		return -1;
	}
	linklist p;
	while(lq->front->next){
		p = lq->front;
		lq->front = p->next;
	//	printf("clear:%d\n",p->data);
		free(p);
		p = NULL;
	}
	return 0;
}
linkqueue * queue_free(linkqueue *lq){
	if(lq == NULL){
		printf("lq is NULL\n");
		return NULL;
	}
	linklist p;
	while(lq->front != lq->rear->next){
		p = lq->front;
		lq->front = lq->front->next;
	//	printf("free:%d\n",p->data);
		free(p);
	}
	free(lq);
	lq = NULL;
	return NULL;

}
