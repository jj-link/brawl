#pragma force_active on

typedef struct Array {
    int count;
    int capacity;
    int stride;
    void (*unkC)(void *);
    void (*destroy)(void *);
    char *data;
} Array;

extern void fn_8035E00C(void *);

static inline void *element(Array *self, int i)
{
    if (i < 0 || i >= self->count)
        return 0;
    return self->data + (self->stride * i);
}

void fn_8035A4FC(Array *self)
{
    int i;

    for (i = 0; i < self->count; ++i) {
        if (self->destroy)
            self->destroy(element(self, i));
    }

    fn_8035E00C(self->data);
    fn_8035E00C(self);
}
