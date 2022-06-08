#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

int main(int argc, const char *argv[])
{
	linkstack s;
	
	s = stack_create();
	if(s == NULL)
		return -1;
	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);
	stack_push(s, 40);
	stack_push(s, 50);
#if 0 
	while(!stack_empty(s)){
		printf("pop:%d\n",stack_pop(s));
	}
#endif
	s = stack_free(s);
	return 0;
}
