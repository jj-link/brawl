#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern s32 lbl_805A0C1C;
extern void *fn_802137A4(s32, s32, s32);
extern s32 fn_802124C8(s32, void *, void *);
extern void fn_80213C80(void);

s32 fn_802152E4(s32 arg0, s32 arg1, s32 arg2) {
    void *p;

    p = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (p == 0) {
        return -0x76;
    }
    *(s32 *)((char *)p + 0x100) = arg1;
    *(s32 *)((char *)p + 0x104) = arg2;
    *(s32 *)((char *)p + 0x108) = 0;
    return fn_802124C8(arg0, (void *)fn_80213C80, p);
}
