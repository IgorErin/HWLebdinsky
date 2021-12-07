int firstWhitData(struct node* f, int dat) //
{
    struct node* p = f;
    while (p != 0)
    {
        if (p->d == dat)
        {
            return p;
        }
        p = p->n;
    }
    return 0;
}
