#define LEN(TYPE) \
int LEN_##TYPE(struct Node_##TYPE *f) \
{ \
    struct Node_##TYPE* p = f; \
    int i = 0; \
    while (p != 0) \
    { \
        i++; \
        p = p->n; \
    } \
    return i; \
}
