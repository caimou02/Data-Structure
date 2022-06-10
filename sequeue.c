#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequeue.h"


sequeue * queue_create(){
	sequeue *sq;
	if((sq = (sequeue *)malloc(sizeof(sequeue))) == NULL){
		printf("malloc failed\n");
		return NULL;
	}
	memset(sq->data, 0 , sizeof(sq->data));
	sq->front = sq->rear = 0;
	return sq;
}

int enqueue(sequeue * sq, datatype x){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	if((sq->rear + 1) % N == sq->front){
		printf("sequeue is full\n");
		return -1;
	}
	sq->data[sq->rear] = x;
	sq->rear = (sq->rear + 1) % N;
	return 0;
}
datatype dequeue(sequeue *sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	datatype ret;
	ret = sq->data[sq->front];
	sq->front = (sq-> front + 1) % N;
	return ret;
}
int queue_empty(sequeue * sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	return (sq->front == sq->rear ? 1 : 0);
}
int queue_full(sequeue *sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	return ((sq->rear + 1) % N == sq->front ? 1 : 0);
}
int queue_clear(sequeue *sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	sq->front = sq->rear = 0;
	return 0;
}
sequeue * queue_free(sequeue * sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return ;
	}
	free(sq);
	sq = NULL;
	return NULL;
}

int queue_show(sequeue *sq){
	if(sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	datatype i;
		i = sq->front;
	while(i != sq->rear){
		printf("%d ",sq->data[i]);
		i = (i + 1 % N);
	}
	puts("");
	return 0;
}
