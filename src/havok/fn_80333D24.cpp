#include <types.h>
#pragma force_active on

struct S {
    u32 pad[2];
    s32 unk8;
};

extern "C" u32 fn_8027D198(void *, u32);
extern "C" void fn_80333A68(s32, s32, void *);
extern "C" int __cntlzw(unsigned int);

extern "C" void fn_80333D24(s32 a0, s32 a1, S *a2) {
    if ((s8)((u32)__cntlzw((s8)(u8)((s32)fn_8027D198(a2, a1) <= a2->unk8)) >> 5))
        fn_80333A68(a1, a0, a2);
}
