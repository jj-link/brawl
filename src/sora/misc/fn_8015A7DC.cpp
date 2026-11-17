#include <types.h>
#pragma force_active on

extern "C" {
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
void* memset(void*, int, u32);
extern const f32 lbl_805A2B94;
extern const f32 lbl_805A2B98;
}

struct Entry {
    s32 key0;
    s32 key1;
    u8 count;
    u8 flag;
};

struct Obj {
    char pad[0x14];
    Entry* src;
    Entry* dst;
    u32 srcCount;
    u32 dstCount;

    void add(u32 k, Entry* s) {
        for (; k < dstCount; k++) {
            if (s->key0 == dst[k].key0 && s->key1 == dst[k].key1) {
                dst[k].count++;
                return;
            }
        }
        if (k < 0xFF) {
            dst[k] = *s;
            dst[k].count = 1;
            dstCount++;
        }
    }
};

extern "C" void fn_8015A7DC(Obj* self, f32 step) {
    self->dstCount = 0;
    self->dst = (Entry*)__nwa__FUlQ25Heaps8HeapType(0xBF4, 0x10);
    memset(self->dst, 0, 0xBF4);
    f32 f = lbl_805A2B94;
    for (u32 i = 0; i < self->srcCount; i++) {
        if (self->src[i].flag == 0) {
            u32 n = self->src[i].count;
            for (u32 j = 0; j < n; j++) {
                f += step;
                if (f >= lbl_805A2B98) {
                    f = lbl_805A2B94;
                    self->add(0, &self->src[i]);
                    self->src[i].count--;
                }
            }
        }
    }
}
