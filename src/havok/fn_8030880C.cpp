#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);

struct Src {
    char pad[0xC];
    u32 field0C;
};

struct Entry {
    u32 a;
    u32 b;
};

struct Buf {
    Entry* entries;
    s32 count;
    u32 cap;
};

extern "C" void fn_8030880C(Src* a0, Src* a1, Buf* buf) {
    if (buf->count == (s32)(buf->cap & 0x3FFFFFFF)) {
        fn_8027CE3C(buf, 8);
    }
    s32 idx = buf->count;
    Entry* base = buf->entries;
    buf->count = idx + 1;
    Entry* e = &base[idx];
    e->a = a0->field0C;
    e->b = a1->field0C;
}
