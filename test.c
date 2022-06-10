#include<stdio.h>
#include<stdlib.h>
#include"linkqueue.h"

int main(int argc, const char *argv[])
{
	linkqueue *lq;	
	lq = queue_create();
	if(lq == NULL )
		return -1;
	enqueue(lq, 10);
	enqueue(lq, 20);
	enqueue(lq, 30);
	enqueue(lq, 40);
	enqueue(lq, 50);
	queue_show(lq);	
	//while(!queue_empty(lq)){
	//	printf("dequeue:%d\n",dequeue(lq));
	//}
	queue_clear(lq);
	//lq = queue_free(lq);
	return 0;
}
