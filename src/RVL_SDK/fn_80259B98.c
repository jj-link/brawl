#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 lbl_8052D9C0[];
extern char lbl_80484DE0[];
extern void fn_802319FC(int, char *, int);
extern void fn_80231A14(int, char *, int, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024AA7C(u16);
extern void fn_8025860C(u8 *);
extern u8 *fn_8025AEE4(int);
extern void fn_8025AFE8(void *);

void fn_80259B98(int arg0, u16 *arg1) {
    char *s = lbl_80484DE0;
    u8 *obj;
    void (*callback)(u16);
    u8 flags;

    if (lbl_8052D9C0[0x4630] >= 4U) {
        fn_80231A14(0xA0003, s + 0x190, arg0, *arg1);
    }
    obj = fn_8025AEE4(arg0);
    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319FC(0xA0001, s + 0x138, arg0);
        }
    } else if (*arg1 == 0) {
        flags = obj[1] | 4;
        obj[1] = flags;
        if (flags & 2) {
            obj[0] = 3;
            if (obj[1] & 1) {
                fn_8025860C(obj);
            } else {
                fn_80231FB0(obj + 8, 5, 0x1E);
            }
        }
    } else {
        if (lbl_8052D9C0[0x4630] >= 4U) {
            fn_802319FC(0xA0003, s + 0x1BC, *(u16 *)(obj + 0x22));
        }
        if (obj[0] != 1U) {
            fn_8024AA7C(*(u16 *)(obj + 0x22));
            *(u16 *)(obj + 0x472) = 0xFFF2;
        } else {
            callback = *(void (**)(u16))(obj + 0x414);
            if (callback != 0) {
                callback(0xFFF2);
            }
            fn_8025AFE8(obj);
        }
    }
}