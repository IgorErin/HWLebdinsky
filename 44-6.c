int count(struct node* f,_Bool (*funBool)(struct node*)) //
{
    struct node* p = f;
    int i = 0;
    while (p != 0)
    {
        if ((*funBool)(p))
        {
            i++;
        }
        p = p->n;
    }

    return i;
}
