#include <types.h>
#pragma force_active on

typedef struct Self {
    u8 pad0[0x60];
    s32 unk60;
    u8 pad1[0x88 - 0x64];
    u32 unk88;
    u8 pad2[0x90 - 0x8C];
    s32 unk90;
    u32 unk94;
} Self;

typedef struct Elem {
    u8 pad[0xC];
    u32 unkC;
} Elem;

extern s32 fn_8035A590(s32);
extern Elem *fn_8035A598(s32, s32);
extern s32 fn_80374488();
extern s32 fn_80377724(Self *);
extern s32 fn_80377918(Self *);
extern s32 fn_80377B88(Self *, Elem *);

s32 fn_80374584(Self *arg0, u32 arg1) {
    s32 temp_r31;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r30;
    s32 var_r3;
    Elem *e;

    if (fn_80374488() == 0) {
        return 0;
    }
    if ((arg1 - arg0->unk88 > 0x7530U) && (fn_80377724(arg0) == 0)) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
    }
    if (var_r0 == 0) {
        return 0;
    }
    temp_r31 = fn_8035A590(arg0->unk60);
    var_r30 = 0;
    goto cond;
body:
    e = fn_8035A598(arg0->unk60, var_r30);
    if ((arg1 - e->unkC > 0x3E8U) && (fn_80377B88(arg0, e) == 0)) {
        var_r0_2 = 0;
        goto done;
    }
    var_r30++;
cond:
    if (var_r30 < temp_r31) {
        goto body;
    }
    var_r0_2 = 1;
done:
    if (var_r0_2 == 0) {
        return 0;
    }
    if (arg0->unk90 == 0) {
        var_r3 = 1;
    } else if ((arg1 - arg0->unk94 > 0x64U) && (fn_80377918(arg0) == 0)) {
        var_r3 = 0;
    } else {
        var_r3 = 1;
    }
    return var_r3 != 0;
}
