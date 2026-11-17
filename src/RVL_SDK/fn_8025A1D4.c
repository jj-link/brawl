#include <types.h>
#pragma force_active on

extern void fn_80231FB0(void *, int, int);
extern void fn_8025A328(int, int, int, void *, void *);
extern void fn_8025A738(int, int, int, void *, void *);
extern void fn_8025AAC8(int, int, int, void *, void *);
extern void fn_8025B344(int, int, int, int);
extern void fn_802319FC(int, const char *, u8);
extern u8 lbl_8052D9C0[];
extern char lbl_80485140[];

void fn_8025A1D4(int arg0, u8 *arg1)
{
    int p;
    u8 *r31;
    u8 *r30;
    u8 type;
    u16 x;
    u16 len;

    p = (int)arg1 + *(u16 *)(arg1 + 4);
    r31 = (u8 *)(p + 8);
    r30 = r31 + *(u16 *)(arg1 + 2);
    fn_80231FB0((void *)(arg0 + 8), 5, 0x1E);

    type = *r31++;
    x = (r31[0] << 8) + r31[1];
    len = (r31[2] << 8) + r31[3];

    if (r31 + len + 4 > r30) {
        fn_8025B344(arg0, x, 4, 0);
        return;
    }

    switch (type) {
    case 2:
        fn_8025A328(arg0, x, len, r31 + 4, r30);
        return;
    case 4:
        fn_8025A738(arg0, x, len, r31 + 4, r30);
        return;
    case 6:
        fn_8025AAC8(arg0, x, len, r31 + 4, r30);
        return;
    default:
        fn_8025B344(arg0, x, 3, 0);
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, lbl_80485140, type);
        }
        return;
    }
}