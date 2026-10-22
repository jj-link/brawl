#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_801E6AC4(int, u32);
extern void fn_801E6AD8(void);
extern u32 fn_801E7204(int);
extern u32 lbl_8059ECEC;
extern u32 lbl_8059ECF0;
extern u32 lbl_805A0C44;

void fn_802162A4(int arg0, u32 arg1) {
    int en = OSDisableInterrupts();
    if ((lbl_805A0C44 & (0x80000000U >> arg0)) && !(fn_801E7204(arg0) & 0x20000000)) {
        if (lbl_8059ECF0 < 2U && arg1 == 2) {
            arg1 = 0;
        }
        if (*(u8 *)0x800030E3 & 0x20) {
            arg1 = 0;
        }
        fn_801E6AC4(arg0, lbl_8059ECEC | 0x400000 | (arg1 & 3));
        fn_801E6AD8();
    }
    OSRestoreInterrupts(en);
}
