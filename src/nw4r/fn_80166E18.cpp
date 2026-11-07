#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_80166DD0(void*, void*);
extern "C" void fn_80164510(void*, void (*)(void*, void*), void*, int, void*);

struct Holder {
    char pad[0xBC];
    void* child;
    void* list;
};

struct Context {
    s32 count;
    void (*func)(void*, s32);
    s32 arg;
    u8 flag;
};

extern "C" s32 fn_80166E18(Holder* self, void (*func)(void*, s32), s32 arg, u8 flag, s32 recurse) {
    s32 count = 0;
    void* node = fn_8015C1B0(&self->list, NULL);
    while (node) {
        void* next = fn_8015C1B0(&self->list, node);
        if (flag != 0 || *(s32*)((char*)node + 0xC) == 1) {
            func(node, arg);
            count++;
        }
        node = next;
    }
    if (recurse) {
        Context ctx;
        ctx.count = 0;
        ctx.func = func;
        ctx.arg = arg;
        ctx.flag = flag;
        fn_80164510(self->child, fn_80166DD0, &ctx, 1, self);
        count += ctx.count;
    }
    return count;
}