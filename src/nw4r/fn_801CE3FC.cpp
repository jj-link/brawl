#include <types.h>
#pragma force_active on

extern "C" {
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32);
s32 fn_801CCA9C(void* self);
void fn_801CCB80(void* self, s32 x);
s32 fn_801D2AD0(void);
s32 fn_801D2D74(s32 a, s32 b, s32 c, s32 d, void* e, void* f);
void fn_801CF238(void* a, s32 b, void* c);
}

extern "C" s32 fn_801CE3FC(u8* self, s32 num, s32 a) {
    s32 old;
    u8* q2;
    void* p;
    s32 i;
    s32 r;

    old = OSDisableInterrupts();
    p = self;
    i = 0;
    while (i < num) {
        r = fn_801CCA9C(*(void**)((u8*)self + 0x7B8));
        if (r == 0) {
            u8* q = self;
            for (s32 j = 0; j < i; j++) {
                fn_801CCB80(*(void**)((u8*)self + 0x7B8), *(s32*)(q + 0x7CC));
                q += 0x38;
            }
            OSRestoreInterrupts(old);
            return 0;
        }
        *(s32*)((u8*)p + 0x7CC) = r;
        i++;
        *(s32*)((u8*)p + 0x7D0) = *(s32*)(*(u8**)((u8*)self + 0x7B8) + 8);
        p = (u8*)p + 0x38;
    }

    r = fn_801D2D74(fn_801D2AD0(), num, a, 0xFF, (void*)fn_801CF238, self);
    if (r == 0) {
        s32 j;
        q2 = self;
        for (j = 0; j < num; j++) {
            fn_801CCB80(*(void**)((u8*)self + 0x7B8), *(s32*)(q2 + 0x7CC));
            q2 += 0x38;
        }
        OSRestoreInterrupts(old);
        return 0;
    }
    *(s32*)((u8*)self + 0x7C0) = r;
    OSRestoreInterrupts(old);
    return 1;
}
