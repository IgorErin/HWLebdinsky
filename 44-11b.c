struct node* add(struct node* p_now, int dat) // accepted
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->n = 0;
    p_new->d = dat;
    p_now->n = p_new;

    return p_new;
}


struct node* createWithN()
{
    int dat;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    struct node* p_now = p;

    
    printf("0 if this last\n");
    scanf("%d", &dat);

    p->d = dat;
    p->n = 0;

    while (dat != 0)
    {
        scanf("%d", &dat);
        p_now = add(p_now, dat);
    }

    return p;
}
