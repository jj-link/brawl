#pragma force_active on
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 state;
    s32 status;
    s32 handle;
    s32 result;
    unsigned char pad10[8];
    s32 field18;
    unsigned char pad1c[4];
    s32 field20;
    s32 field24;
    unsigned char pad28[0x30];
} State;

extern State lbl_8048E680;
extern char lbl_80415790[];

extern void fn_80335638(s32, const char *, ...);
extern void fn_80335988(s32);
extern void fn_80335C44(s32 *);
extern void fn_8033524C(s32, s32);
extern void fn_80359FF8(s32, s32);
extern s32 fn_8038D5D0(unsigned char *, void *);
extern s32 fn_8037F00C(s32, void *, s32, s32, void *, s32);
extern s32 fn_80335CAC(void *, void *, void (*)(void), s32);
extern void fn_80359828(void);

void fn_803596B8(void)
{
    char sp8[0x80];

    fn_80335638(4, lbl_80415790 + 0x368);
    fn_80335988(0);
    fn_80335C44(&lbl_8048E680.field18);

    if (lbl_8048E680.field18 == 0) {
        fn_80335638(8, lbl_80415790 + 0x377);
        fn_8033524C(9, -0x182B9);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    if (fn_8038D5D0(*(unsigned char **)&lbl_8048E680.handle, sp8) == 0) {
        fn_80359FF8(6, 0xE);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    if (fn_8037F00C(lbl_8048E680.field18, lbl_80415790 + 0x390,
                    lbl_8048E680.field20, lbl_8048E680.field24,
                    lbl_80415790 + 0x390, 0) == 0) {
        fn_80359FF8(6, 2);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    lbl_8048E680.result = fn_80335CAC(sp8, &lbl_8048E680.field18, fn_80359828, 0);
    if (lbl_8048E680.result < 0) {
        fn_80335638(8, lbl_80415790 + 0x398, lbl_8048E680.result);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    lbl_8048E680.state = 2;
}
