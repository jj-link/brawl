#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Ent {
    u16 unk0;
    u8 pad02[9];
    u8 unkB;
    u8 pad0C;
    u8 unkD;
} Ent;

extern void fn_802319E4(s32, void *);
extern void fn_80231FB0(void *, int, int);
extern u8 *fn_8023B434(void);
extern Ent *fn_8023C7FC(u8 *, u8);
extern u8 fn_80244A84(u8 *, s32, u8, u8, u32, s32);
extern void fn_8024E63C(void *);
extern char lbl_80483E70[];
extern u8 lbl_8052CDC0[];

s32 fn_802501E4(void *arg0)
{
    u8 *p = (u8 *)arg0;
    u8 byte;
    s32 flag;
    Ent *ent;
    u8 a, b;
    u16 temp;
    s32 c;
    u8 r;

    byte = *fn_8023B434();
    *(u32 *)(p + 4) = 3;
    flag = (byte >> 5) & 1;
    ent = fn_8023C7FC(p + 0x2A, byte);
    if (ent != 0) {
        temp = ent->unk0;
        a = ent->unkB;
        b = ent->unkD;
        c = temp | 0x8000;
    } else {
        a = 1;
        b = 0;
        c = 0;
    }
    r = fn_80244A84(p + 0x2A, 0x18, a, b, c, flag);
    if (r == 0) {
        if (lbl_8052CDC0[0] >= 1) {
            fn_802319E4(0x80000, lbl_80483E70);
        }
        fn_8024E63C(arg0);
        return 0;
    }
    fn_80231FB0(p + 0x10, 2, 0x3C);
    return 1;
}
