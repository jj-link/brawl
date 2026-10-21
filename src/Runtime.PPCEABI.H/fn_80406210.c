#pragma force_active on
typedef unsigned int u32;
typedef int BOOL;

typedef struct RingBuffer {
    unsigned char *read;
    unsigned char *write;
    unsigned char *base;
    u32 capacity;
    u32 available;
    u32 free;
    BOOL lock;
} RingBuffer;

extern void fn_8040649C(BOOL *);
extern BOOL fn_80406478(BOOL *);
extern void *memcpy(void *, const void *, unsigned long);

int fn_80406210(RingBuffer *self, unsigned char *dest, u32 size)
{
    u32 remaining;

    if (size > self->available)
        return -1;

    fn_8040649C(&self->lock);

    remaining = self->capacity - (self->read - self->base);
    if (size < remaining) {
        memcpy(dest, self->read, size);
        self->read += size;
    } else {
        memcpy(dest, self->read, remaining);
        memcpy(dest + remaining, self->base, size - remaining);
        self->read = self->base + size - remaining;
    }

    if (self->capacity == (u32)(self->read - self->base))
        self->read = self->base;

    self->free += size;
    self->available -= size;

    fn_80406478(&self->lock);
    return 0;
}
