void copyWithCases(struct node* p_first, struct node* p_copy_first)
{
    
    if (p_first->n == 0)
    {
        p_copy_first->d = p_first->d;
        p_copy_first->n = 0;
    }
    else
    {
        
        struct node* p = p_copy_first;


        while (p_first->n != 0)
        {
            struct node* p_new = (struct node*)malloc(sizeof(struct node));
            p->d = p_first->d;
            p->n = p_new;
            p = p_new;
            p_first = p_first->n;

            
        }
        p->n = 0;
        p->d = p_first->d;

    }
}
