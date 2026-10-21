#pragma force_active on
extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern int fn_80211AE8(void);
extern int fn_80211AE0(void);
extern void fn_80211AF0(unsigned int);
extern int fn_80213468(int, int);
extern void fn_80228834(const char *, ...);
extern void fn_802288DC(const char *, ...);

extern char lbl_8047E240[];
extern int lbl_8059ED80;
extern int lbl_805A0CD0;
extern unsigned int lbl_805A0CD4;

int fn_80228988(void)
{
    const char *base = lbl_8047E240;
    int result = 0;
    int interrupts = OSDisableInterrupts();

    if (lbl_8059ED80 != -1) {
        fn_80228834(base + 0xC, lbl_8059ED80);
        goto done;
    }

    if (lbl_805A0CD0 == 0) {
        lbl_805A0CD0 = fn_80211AE8();
        lbl_805A0CD4 = fn_80211AE0();
        fn_80228834(base + 0x3C, 0x80, lbl_805A0CD0, lbl_805A0CD4);

        if ((unsigned int)(lbl_805A0CD0 + 0x4000) > lbl_805A0CD4) {
            fn_802288DC(base + 0x5C);
            result = -22;
            goto done;
        }

        fn_80211AF0(lbl_805A0CD0 + 0x4000);
    }

    lbl_8059ED80 = fn_80213468(lbl_805A0CD0, 0x4000);
    if (lbl_8059ED80 < 0) {
        fn_802288DC(base + 0x74);
        result = -22;
    }

done:
    OSRestoreInterrupts(interrupts);
    return result;
}
