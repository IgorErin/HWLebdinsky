void addLAst_##TYPE(struct Node_##TYPE* f, TYPE input) \
{ \
    struct Node_##TYPE* p = f; \
    while (p->n != 0) \
    { \
        p = p->n; \
    } \
    p->n = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
    p = p->n; \
    p->d = input; \
    p->n = 0; \
};
