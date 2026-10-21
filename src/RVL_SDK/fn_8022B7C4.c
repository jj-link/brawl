#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern char lbl_804FB4A0[];
extern int lbl_805A0CE0;
extern u8 lbl_805A0CE4;
extern char lbl_8047ECF8[];
extern char lbl_8047ED10[];

extern void fn_8022E928(const char *, ...);
extern void fn_80231AA4(void);
extern void fn_80232598(u8);
extern u8 fn_8024AEB0(u8);
extern void fn_80257700(u8);
extern void fn_8020E0EC(void);
extern void OSCreateAlarm(void *);
extern u64 OSGetTime(void);
extern void fn_8022B338(void *, void *);
extern void OSSetPeriodicAlarm(void *, u64, u64, void (*)(void *, void *));

int fn_8022B7C4(void)
{
    char *p = lbl_804FB4A0;

    if (lbl_805A0CE0 != 0) {
        return 0;
    }

    fn_8022E928(lbl_8047ECF8);
    fn_80231AA4();
    fn_80232598(lbl_805A0CE4);
    fn_8024AEB0(lbl_805A0CE4);
    fn_80257700(lbl_805A0CE4);
    fn_8022E928(lbl_8047ED10);

    *(int *)(p + 0) = 0;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 0x6F0) = 0;
    *(int *)(p + 0x6EC) = 0;
    p[0x10] = 1;

    fn_8020E0EC();
    OSCreateAlarm(p + 0x710);
    OSSetPeriodicAlarm(
        p + 0x710,
        OSGetTime(),
        (u64)((*(u32 *)0x800000F8 / 4 / 1000) * 10),
        fn_8022B338
    );

    lbl_805A0CE0 = 1;
    return 1;
}
