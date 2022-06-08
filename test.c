#include<stdio.h>
#include"sqstack.h"
#include<stdlib.h>

int main(int argc, const char *argv[])
{
	sqstack *s;
	s = stack_create(100);
	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);
	stack_push(s, 40);
	stack_push(s, 50);
	if(s == NULL)
	return -1;
	while(!stack_empty(s)){
		printf("pop:%d ",stack_pop(s));
	}
     puts("");
	 stack_free(s);
	return 0;
}
