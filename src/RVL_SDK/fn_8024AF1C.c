#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_8052CDC0[];
extern char jumptable_80483008[];
extern void fn_802319FC(int, char *, int);
extern void fn_80231A14(int, char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8022F0E0(void *);
extern void fn_8024FA74(void *);
extern void fn_8024EA24(void *);
extern u8 fn_8023FDEC(void *, u16, u16, u8, void *);
extern void fn_8024C738(void);

void fn_8024AF1C(void *arg0, u16 arg1, void *arg2)
{
    char *a = (char *)arg0;
    char *jt = jumptable_80483008;
    char *r7 = *(char **)(a + 0x30);
    void (*fp1)(u16, int) = *(void (**)(u16, int))(r7 + 0x18);
    void (*fp2)(u16, u16) = *(void (**)(u16, u16))(r7 + 0x8);
    u16 val = *(u16 *)(a + 0x14);
    char *obj;

    if (lbl_8052CDC0[0] >= 4) {
        fn_802319FC(0x80003, jt + 0x24, arg1);
    }

    switch (arg1) {
    case 3:
        if (lbl_8052CDC0[0] >= 3) {
            fn_802319FC(0x80002, jt + 0x40, *(u16 *)(a + 0x14));
        }
        fn_8024FA74(arg0);
        fp1(val, 0);
        break;

    case 0:
        obj = *(char **)(a + 0x10);
        *(int *)(a + 0x4) = 1;
        fn_8023FDEC(obj + 0x2a, *(u16 *)(*(char **)(a + 0x30) + 0x2), *(u16 *)(obj + 0x28), 1, (void *)fn_8024C738);
        break;

    case 1:
        if (lbl_8052CDC0[0] >= 3) {
            fn_80231A14(0x80002, jt + 0x84, *(u16 *)(a + 0x14), ((u8 *)arg2)[6]);
        }
        fn_8024FA74(arg0);
        fp2(val, ((u8 *)arg2)[6]);
        break;

    case 20:
        obj = *(char **)(a + 0x10);
        if (fn_8023FDEC(obj + 0x2a, *(u16 *)(*(char **)(a + 0x30) + 0x2), *(u16 *)(obj + 0x28), 1, (void *)fn_8024C738) == 1) {
            *(int *)(a + 0x4) = 1;
            return;
        }
        break;

    case 7:
        fn_8024EA24(arg0);
        *(int *)(a + 0x4) = 3;
        fn_80231FB0(a + 0x18, 3, 0x3C);
        break;

    case 8:
        if (lbl_8052CDC0[0] >= 3) {
            fn_80231A14(0x80002, jt + 0x84, *(u16 *)(a + 0x14), 0xEEEE);
        }
        fn_8024FA74(arg0);
        fp2(val, 3);
        break;

    case 10:
        obj = *(char **)(a + 0x10);
        *(int *)(a + 0x4) = 2;
        fn_8023FDEC(obj + 0x2a, *(u16 *)(*(char **)(a + 0x30) + 0x2), *(u16 *)(obj + 0x28), 0, (void *)fn_8024C738);
        break;

    case 30:
        if (lbl_8052CDC0[0] >= 3) {
            fn_80231A14(0x80002, jt + 0x84, *(u16 *)(a + 0x14), 0xEEEE);
        }
        fn_8024FA74(arg0);
        fp2(val, 0xEEEE);
        break;

    case 19:
    case 29:
        fn_8022F0E0(arg2);
        break;

    case 26:
        fn_8024FA74(arg0);
        break;

    default:
        break;
    }
}
