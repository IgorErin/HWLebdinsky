struct node* pointerToNEl(struct node* f, int n) //
{
    struct node* p = f;
    int i = 0;
    while (p != 0)
    {
        i++;
        p = p->n;
        if (i == n)
        {
            return p;
        }
    }
}
