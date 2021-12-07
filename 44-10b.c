#define ADDINWITHPOINTER(TYPE) \ //
struct node* addInWithPointer(struct Node_##TYPE* f, int n, TYPE dat) \
{ \
    struct Node_##TYPE* p = f; \
    int i = 0; \
    struct Node_##TYPE* p_new = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
    p_new->d = dat; \
    if (n == 0) \
    { \
        p_new->n = f; \
        return p_new; \
    } \
    while (p != 0) \
    { \
        if (i == n - 1) \
        { \
            p_new->n = p->n; \
            p->n = p_new; \
            return f; \
        } \
        i++; \
        p = p->n; \
    } \
}
#define ADDINWITHPOINTERTOPOINTER(TYPE) \
void addInWithPointerToPointer(struct Node_##TYPE** f, int n, TYPE dat) \
{ \
    struct Node_##TYPE* p = *f; \
    struct Node_##TYPE** pp = f; \
    struct Node_##TYPE* p_new = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
    p_new->d = dat; \
    int i = 0; \
    while (p != 0) \
    { \
        if (i == n) \
        { \
            p_new->n = *pp; \
            *pp = p_new; \
        } \
        i++; \
        pp = &((*p).n); \
        p = p->n; \
    } \
    if (i == n) \
    { \
        p_new->n = *pp; \
        *pp = p_new; \
    } \
} 
