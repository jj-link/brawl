#include <types.h>
#pragma force_active on

extern "C" {
int OSIsThreadTerminated(void* thread);
void OSResumeThread(void* thread);
void* fn_80150460(void);
u64 getTime__6nteDWCCFv(void* self);
void fn_8015051C(void);
s8 fn_800305B0(s32 arg);
u64 fn_8014FBB8(void);
void fn_8014FEFC(void);
u64 fn_801504AC(s32 arg);
void fn_801E1D80(u64 time, void* out);
void* fn_80038984(void* obj, s32 type);
void* __nw__FUlQ25Heaps8HeapType(u32 size, s32 type);
extern u8 lbl_805A0458;
}

struct Buf {
    u8 pad[0xC];
    s32 a;
    s32 b;
    s32 c;
    u8 pad2[0x10];
};

extern "C" s32 fn_801578C4(void* self) {
    s32 one;
    u8* p = (u8*)self;
    Buf b2;
    Buf b1;
    u64 t;
    void* obj;
    u64 t3;

    bool term = OSIsThreadTerminated(p + 8) == 1;
    if (term) {
        return 0;
    }
    if (*(s32*)(p + 0x354) != 0) {
        return 0;
    }
    t = getTime__6nteDWCCFv(fn_80150460());
    if (t == 0) {
        return 0;
    }
    fn_8015051C();
    one = 1;
    p[0x37D] = one;
    p[0x37E] = fn_800305B0(3);
    fn_801E1D80(fn_8014FBB8(), &b1);
    fn_801E1D80(fn_801504AC(0), &b2);
    if (lbl_805A0458 == 0 && b2.c == b1.c && b2.b == b1.b && b2.a == b1.a) {
        fn_8014FEFC();
        p[0x348] = one;
        p[0x374] = one;
        p[0x37C] = one;
        OSResumeThread(p + 8);
        return 1;
    }
    if (*(s32*)(p + 0x370) == 0) {
        obj = __nw__FUlQ25Heaps8HeapType(0x194, *(s32*)(p + 0x350));
        if (obj != 0) {
            obj = fn_80038984(obj, *(s32*)(p + 0x350));
        }
        *(void**)(p + 0x370) = obj;
        if (obj == 0) {
            fn_8014FEFC();
            p[0x348] = one;
            p[0x374] = one;
            p[0x37C] = one;
            OSResumeThread(p + 8);
            return 1;
        }
    }
    t3 = fn_8014FBB8();
    *(u32*)(p + 0x368) = (u32)(t3 >> 32);
    *(u32*)(p + 0x36C) = (u32)t3;
    p[0x374] = 0;
    *(s32*)(p + 0x354) = 1;
    OSResumeThread(p + 8);
    return 1;
}
