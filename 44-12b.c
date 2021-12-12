struct node* copyWithCases(struct node* p_first)
{

    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p_first == 0)
    {
        return 0;
    }
    else if (p_first->n == 0)
    {
       
        p->n = 0;
        p->d = p_first->d;
        return p;
    }
    else
    {
        struct node* p_save = p;
        while (p_first->n != 0)
        {
            p->d = p_first->d;

            struct node *p_new = (struct node*)malloc(sizeof(struct node));
            
            p->n = p_new;
            p = p_new;
            p_first = p_first->n;
        }
        p->d = p_first->d;
        p->n = 0;
        return p_save;
    }
}
