#pragma force_active on
typedef unsigned int u32;
typedef long long s64;

extern s64 OSGetTime(void);
extern s64 fn_803F1470(s64, s64);
extern void fn_801FE8D0(void *arg);
extern void fn_801FC130(void);
extern int lbl_804E4580[];
extern int lbl_805A09A0;

void fn_801FC1C0(int arg0, int arg1) {
    lbl_804E4580[2] = arg0;
    lbl_804E4580[3] = (int)fn_803F1470(OSGetTime(), (s64)((*(u32 *)0x800000F8) >> 2));
    lbl_805A09A0 = arg1;
    fn_801FE8D0(fn_801FC130);
}
