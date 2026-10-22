#pragma force_active on

typedef unsigned int u32;
typedef void (*Callback)(void*, void*, void*);

struct State {
    unsigned char pad0[0x0C];
    Callback callback;
    void* context;
    u32 size;
    u32 offset;
    unsigned char pad1[0x68 - 0x1C];
    void* handle;
    bool busy;
};

struct Outer;

extern "C" void fn_8015CD54(void*, Outer*);
extern "C" int fn_801F6708(
    void*, void*, u32, u32, void (*)(void*, Outer*), void*);
extern "C" void fn_8015CC44(void*, u32);

static inline u32 clamp(State* self, u32 count)
{
    if (((self->offset + count + 31) & ~31u) >
        ((self->size + 31) & ~31u)) {
        count = (self->size - self->offset + 31) & ~31u;
    }
    return count;
}

static inline u32 clamp2(u32 count, u32 size, u32 offset)
{
    if (((offset + count + 31) & ~31u) > ((size + 31) & ~31u)) {
        count = (size - offset + 31) & ~31u;
    }
    return count;
}

extern "C" bool fn_8015D0E4(
    State* self, void* buffer, u32 count, Callback callback, void* context)
{
    count = clamp(self, count);
    self->callback = callback;
    self->context = context;
    self->busy = true;

    bool result = fn_801F6708(
        (char*)self + 0x28,
        buffer,
        clamp2(count, self->size, self->offset),
        self->offset,
        fn_8015CD54,
        self->handle) != 0;

    if (result) {
        fn_8015CC44(&self->size, count);
    } else {
        self->busy = false;
    }

    return result;
}
