#pragma force_active on
typedef unsigned int u32;
typedef int BOOL;

typedef struct RingBuffer {
    unsigned char *read;
    unsigned char *write;
    unsigned char *base;
    u32 capacity;
    u32 used;
    u32 free;
    BOOL lock;
} RingBuffer;

extern void *memcpy(void *, const void *, unsigned long);
extern void fn_8040649C(BOOL *);
extern BOOL fn_80406478(BOOL *);

int fn_80406318(RingBuffer *self, const unsigned char *src, u32 size)
{
    u32 remaining;

    if (size > self->free) {
        return -1;
    }

    fn_8040649C(&self->lock);
    remaining = self->capacity - (self->write - self->base);

    if (remaining >= size) {
        memcpy(self->write, src, size);
        self->write += size;
    } else {
        memcpy(self->write, src, remaining);
        memcpy(self->base, src + remaining, size - remaining);
        self->write = self->base + size - remaining;
    }

    if (self->capacity == (u32)(self->write - self->base)) {
        self->write = self->base;
    }

    self->free -= size;
    self->used += size;
    fn_80406478(&self->lock);
    return 0;
}
