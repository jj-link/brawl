#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_801E6C38(s32, void *, u32);
extern void fn_801E6AC4(s32, s32);
extern u32 fn_801E6B44(u32);
extern void fn_801E73B8(s32, void (*)(void));
extern void fn_802157F8(void);
extern void *memset(void *, int, unsigned long);
extern s32 __cntlzw(u32);

extern unsigned char lbl_804F6760[];
extern s32 lbl_8059ECE4;
extern u32 lbl_8059ECEC;
extern u32 lbl_805A0C38;
extern u32 lbl_805A0C40;
extern u32 lbl_805A0C44;

void fn_80215724(s32 arg0, s32 arg1)
{
    u32 buf;
    s32 idx;
    u32 old;
    s32 clz;

    if (!(arg1 & 0xF)) {
        idx = lbl_8059ECE4;
        old = lbl_805A0C44;
        lbl_805A0C44 = old | (0x80000000U >> idx);
        fn_801E6C38(idx, &buf, old);
        fn_801E6AC4(idx, lbl_8059ECEC | 0x400000);
        fn_801E6B44(lbl_805A0C44);
        lbl_805A0C38 |= 0x80000000U >> lbl_8059ECE4;
    }
    clz = __cntlzw(lbl_805A0C40);
    lbl_8059ECE4 = clz;
    if (clz != 32) {
        lbl_805A0C40 &= ~(0x80000000U >> clz);
        memset(lbl_804F6760 + clz * 12, 0, 12);
        fn_801E73B8(lbl_8059ECE4, fn_802157F8);
    }
}
