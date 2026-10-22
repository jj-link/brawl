#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

struct Obj40 {
    char pad[0x40];
    s32 unk40;
};

struct Arg {
    s32 unk0;
    u16 unk4;
    u8 pad6[2];
    struct Obj40 *unk8;
};

extern s32 fn_803783C4(struct Obj40 *, s32, u16, u8 *, s32);
extern void *memcpy(void *dst, const void *src, u32 n);
extern s16 lbl_8059F980;

s32 fn_80377AD0(struct Arg *arg0) {
    s16 sp8;
    u8 spC[12];
    struct Obj40 *temp_r31;
    s32 temp_r30;
    u16 temp_r29;
    s32 var_r28;

    var_r28 = 0;
    temp_r31 = arg0->unk8;
    temp_r29 = arg0->unk4;
    temp_r30 = arg0->unk0;
    if (temp_r31->unk40 == 2) {
        sp8 = 3;
        memcpy(spC, &sp8, 2);
        var_r28 = 2;
    }
    memcpy(spC + var_r28, &lbl_8059F980, 2);
    spC[var_r28 += 2] = 0x68;
    return fn_803783C4(temp_r31, temp_r30, temp_r29, spC, var_r28 + 1) != 0;
}
