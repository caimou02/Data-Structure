#include <stdio.h>
#include"linklist.h"
void test_get();
void test_insert();
void test_delete();
void test_reverse();
void test_adjmax();
void test_merge();
void test_sort();
int main(int argc, const char *argv[])
{
	test_sort();
	return 0;
}

void test_get(){
	linklist H;
	int value;

	H = list_create();
	if(H == NULL)
	return ;

	printf("Input:");
	while(1){
	scanf("%d",&value);
	if(value == -1)
		break;
	list_tail_insert(H, value);
	printf("Input:");
	}
	list_show(H);
	linklist p;
	p = list_get (H,4);//H = 1,3,5,7
	if(p != NULL)
	printf("%d\n",p->data);
	H = list_free(H);
}

void test_insert(){
	linklist H;
	int value;

	H = list_create();
	if(H == NULL)
	return ;

	printf("Input:");
	while(1){
	scanf("%d",&value);
	if(value == -1)
		break;
	list_tail_insert(H, value);
	printf("Input:");
	}
	list_show(H);
	list_insert(H, 10, 3);
	list_show(H);
	H = list_free(H);



}

void test_delete(){
	linklist H;
	int value;

	H = list_create();
	if(H == NULL)
	return ;

	printf("Input:");
	while(1){
	scanf("%d",&value);
	if(value == -1)
		break;
	list_tail_insert(H, value);
	printf("Input:");
	}
	list_show(H);
	list_delete(H, -2);
	list_show(H);
	H = list_free(H);


}

void test_reverse(){
	linklist H;
	int value;

	H = list_create();
	if(H == NULL)
	return ;

	printf("Input:");
	while(1){
	scanf("%d",&value);
	if(value == -1)
		break;
	list_tail_insert(H, value);
	printf("Input:");
	}
	list_show(H);
	list_reverse(H);
	list_show(H);
	H = list_free(H);

}

void test_adjmax(){
	linklist H,q;
	int value;
	int  sum;

	H = list_create();
	if(H == NULL)
	return ;

	printf("Input:");
	while(1){
	scanf("%d",&value);
	if(value == -1)
		break;
	list_tail_insert(H, value);
	printf("Input:");
	}
	list_show(H);
	q = list_adjmax(H, &sum);
	if(q != NULL && q != H){
	printf("%d\n",q->data);
	printf("sum is:%d\n",sum);
	}
	H = list_free(H);
	q = list_free(q);

}

void test_merge(){
	linklist H1,H2;
	int a[] = {1, 4, 6, 8, 10};
	int b[] = {2, 4, 16, 18, 30};
	int i;
	H1 = list_create();
	if(H1 == NULL)
		return;
	H2 = list_create();
	if(H2 == NULL)
		return;
	for(i = 0; i < (sizeof(a)/sizeof(int)); i++){
	list_tail_insert(H1, a[i]);
	}
	for(i = 0; i < (sizeof(b)/sizeof(int)); i++){
	list_tail_insert(H2, b[i]);
	}
	list_show(H1);
	list_show(H2);

	list_merge(H1, H2);
	list_show(H1);

	H1 = list_free(H1);
	H2 = list_free(H2);
}


void test_sort(){
	linklist H;
	int a[] = {1, 7 ,3, 18, 5, 21, 16};
	int i;
	H = list_create();
	if(H == NULL)
		return;
	for(i = 0; i < (sizeof(a)/sizeof(int)); i++){
	list_tail_insert(H, a[i]);
	}
	list_show(H);
	list_sort(H);
	list_show(H);
	H = list_free(H);


}

