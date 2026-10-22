#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);

struct Pair {
    u32 a;
    u32 b;
};

struct Buf {
    Pair* data;
    s32 count;
    u32 capacity;
};

struct Src {
    char pad[0xC];
    u32 value;
};

extern "C" void fn_80308894(Src* arg0, Src* arg1, Buf* arg2) {
    if (arg2->count == (s32)(arg2->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(arg2, 8);
    }
    s32 idx = arg2->count;
    Pair* base = arg2->data;
    arg2->count = idx + 1;
    Pair* p = &base[idx];
    p->a = arg0->value;
    p->b = arg1->value;
}
