#pragma force_active on
#include <revolution/OS/OSThread.h>

extern u8 fn_801D6620(void);
extern void fn_801E2FEC(void);
extern void fn_801E28F8(void);
extern void fn_801E0760(void);
extern void fn_801DF11C(int);
extern void fn_801D9C80(void);
extern void fn_801DEF64(int, int);
extern void fn_801E25C0(void);
extern void fn_801E2750(void);
extern void fn_801D8690(const char *, int, const char *, ...);
extern int lbl_805A0634;
extern int lbl_805A06A4;
extern int lbl_805A06E0;
extern char lbl_804689E0[];
extern char lbl_804689EC[];

void fn_801DF434(int argument)
{
    u8 old = fn_801D6620();

    fn_801E2FEC();
    fn_801E28F8();
    if (old == 0x81) {
        fn_801E0760();
        fn_801DF11C(4);
        OSEnableScheduler();
        fn_801D9C80();
    } else if (old == 0x80) {
        fn_801E0760();
        fn_801DF11C(4);
        OSEnableScheduler();
        fn_801DEF64(argument, lbl_805A06E0);
    }
    fn_801E0760();
    fn_801DF11C(1);
    if (lbl_805A0634 || lbl_805A06A4)
        fn_801E25C0();
    fn_801E2750();
    fn_801D8690(lbl_804689E0, 0x3CD, lbl_804689EC);
}
