#define POINTERTONEL(TYPE) \ //
struct Node_##TYPE* PointerToN_##TYPE(struct Node_##TYPE *f, TYPE n) \
{ \
    struct Node_##TYPE* p = f; \
    int i = 0; \
    while (p != 0) \
    { \
        i++; \
        p = p->n; \
        if (i == n) \
        { \
            return p; \
        } \
    } \
}
