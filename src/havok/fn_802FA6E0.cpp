#include <types.h>
#pragma force_active on

struct Ctx {
    u8 pad0[0x40];
    void* unk40;
    s32 unk44;
    u8 pad48[0x10];
    void* unk58;
};
struct Ent { u32 unk0; void* unk4; };
struct Base { u8 pad0[0x10]; s32 off10; };
struct Target { u8 pad0[0x58]; void* unk58; u8 pad5c[0x4C]; u8 unkA8; };

extern "C" void* fn_802F37D8(u32 arg0, void* arg1, void* arg2);
extern "C" void fn_802FF278(void* self, u32 node);
extern "C" void fn_802FF684(void* self, s32 arg);

inline void transfer(void* a, void* b, u32 node) {
    fn_802FF684(b, (s32)node);
    fn_802FF278(a, node);
}

extern "C" void fn_802FA6E0(void* arg0, Ctx* arg1, void* arg2, s32 arg3) {
    Ent* e;
    Base* b;
    Target* t;
    s32 off, i;
    i = 0;
    off = 0;
    for (; i < arg1->unk44; off += 8, i++) {
        e = (Ent*)((u8*)arg1->unk40 + off);
        b = (Base*)e->unk4;
        t = (Target*)((u8*)b + b->off10);
        if ((s8)((u32)__cntlzw((u32)t->unkA8 - 7) >> 5) != 0) {
            u32 node = e->unk0;
            fn_802FF684(arg2, (s32)node);
            fn_802FF278(arg0, node);
        } else if (arg3 == 7) {
            if (fn_802F37D8(e->unk0, arg1->unk58, t->unk58) == arg1->unk58) {
                transfer(arg0, (void*)((u8*)t->unk58 + 0x48), e->unk0);
            }
        }
    }
}