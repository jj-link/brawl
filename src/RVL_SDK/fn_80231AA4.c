#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern int lbl_805A0D24;
extern void *lbl_805A0D1C;
extern void *lbl_805A0D18;
extern u8 lbl_8040D680[0x18];
extern int lbl_8059EDE0;
extern int lbl_8059ED98;
extern u8 lbl_805297A0[0x30];

extern void fn_80230314(void);
extern void fn_80230508(void);
extern void fn_802435D8(void);
extern void fn_80231864(int, void *);
extern void fn_80230458(int);
extern void fn_80231BE4(void);
extern void fn_8023044C(int);
extern u8 fn_80234BC0(void);
extern void OSCreateAlarm(void *);
extern u64 OSGetTime(void);
extern void OSSetPeriodicAlarm(void *, u64, u64, void (*)(void *, void *));
extern void fn_80231A8C(void *, void *);

s32 fn_80231AA4(void)
{
    void *p;

    lbl_805A0D24 = 0;
    fn_80230314();
    fn_80230508();
    fn_802435D8();
    p = &lbl_8040D680;
    lbl_805A0D1C = &lbl_8059EDE0;
    lbl_805A0D18 = p;
    fn_80231864(0, p);
    while (lbl_8059ED98 != 0) {
        fn_80230458(100);
    }
    fn_80231BE4();
    OSCreateAlarm(lbl_805297A0);
    OSSetPeriodicAlarm(lbl_805297A0, OSGetTime(), (u64)((*(u32 *)0x800000F8 / 4 / 1000) * 2), fn_80231A8C);
    fn_8023044C(0);
    while (fn_80234BC0() == 0) {
        fn_80230458(0x7D0);
    }
    return 0;
}
