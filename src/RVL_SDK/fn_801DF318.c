#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct State {
    u32 checksum;
    u8 flags;
    u8 type;
    u8 state;
    u8 argument;
    u8 reserved[24];
} State;

extern void OSEnableScheduler(void);
extern void fn_801D5300(void *);
extern void fn_801D98B8(void);
extern void fn_801DF11C(int);
extern s32 fn_801E00A8(s32 *);
extern void fn_801E01C4(void);
extern void fn_801E0760(void);
extern void fn_801E26D8(void);
extern void fn_801E28F8(void);
extern void fn_801E2FEC(void);
extern void fn_801E31D4(State *);
extern void fn_801E32B8(State *);
extern u32 fn_801FB338(void);
extern void fn_801FB56C(void);
extern void fn_8020E0EC(void);
extern u32 fn_8020E18C(void);
extern void fn_8020FC18(u8 *);
extern void *memset(void *, int, unsigned long);
extern s32 lbl_805A06E4;

void OSShutdownSystem(void) {
    u8 sp8;
    s32 spC;
    u8 sp10[8];
    State sp18;
    u8 old;
    u8 var;

    memset(&sp8, 0, 2);
    fn_8020E0EC();
    do {
    } while (fn_8020E18C() == 1);
    fn_8020FC18(&sp8);
    fn_801E2FEC();
    fn_801E28F8();
    fn_801FB56C();
    fn_801E32B8(&sp18);
    old = sp18.state;
    if (fn_801FB338() != 2) {
        var = 3;
    } else if (old != 1 || (fn_801E00A8(&spC) != 0 && spC != 0)) {
        var = 2;
    } else {
        var = 1;
    }
    sp18.state = var;
    if (sp8 == 1) {
        sp18.type = 5;
    } else {
        sp18.type = 1;
    }
    fn_801E01C4();
    fn_801E31D4(&sp18);
    fn_801D5300(sp10);
    if (sp8 == 1) {
        lbl_805A06E4 = 1;
        fn_801E0760();
        fn_801DF11C(5);
        OSEnableScheduler();
        fn_801D98B8();
        return;
    }
    fn_801E0760();
    fn_801DF11C(2);
    fn_801E26D8();
}
