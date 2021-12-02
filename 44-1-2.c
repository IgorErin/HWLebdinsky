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

struct Node
{
	int d; 
	struct Node* n; 
};




void add_first(struct Node** f, int d)
{
	struct Node* p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->d = d;
	p->n = *f;
	*f = p;
}

#define ADD_FIRST(TYPE)\
void add_first(struct Node_##TYPE** f, int d) \
{ \
	struct Node_##TYPE* p; \
	p = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
	p->d = d; \
	p->n = *f; \
	*f = p; \
} \

#define ADD_LAST(TYPE)\
int addLast(struct Node_##TYPE* f, int d)\
{ \
	struct Node_##TYPE* p = f; \
int i = 0; \
while (p != 0) \
{ \
++i;  \
p = p->n; \
} \
\
struct Node* post_p = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
	p = post_p; \
	post_p->n = NULL; \
	post_p->d = d; \
} 

int main()
{
	

}
