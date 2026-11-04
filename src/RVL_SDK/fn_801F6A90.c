#include <revolution/OS/OS.h>
#include <string.h>
#pragma force_active on
#pragma opt_propagation off
extern const char *lbl_8059EAD8;
extern int lbl_805A0940, lbl_805A0630, lbl_805A0970, lbl_805A0920, lbl_805A093C;
extern unsigned char lbl_804DF740[], lbl_804DF840[], lbl_804E4580[];
extern int lbl_805A0960, lbl_805A08D8;
extern unsigned char *lbl_805A0988;
extern void *lbl_805A098C;
extern void fn_801FC938(void), fn_801F5ED8(void), fn_801FB6CC(void);
extern void fn_801E0704(void *), fn_801FEA44(void), fn_801FEA4C(void);
extern void fn_801FC454(int), fn_802110D4(void);
extern int fn_80211080(void), fn_802113E0(void *, void *), fn_80211484(void *, void *);
void fn_801F6A90(void) {
    int result;
    unsigned int value;
    unsigned char *base;
    if (lbl_805A0940 == 0) {
        OSRegisterVersion(lbl_8059EAD8);
        lbl_805A0940 = 1;
        fn_801FC938();
        if (lbl_805A0630 == 0 && *(unsigned char *)0x80003187 == 0x80) {
            result = fn_80211080();
            if (result == 0) result = fn_802113E0(0, lbl_804DF740);
            if (result == 0) result = fn_80211484(0, &lbl_805A0960);
            if (result == 0) fn_80211484(lbl_804DF840, &lbl_805A0960);
            fn_802110D4();
        }
        fn_801F5ED8();
        fn_801FB6CC();
        lbl_805A0970 = 0;
        lbl_805A0988 = (unsigned char *)0x80000000;
        lbl_805A098C = (void *)0x80000000;
        fn_801E0704(&lbl_805A08D8);
        fn_801FEA44();
        fn_801FEA4C();
        value = *(unsigned int *)(lbl_805A0988 + 0x20);
        if (value != 0xE5207C22 && value != 0x0D15EA5E) lbl_805A0920 = 1;
        memset(lbl_804E4580, 0, 0x80);
        base = (unsigned char *)0x80000000;
        memcpy(lbl_804E4580, base, 4);
        lbl_804E4580[4] = base[6];
        lbl_804E4580[5] = base[7];
        lbl_805A093C = 0;
        fn_801FC454(1);
    }
}