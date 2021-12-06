#define ADDFIRST(TYPE) \
void add_first_##TYPE(struct Node_##TYPE** f, TYPE d) \
{ \
    struct Node_##TYPE* p; \
    p = (struct Node_##TYPE*)malloc(sizeof(struct Node_##TYPE)); \
    p->d = d; \
    p->n = *f; \
    *f = p; \
}
