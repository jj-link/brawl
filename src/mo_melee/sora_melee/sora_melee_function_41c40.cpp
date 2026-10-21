#include <types.h>
#pragma force_active on

struct VObj {
    virtual void f0();
    virtual void* f1(s32 idx);
};

struct Ent {
    u8 pad[0x1c];
    u32 flags;
};

struct Hdr {
    u8* base;
    s32 count;
};

struct Self {
    u32 unk0;
    s16 unk4;
    s16 unk6;
};

extern "C" void fn_27_36074(s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_27_41678(void* p, u8* addr);

extern "C" s32 fn_27_41C40(Self* self, s32 a1, VObj* obj, Hdr* hdr, s32 a4, s32 a5) {
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    for (; i < hdr->count; off += 0x20, i++) {
        fn_27_36074(a1, i, (((Ent*)(hdr->base + off))->flags >> 16) & 1, a4);
        void* p = obj->f1(a5 + i);
        fn_27_41678(p, hdr->base + off);
    }
    self->unk4 = a5;
    self->unk6 = i;
    self->unk0 = a4;
    return i;
}
