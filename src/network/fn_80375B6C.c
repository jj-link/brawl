#include <types.h>
#pragma force_active on

typedef struct S_8035A598 {
    s32 count;
    s32 pad4;
    s32 size;
    s32 padC[2];
    s32 base;
} S_8035A598;

typedef struct Obj {
    s32 pad0[0x11];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    S_8035A598* unk58;
    S_8035A598* unk5C;
    s32 unk60;
    s32 unk64;
} Obj;

extern s32 fn_8035A590(S_8035A598*);
extern void* fn_8035A598(S_8035A598*, s32);
extern s32 fn_8035A6EC(S_8035A598*, s32*, void*);
extern s32 fn_803737D8(s32);
extern void fn_8037382C(s32, s32, s32);
extern s32 fn_803779DC(Obj*, u32, u32);
extern s32 fn_80375B58(u16*, u16*);

s32 fn_80375B6C(Obj* arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32* arg5) {
    struct { s32 f0; s32 f1; s32 f2; u16 f3; } local;
    s32 count;
    s32 i;
    u16 val;

    count = fn_8035A590(arg0->unk5C);
    i = 0;
    while (i < count) {
        val = *(u16*)((u8*)fn_8035A598(arg0->unk5C, i) + 0x0C);
        if (val == arg2) { *arg5 = 0; return 1; }
        if ((s16)(val - arg2) > 0) break;
        i++;
    }
    if (fn_803737D8((s32)(&arg0->unk44)) < arg4) { *arg5 = 1; return 1; }

    local.f0 = arg0->unk4C;
    local.f1 = arg4;
    local.f2 = arg1;
    local.f3 = arg2;
    fn_8035A6EC(arg0->unk5C, (s32*)&local, (void*)&fn_80375B58);
    if (count + 1 != fn_8035A590(arg0->unk5C)) { *arg5 = 1; return 1; }

    fn_8037382C((s32)(&arg0->unk44), arg3, arg4);
    if (count == 0) {
        if (fn_803779DC(arg0, *(u16*)((u8*)arg0 + 0x66), (u16)(arg2 - 1)) == 0) return 0;
    } else {
        u16 valNow = *(u16*)((u8*)fn_8035A598(arg0->unk5C, count) + 0x0C);
        if (valNow == arg2) {
            u16 valPrev = *(u16*)((u8*)fn_8035A598(arg0->unk5C, count - 1) + 0x0C);
            if ((u16)(arg2 - valPrev) > 1) {
                if (fn_803779DC(arg0, (u16)(valPrev + 1), (u16)(arg2 - 1)) == 0) return 0;
            }
        }
    }
    *arg5 = 0;
    return 1;
}
