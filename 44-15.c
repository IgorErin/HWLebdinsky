#define DELFIRST(TYPE) \
void delFIrst(struct Node_##TYPE** pp) \
{ \
    if (*pp == 0) \
    { \
        return; \
    } \
    struct Node_##TYPE* p = *pp; \
    *pp = (*pp)->n; \
    free(p); \
}
