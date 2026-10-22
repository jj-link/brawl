#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern void fn_802319E4(int, const char *);
extern void fn_802584DC(void *, int, void *);
extern void fn_802588C8(void *, int, int);
extern void fn_80259FF4(void *, u16);
extern char lbl_80484CA8[];
extern u8 lbl_8052D9C0[];

void fn_80258780(u8 *arg0, u8 *arg1) {
    u16 i = *(u16 *)(arg0 + 0x46c);
    u16 n = i + (u16)((arg1[6] << 8) + arg1[7]);
    u8 *p = arg1 + 8;
    int t;
    *(u16 *)(arg0 + 0x46c) = n;
    if (n == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319E4(0xA0001, lbl_80484CA8);
        }
        fn_80259FF4(arg0, 0x10000 - 0x10);
        return;
    }
    if (n > *(u16 *)(lbl_8052D9C0 + 0x462E)) {
        *(u16 *)(arg0 + 0x46c) = *(u16 *)(lbl_8052D9C0 + 0x462E);
    }
    for (; i < *(u16 *)(arg0 + 0x46c); ) {
        u8 *q = p;
        u16 j = i;
        p += 4;
        i++;
        *(int *)(arg0 + ((j * 4) & 0x3FFFC) + 0x418) = ((q[0] << 24) + (q[1] << 16)) + (q[3] + (q[2] << 8));
    }
    t = *p;
    if (t != 0) {
        if (t > 0x10U) {
            fn_80259FF4(arg0, 5);
            return;
        }
        fn_802584DC(arg0, t, p + 1);
        return;
    }
    arg0[0x474] = 2;
    fn_802588C8(arg0, 0, 0);
}
