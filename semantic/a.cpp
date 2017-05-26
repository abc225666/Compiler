#include <stdio.h>
#include <stdlib.h>

#define NEW_VAL(T) ((T*)malloc(sizeof(T)))

typedef struct a
{
	int b;

}aa;

int main()
{
	aa *bb= NEW_VAL(aa);
	int *i=NEW_VAL(int);
	*i=100;
	bb->b=0;
	printf("%d",*i);
	return 0;
}