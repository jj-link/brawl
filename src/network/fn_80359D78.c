#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    s32 state;
    s32 status;
    s32 field8;
    s32 result;
    unsigned char pad10[0x24];
    u32 limit;
    u32 size;
    unsigned char pad3c[8];
    s32 field44;
    unsigned char pad48[0x10];
} State;

extern State lbl_8048E680;
extern char lbl_80415790[];

extern void fn_80335638(s32, const char *, ...);
extern void fn_80359FF8(s32, s32);
extern s32 fn_8038D54C(s32, s32, void *);
extern void fn_80359E78(s32, s32);
extern s32 fn_80335E3C(void *, u32, s32, s32, void (*)(s32, s32), s32);

void fn_80359D78(void)
{
    char buffer[0x80];
    s32 result;

    fn_80335638(4, lbl_80415790 + 0x527);
    if (lbl_8048E680.size > lbl_8048E680.limit) {
        fn_80359FF8(5, 2);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    if (fn_8038D54C(lbl_8048E680.field8, lbl_8048E680.field44, buffer) == 0) {
        fn_80359FF8(5, 14);
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    result = fn_80335E3C(buffer, lbl_8048E680.size + 0x800,
                         1, 0, fn_80359E78, 0);
    lbl_8048E680.result = result;
    if (result < 0) {
        lbl_8048E680.state = 5;
        lbl_8048E680.status = 3;
        return;
    }

    lbl_8048E680.state = 2;
}
