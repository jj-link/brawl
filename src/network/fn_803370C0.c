#include <types.h>
#pragma force_active on
typedef struct G { s32 unk0; char pad4[0x14]; s32 unk18; s32 unk1C; char pad20[0x18]; void (*unk38)(s32, u8, void *, s32); s32 unk3C; } G;
typedef struct Arg { s32 unk0; s32 pad4; s32 unk8; } Arg;
typedef struct S8 { s32 unk0; s32 unk4; char pad8[0x100]; } S8;
extern void fn_80335638(s32, const char *, ...);
extern s32 fn_8033891C(void);
extern s32 fn_803517BC(s32, s32);
extern s32 fn_803683E8(s32, s32, void *);
extern const char lbl_80489554[];
extern G *lbl_805A0F70;
static inline s32 find_index(s32 id) {
    s32 base, off, i, val;
    if (lbl_805A0F70 == NULL || id == 0) return -1;
    i = 0;
    off = 0;
    while (i < lbl_805A0F70->unk18) {
        base = lbl_805A0F70->unk1C;
        if (base == 0) val = 0;
        else {
            val = fn_803517BC(fn_8033891C(), base + off);
            if (val == 0) goto zero;
            if (val != -1) goto skip;
zero:       val = 0;
skip:       ;
        }
        if (id == val) return i;
        off += 12;
        i++;
    }
    return -1;
}
void fn_803370C0(s32 arg0, Arg *arg1) {
    u8 sp110[0x108];
    S8 sp8;
    s32 index;
    fn_80335638(0x20000, lbl_80489554, arg1->unk0);
    if (lbl_805A0F70->unk38 != NULL) {
        index = find_index(arg1->unk0);
        if (index != -1) {
            fn_803683E8(arg0, arg1->unk8, &sp8);
            lbl_805A0F70->unk38(index, (u8)sp8.unk4, sp110, lbl_805A0F70->unk3C);
        }
    }
}