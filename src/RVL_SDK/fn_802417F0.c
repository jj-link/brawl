#pragma force_active on
typedef unsigned char u8;
extern u8 lbl_80529CF8[];
extern char lbl_80481C20[];
extern void *fn_8023A0F0(u8 *);
extern void *fn_80239F18(u8 *);
extern void fn_80231A74(int, char *, int, int, int, int, int, int);
extern void fn_80244D34(u8 *, u8 *);
extern void fn_80244ED4(u8 *);
void fn_802417F0(u8 *arg0) {
    u8 key[16];
    u8 *obj = fn_8023A0F0(arg0);
    if (lbl_80529CF8[0x27c0] >= 4U) {
        fn_80231A74(0xD0003, lbl_80481C20, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    if (obj != 0 && (obj[0x76] & 0x10)) {
        fn_80244D34(arg0, obj + 0x25);
        return;
    }
    if (obj == 0) {
        obj = fn_80239F18(arg0);
    }
    if (!(obj[0x81] & 0x40) && *(u8 (**)(u8 *, u8 *))(lbl_80529CF8 + 0x1918) != 0) {
        if (obj != 0) {
            if (!(*(u8 (**)(u8 *, u8 *))(lbl_80529CF8 + 0x1918))(arg0, obj + 0x25)) {
                fn_80244D34(arg0, obj + 0x25);
                return;
            }
        } else {
            if (!(*(u8 (**)(u8 *, u8 *))(lbl_80529CF8 + 0x1918))(arg0, key)) {
                fn_80244D34(arg0, key);
                return;
            }
        }
    }
    fn_80244ED4(arg0);
}