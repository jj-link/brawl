#include <types.h>
#pragma force_active on
struct Self;
struct Context { Self* self; int value; int result; };
class Class_80488260 {
public:
    virtual void fn_802E8C04(Context*);
};
struct Self {
    char pad0[0x58];
    Class_80488260** listeners;
    int count;
    char pad1[0x30];
    int* data;
    int size;
    unsigned int capacity;
};
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_802E80AC(Self* self, int value) {
    Context ctx;
    ctx.value = value;
    ctx.self = self;
    ctx.result = 0;
    int i = self->count - 1;
    int offset = i * 4;
    for (; i >= 0; offset -= 4, --i) {
        Class_80488260* listener = *(Class_80488260**)((char*)self->listeners + offset);
        if (listener)
            listener->fn_802E8C04(&ctx);
    }
    if (ctx.result == 0) {
        if (self->size == (int)(self->capacity & 0x3fffffff))
            fn_8027CE3C(&self->data, 4);
        self->data[self->size++] = value;
    }
}