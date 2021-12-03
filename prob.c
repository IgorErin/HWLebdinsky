#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>



struct Node
{
	int d; 
	struct Node* n; 
};

/*

void addForTwoPointer(struct Node** f, int pos, int d)
{

	struct Node* p_new;
	p_new = (struct Node*)malloc(sizeof(struct Node));
	struct Node *p = f;
	int i = 0;

	

	while (i != pos)
	{
		i++;

		p->n = *f;
		*f = p;

		if (i == pos)
		{
			*f = p_new;
			p_new->n = 
		}
	}
	
	

}
*/
struct Node* addOnNPos(struct Node* f, int pos, int d)
{
	struct Node* p = f;
	struct Node* p_new = (struct Node*)malloc(sizeof(struct Node*));
	int i = 0;

	if (pos == 0)
	{
		p_new->n = f;
		p_new->d = d;
		return p_new->n;
	}
	else
	{
		while (p != 0)
		{
			i++;
			p = p->n;
			if (i == pos - 1)
			{
				
				p_new->n = p->n;
				p->n = p_new;
				p_new->d = d;
				break;
			}
		}
	}

	return f;
}

void add(struct Node** pp, int i)
{
	struct Node* p_new = (struct Node*)malloc(sizeof(struct Node));
	
	p_new->d = i;
	p_new->n = *pp;
	*pp = p_new;


}

int length(struct Node* f)
{
	struct Node* p = f; 
	
	int i = 0;
	while (p != 0)
	{
		printf("%d\n", p->d);
		++i; 
		p = p->n; 
	}
	
}


int main()
{
	struct Node lol;
	lol.n = NULL;
	lol.d = 0;
	struct Node* p_lol;
	struct Node** p_p_lol;

	p_lol = &lol;
	p_p_lol = &p_lol;

	for (int i = 1; i < 10; i++)
	{
		add(p_p_lol, i);
	}

	length(p_lol);
	
	
	addOnNPos(p_lol, 4, -4);
	printf("----------\n");

	length(p_lol);

}
