struct node* addInWithPointer(struct node* f, int n, int dat) //
{
    struct node* p = f;
    int i = 0;
    struct node* p_new = (struct node*)malloc(sizeof(struct node));
    p_new->d = dat;

    if (n == 0)
    {
        p_new->n = f;
        return p_new;
    }

    while (p != 0)
    {
        if (i == n - 1)
        {
            p_new->n = p->n;
            p->n = p_new;
            return f;
        }
        i++;
        p = p->n;
    }
}

void addInWithPointerToPointer(struct node** f, int n, int dat)
{
    
    struct node* p = *f;
    struct node** pp = f;
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->d = dat;

    int i = 0;

    while (p != 0)
    {
        if (i == n)
        {
            p_new->n = *pp;
            *pp = p_new;
            
        }
       
        
        i++;
        pp = &((*p).n);
        p = p->n;
        
        
    }
    if (i == n)
    {
        p_new->n = *pp;
        *pp = p_new;
    }
    
}

