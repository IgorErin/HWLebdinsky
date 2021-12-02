#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>


#define NODE(TYPE) \
struct Node_##TYPE \
{ \
TYPE d; \
struct Node_##TYPE *n; \
};

struct lol {
	int p ;
};

/*
int fun(struct Node* l)
{
	if (l->d % 2 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/
struct Node
{
	int d; 
	struct Node* n; 
};

/*

int lengthForAnyTypes(struct Node_##TYPE* f)
{
	struct Node_##TYPE* p = f; 
	
	int i = 0;
	while (p != 0)
	{
		++i; 
		p = p->n; 
	return i;
}
*/

int ToSecondFild(struct Node* f)
{
	struct Node* p = f; 
	
	int i = 0;
	while (p != 0)
	{
		++i;
		p = p->n; 
		if (i == 2)
		{
			return &p->d;
		}
	}
	
}

int PointerTolastElement(struct Node* f)
{
	struct Node* p = f;
	struct Node* ex_p = f;

	int i = 0;
	while (p != 0)
	{
		++i; 
		ex_p = p;
		p = p->n; 
	}
	return ex_p;
}

int PointerToNElenment(struct Node* f, int n)
{
	struct Node* p = f;
	struct Node* ex_p = f;

	int i = 0;
	while (p != 0)
	{
		++i;
		p = p->n;
		if (i == n)
		{
			return p;
		}
	}
	return 0;
}

/*int PointerToNElenmentForAllTypes(struct Node_##TYPE* f, int n)\
{\
	struct Node_##TYPE* p = f;\
	struct Node_##TYPE* ex_p = f;\
	int i = 0;\
	while (p != 0)\
	{\
		++i;\
		p = p->n;\
		if (i == n)\
		{\
			return p;\
		}\
	}\
	return 0;\
}\*/

void printAllElenets(struct Node* f)
{
	struct Node* p = f; 
	
	int i = 0;
	while (p != 0)
	{
		printf("%d", p->d);
		++i; 
		p = p->n; 
	}
	
}

int howMachTruElements(struct Node* f, int (*fun)(struct Node*))
{
	struct Node* p = f;
	int a = 0;
	int i = 0;
	while (p != 0)
	{
		if ((*fun)(p))
		{
			a++;
		}
		++i;
		p = p->n;
	}
	return a;
}


int returnFirstElementWithData(struct Node* f, int data)
{
	struct Node* p = f;
	int a = 0;
	int i = 0;
	while (p != 0)
	{
		if (p->d == data)
		{
			return p;
		}
		++i;
		p = p->n;
	}
	return 0;
}

int returnLastElementWithData(struct Node* f, int data)
{
	struct Node* p = f;
	struct Node* sub_p = 0;
	int i = 0;

	while (p != 0)
	{
		if (p->d == data)
		{
			sub_p = p;
		}
		++i;
		p = p->n;
	}
	return sub_p;
}




int main()
{
	

}
