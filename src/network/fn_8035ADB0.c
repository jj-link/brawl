#pragma force_active on
typedef unsigned int u32;

typedef struct Array {
    int count;
    int capacity;
    int stride;
    void (*unkC)(void *);
    void (*destroy)(void *);
    char *data;
} Array;

extern void *fn_803F602C(void *, const void *, u32);

static inline void *element(Array *self, int i)
{
    if (i < 0 || i >= self->count)
        return 0;
    return self->data + self->stride * i;
}

static inline void erase(Array *self, int i)
{
    if (self->destroy)
        self->destroy(element(self, i));

    if (i < self->count - 1) {
        void *dest = element(self, i);
        void *src = element(self, i + 1);
        fn_803F602C(dest, src, self->stride * (self->count - 1 - i));
    }

    --self->count;
}

void fn_8035ADB0(Array *self)
{
    int i;

    for (i = self->count - 1; i >= 0; --i)
        erase(self, i);
}
