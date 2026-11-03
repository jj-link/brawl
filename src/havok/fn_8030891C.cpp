#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);

struct Vec16 {
    u16* data;
    s32 count;
    u32 cap;
};

struct Holder {
    s32 pad0;
    Vec16 vec;
};

struct Pair {
    u32 a;
    u32 b;
};

struct PairBuf {
    Pair* data;
    s32 count;
    u32 cap;
};

struct Src {
    char pad[0xC];
    u32 value;
};

extern "C" void fn_8030891C(u8* arg0, Src* arg1, s32 arg2, Src* arg3, PairBuf* arg4) {
    u32 flags = arg3->value;
    if (!(flags & 1)) {
        if (arg4->count == (s32)(arg4->cap & 0x3FFFFFFF)) {
            fn_8027CE3C(arg4, 8);
        }
        s32 idx = arg4->count;
        Pair* base = arg4->data;
        arg4->count = idx + 1;
        Pair* p = &base[idx];
        p->a = arg1->value;
        p->b = arg3->value;
        return;
    }
    u16 val = arg2;
    Holder* h = (Holder*)(arg0 + (flags & ~1));
    if (h->vec.count == (s32)(h->vec.cap & 0x3FFFFFFF)) {
        fn_8027CE3C(&h->vec, 2);
    }
    h->vec.data[h->vec.count++] = val;
}
