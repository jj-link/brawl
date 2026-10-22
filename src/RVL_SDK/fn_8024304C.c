#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern void fn_8023E27C(int);
extern void fn_8023D478(int);
extern void fn_8023D6CC(int, int, int, int);
extern void fn_80240728(int, int, int);
extern void fn_802393E4(int, int, int);
extern void fn_80238FB0(int, int, int);
extern void fn_8024D3AC(void);
extern void fn_80240FCC(u8 *, u16, int, int);
extern void fn_8024C500(int, u16, u8 *);
extern u8 fn_8023F234(u16);
extern void fn_8023F130(int, u16, int, int, int, int);
extern void fn_8023EAE0(int, int, u16, void *);
extern void fn_8023B558(u8 *, int, int);

void fn_8024304C(int arg0, int arg1, u8 *arg2) {
    u8 buf[6];
    int sp10[4];
    u16 id;
    switch (arg0) {
    case 0x801: case 0x803: case 0x804: case 0x805: case 0x806:
        fn_8023E27C(arg1);
        return;
    }
    if (arg1 == 0) return;
    switch (arg0) {
    case 0x401:
        fn_8023D478(arg1);
        return;
    case 0x419:
        fn_8023D6CC(0, 0, 0, arg1);
        fn_80240728(0, 0, arg1);
        return;
    case 0xD:
        fn_802393E4(arg1, 0, 0);
        return;
    case 0x80B:
        fn_80238FB0(arg1, 0, 0xFF);
        fn_8024D3AC();
        return;
    case 0x405:
        if (arg2 != 0) {
            buf[5] = arg2[1];
            buf[4] = arg2[2];
            buf[3] = arg2[3];
            buf[2] = arg2[4];
            buf[1] = arg2[5];
            buf[0] = arg2[6];
            fn_80240FCC(buf, 0xFFFF, arg1, 0);
            fn_8024C500(arg1, 0xFFFF, buf);
        }
        return;
    case 0x428:
        if (arg2 != 0) {
            id = arg2[1] + (arg2[2] << 8);
            if (fn_8023F234(id)) {
                fn_8023F130(arg1, id, 0, 0, 0, 0);
                return;
            }
            fn_8023EAE0(arg1, 0, id, sp10);
        }
        return;
    default:
        if ((arg0 & 0xFC00) - 0x10000 + 0x10000 == 0xFC00) {
            fn_8023B558(arg2, arg0, 1);
        }
        return;
    }
}
