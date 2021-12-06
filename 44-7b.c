int LastWhitData(struct node* f, int par)
{
    struct node* p = f, *output = 0;
    while (p != 0)
    {
        if (p->d == par)
        {
            output = p;
        }
        p = p->n;
    }
    return output;
}
