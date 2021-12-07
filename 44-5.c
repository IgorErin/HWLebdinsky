void nodePrint(struct node* f) //
{
    struct node* p = f;
    int i = 0;
    printf("%d", p->d);
    while (p != 0)
    {
        p = p->n;
        printf("%d\n", p->d);
    }
}
