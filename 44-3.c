struct node* pointerToLastEL(struct node* f)
{
    struct node* p = f;
    
    while (p->n != 0)
    {
        p = p->n;
    }
    return p;
}
