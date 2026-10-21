#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State {
    u32 checksum;
    u8 flags;
    u8 type;
    u8 state;
    u8 argument;
    u8 reserved[24];
} State;

extern void fn_801E2FEC(void);
extern void fn_801E28F8(void);
extern void fn_801FB56C(void);
extern void fn_801E32B8(State *);
extern u32 fn_801FB338(void);
extern int fn_801E00A8(int *);
extern void fn_801E01C4(void);
extern void fn_801E31D4(State *);
extern void fn_801E0760(void);
extern void fn_801DF11C(int);
extern void OSEnableScheduler(void);
extern void fn_801D98B8(void);
extern void fn_801EBCE4(void);
extern int lbl_805A0634;
extern int lbl_805A06A4;
extern void fn_801E25C0(void);
extern void fn_801E2750(void);
extern char lbl_804689E0[];
extern char lbl_804689EC[];
extern void fn_801D8690(const char *, int, const char *, ...);

void fn_801DF504(int argument)
{
    State state;
    int value;
    u8 old;
    int next;

    fn_801E2FEC();
    fn_801E28F8();
    fn_801FB56C();
    fn_801E32B8(&state);
    old = state.state;

    if (fn_801FB338() != 2)
        next = 3;
    else if (old != 1 || (fn_801E00A8(&value) && value))
        next = 2;
    else
        next = 1;

    state.state = next;
    state.type = 3;
    state.argument = argument;

    fn_801E01C4();
    fn_801E31D4(&state);
    fn_801E0760();
    fn_801DF11C(5);
    OSEnableScheduler();
    fn_801D98B8();
    fn_801E0760();
    fn_801EBCE4();

    if (lbl_805A0634 || lbl_805A06A4)
        fn_801E25C0();

    fn_801E2750();
    fn_801D8690(lbl_804689E0, 0x3CD, lbl_804689EC);
}
