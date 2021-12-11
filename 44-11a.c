void add(struct node * first_p, int dat) // accepted
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->d = dat;
    p->n = 0;
    if (first_p != 0)
    {
        while (first_p->n != 0)
        {
            first_p = first_p->n;
        }
    }


    first_p->n = p;
}

struct node * createWithNInSqr()
{
    int dat;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    
    printf("0 if this last \n");
    scanf("%d", &dat);

    p->n = 0;
    p->d = dat;

    while (dat != 0)
    {
        scanf("%d", &dat);
        add(p, dat);
        
    }

    return p;

}
